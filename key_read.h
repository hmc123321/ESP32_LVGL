#ifndef __KEY_READ_H__
#define __KEY_READ_H_

#include <Arduino.h>
#include <FreeRTOS.h>
#include <semphr.h>

#define KEY_PERIOD pdMS_TO_TICKS(10)  //按键扫描周期
#define COUNT_UNIT 0.1

#define LONG_PRESS_TIME (1500 * COUNT_UNIT) // 长按时间阈值，单位为 tick
#define DEBOUNCE_TIME (10 * COUNT_UNIT)

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

#ifdef MY_ESP32
uint16_t keyPins[BTN_NUM] = {26,13,15};
#else
uint16_t keyPins[BTN_NUM] = {18,19,47};
#endif

void Key_TimerTask(TimerHandle_t xTimer);
void button_init();

#endif