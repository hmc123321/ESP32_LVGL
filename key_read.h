#ifndef __KEY_READ_H__
#define __KEY_READ_H_

#include <Arduino.h>
#include <lvgl.h>

#define KEY_PERIOD pdMS_TO_TICKS(10)  //按键扫描周期
#define COUNT_UNIT 0.1

#define LONG_PRESS_TIME (1500 * COUNT_UNIT) // 长按时间阈值，单位为 tick
#define DEBOUNCE_TIME (10 * COUNT_UNIT)

#define PRESSING_EVENT  0
#define RELEASE_EVENT   1
typedef enum 
{
  BTN_1 = 0,
  BTN_2,
  BTN_3,
  BTN_NUM,
} Key_Num;

typedef enum 
{
  KEY_SHORT_PRESSING = 0,
  KEY_RELEASE,
  KEY_LONG_PRESSING
} Key_State;

void Key_TimerTask(TimerHandle_t xTimer);
void button_init();
void encoder_callback(lv_indev_drv_t * drv, lv_indev_data_t*data);

extern Key_State keyState[BTN_NUM];
extern SemaphoreHandle_t buttonStateSemaphore; // 按键状态信号量
#endif