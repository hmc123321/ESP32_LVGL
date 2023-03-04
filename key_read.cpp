#include "key_read.h"

Key_State buttonLastRead[BTN_NUM] = {KEY_RELEASE, KEY_RELEASE, KEY_RELEASE};//保存前一刻按键状态
Key_State buttonState[BTN_NUM]; // 局部按键状态
Key_State keyState[BTN_NUM];

uint16_t Button_Pins[BTN_NUM] = {26,13,15};
// uint16_t Button_Pins[BTN_NUM] = {18,19,47};

Key_State mg_keyState[BTN_NUM];
Key_State mg_lastKeyState[BTN_NUM];

//按钮事件
int16_t KeyEvent[3][BTN_NUM]=
{
  { 1,  LV_INDEV_STATE_PR ,-1},//按下的状态
  { 0,  LV_INDEV_STATE_REL, 0},//松开的状态
  { 0,  0                 , 0},//长按的计数
};

static uint32_t buttonTimer[BTN_NUM] = {0, 0, 0}; // 按键计数器
TimerHandle_t Key_Timer;//按键扫描软件定时器句柄
SemaphoreHandle_t buttonStateSemaphore; // 按键状态信号量

void button_init()
{
  memset(mg_keyState, KEY_RELEASE, BTN_NUM);
  memset(mg_lastKeyState, KEY_RELEASE, BTN_NUM);

  for(int i = 0; i<BTN_NUM ;i++)
  {
    keyState[i] = KEY_RELEASE;
  }
  // 初始化按键引脚
  for (int i = 0; i < BTN_NUM; i++) 
  {
    pinMode(Button_Pins[i], INPUT_PULLUP);
  }

  // 创建按键状态信号量
  buttonStateSemaphore = xSemaphoreCreateMutex();
  xSemaphoreGive(buttonStateSemaphore);

  //Timer tasks init 
  Key_Timer = xTimerCreate(
    "Key_Timer_Task",//描述该任务
    KEY_PERIOD,      //周期，单位是时钟tick，使用pdMS_TO_TICKS()转换毫秒到tick
    pdTRUE,          //是否重装载
    0,               //定时器ID
    Key_TimerTask    //该定时器执行的函数
  );

  //start timer task
  xTimerStart(Key_Timer,0);
}

void Key_TimerTask(TimerHandle_t xTimer)
{
  for (int i = 0; i < BTN_NUM; i++) 
  {
    Key_State currentState = Key_State(digitalRead(Button_Pins[i]));//每10ms读取一次按键
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
  for(int i = 0; i<BTN_NUM ;i++)
  {
    keyState[i] = buttonState[i];
  }
  xSemaphoreGive(buttonStateSemaphore); 
}

void encoder_callback(lv_indev_drv_t * drv, lv_indev_data_t*data)
{
  // data->state = LV_INDEV_STATE_PR;  //编码器按键按下
  // data->state = LV_INDEV_STATE_REL; //编码器按键释放
  // data->enc_diff = 0;               //编码器滚动了多少格

  // 读取按键状态数组
  xSemaphoreTake(buttonStateSemaphore, portMAX_DELAY);
  for(int i = 0; i<BTN_NUM ;i++)
  {
    mg_keyState[i] = keyState[i];
  }
  xSemaphoreGive(buttonStateSemaphore);
   
  data->state = ((mg_keyState[BTN_2] == KEY_RELEASE) ? lv_indev_state_t(KeyEvent[RELEASE_EVENT][BTN_2]): lv_indev_state_t(KeyEvent[PRESSING_EVENT][BTN_2]));//确定按钮,可长按
  
  //方向按钮，长按与短按触发不一样
  for(int i = 0; i < BTN_NUM; i++)
  {
    if(i == BTN_2)//跳过确定键
    {
      continue;
    }
    if ((mg_lastKeyState[i] != mg_keyState[i]) && (mg_keyState[i] == KEY_SHORT_PRESSING) )
    {
      data->enc_diff = KeyEvent[PRESSING_EVENT][i];
      break;
    }
    else if (mg_keyState[i] == KEY_LONG_PRESSING)
    {
      KeyEvent[LONG_PR_CNT][i] ++;
      data->enc_diff = KeyEvent[PRESSING_EVENT][i] * ((KeyEvent[LONG_PR_CNT][i] % 5) == 0);
      break;
    }
    else
    {
      data->enc_diff = KeyEvent[RELEASE_EVENT][i];
    }
  }
  for(int i = 0; i < BTN_NUM; i++)
  {
    mg_lastKeyState[i] = mg_keyState[i];
  }
}
