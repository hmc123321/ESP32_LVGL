#include "key_read.h"

volatile Key_State keyState[BTN_NUM] = {KEY_RELEASE, KEY_RELEASE, KEY_RELEASE}; // 全局按键状态
volatile Key_State buttonState[BTN_NUM] = {KEY_RELEASE, KEY_RELEASE, KEY_RELEASE}; // 局部按键状态
volatile Key_State buttonLastRead[BTN_NUM] = {KEY_RELEASE, KEY_RELEASE, KEY_RELEASE};//保存前一刻按键状态
SemaphoreHandle_t buttonStateSemaphore; // 按键状态信号量

static uint32_t buttonTimer[BTN_NUM] = {0, 0, 0}; // 按键计数器
//static bool longPressState[BTN_NUM] = {false, false, false}; // 长按状态

/**
 * 默认状态是1，按下是0.
 * 若按键从1变为0，更新currentState为0，即按下；或者从0变1，更新currentState为1，即放开.
 * 若是按下状态，则开始计时
 */
/*
// 按键任务
void buttonTask(void *pvParameters) {
  for (;;) {
    // 检测按键状态
    for (int i = 0; i < BTN_NUM; i++) {
      bool currentState = digitalRead(keyPins[i]);

      if (currentState != buttonState[i]) {//若按键状态变化，且变成按下，就开始长按计时
        buttonState[i] = currentState;
        if (currentState == LOW) { // 按键按下
          buttonTimer[i] = xTaskGetTickCount(); // 记录按键按下的时间
        }
      }
    }

    // 判断是否长按
    for (int i = 0; i < BTN_NUM; i++) {
      if (buttonState[i] == LOW) {
        uint32_t duration = xTaskGetTickCount() - buttonTimer[i];
        if ((duration > LONG_PRESS_TIME) && (!longPressState[i])) {//若在一定的时间内
          longPressState[i] = true;
          buttonState[i] = LONG_PRESS;
        }
      }
    }

    // 清除长按状态和计时器
    for (int i = 0; i < BTN_NUM; i++) {
      if (buttonState[i] == HIGH) {
        buttonTimer[i] = 0;
        longPressState[i] = false;
      }
    }

    // 更新按键状态到数组
    xSemaphoreTake(buttonStateSemaphore, portMAX_DELAY);
    for (int i = 0; i < BTN_NUM; i++) {
      switch (buttonState[i]) {
        case HIGH:
          keyState[i] = 0; // 高电平为短按
          break;
        case LOW:
          keyState[i] = 1; // 低电平为按下
          break;
        case LONG_PRESS:
          keyState[i] = 2; // 长按
          break;
      }
    }
    xSemaphoreGive(buttonStateSemaphore);

    vTaskDelay(pdMS_TO_TICKS(20)); // 延时 20 毫秒
  }
}
*/

void button_init()
{
  memset(buttonDebounceTimer,0,BTN_NUM);
  // 初始化按键引脚
  for (int i = 0; i < BTN_NUM; i++) {
    pinMode(keyPins[i], INPUT_PULLUP);
  }

  // 创建按键状态信号量
  buttonStateSemaphore = xSemaphoreCreateMutex();
  xSemaphoreGive(buttonStateSemaphore);

  // 创建按键任务
  xTaskCreate(buttonTask, "buttonTask", 2048, NULL, 1, NULL);
  // 其他初始化操作
}

void loop() {
// 读取按键状态数组
  xSemaphoreTake(buttonStateSemaphore, portMAX_DELAY);
  for (int i = 0; i < BTN_NUM; i++) {
  Serial.print(keyState[i]);
  Serial.print('\t');
  }
  Serial.println();
  xSemaphoreGive(buttonStateSemaphore);

  // 其他操作
  delay(100);
}


void Key_TimerTask(TimerHandle_t xTimer)
{
  for (int i = 0; i < BTN_NUM; i++) 
  {
    bool currentState = digitalRead(keyPins[i]);//每10ms读取一次按键
    if (currentState == buttonLastRead[i])//若状态保持住，则计数
    {
      buttonTimer[i] ++;
    }
    else //按下或者松开的瞬间清除计数
    {
      buttonTimer[i] = 0;
    }

    if(buttonTimer[i] >= LONG_PRESS_TIME)
    {
      buttonTimer[i] =  LONG_PRESS_TIME;//若计数超限，不再增加，直到切换状态
      if(currentState == KEY_SHORT_PRESSING)//若超限时是按下的，更改按键状态
      {
        buttonState[i] = KEY_LONG_PRESSING;  
      } 
    }
    else if (buttonTimer[i] > DEBOUNCE_TIME)//否则按住超过20ms，视为短按
    {
      buttonState[i] = currentState;
    }
    else 
    {
    }
    buttonLastRead[i] = currentState;
  }
  xSemaphoreTake(buttonStateSemaphore, portMAX_DELAY);
  memcpy(keyState,buttonState,BTN_NUM)
  xSemaphoreGive(buttonStateSemaphore);
  
}