#include <lvgl.h>
#include <TFT_eSPI.h>
#include "ui.h"
#include "key_read.h"

/*micro defines*/
#define REFRESH_PERIOD 5  //屏幕刷新周期

/*declare functions*/
void encoder_callback(lv_indev_drv_t * drv, lv_indev_data_t*data);
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p );
void my_button_regist();
void my_disp_drv_init();

/*显示屏分辨率预设*/
static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 172;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * 10 ];

//用户变量
TickType_t xLastWakeTime; //用于主循环中每5ms一次的延迟的时间戳
lv_group_t * my_group;//绑定控件与按键的组
TaskHandle_t myTaskHandle;

//实例化
TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

void setup()
{
  Serial.begin(115200);
 
  //lvgl screen init
  lv_init();
  tft.begin();          /* TFT init */
  tft.setRotation( 1 ); /* Landscape orientation, flipped */
  lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );

  /*Initialize the drivers*/
  my_disp_drv_init();
  my_button_regist();
  //以下写你自己的控件代码  
  ui_init();
  lv_group_add_obj(my_group,ui_Screen1_ImgButton3);
  xTaskCreatePinnedToCore(myTask, "myTask", 2048, NULL, 1, &myTaskHandle, 0);
  xLastWakeTime = xTaskGetTickCount();
}

//主要逻辑写在这个函数里，在与loop并行的Core 0运行，loop优先级最高，只用来刷屏幕。
void myTask(void *pvParameters) {
  Key_State keyStateMonitor[BTN_NUM];
  while (1) {
    // 在这里编写任务的具体逻辑
    // 读取按键状态数组
    // xSemaphoreTake(buttonStateSemaphore, portMAX_DELAY);
    // for(int i = 0; i<BTN_NUM ;i++)
    // {
    //   keyStateMonitor[i] = keyState[i];
    // }
    // xSemaphoreGive(buttonStateSemaphore);
    
    // Serial.print(keyStateMonitor[BTN_1]);
    // Serial.print(",");
    // Serial.print(keyStateMonitor[BTN_2]);
    // Serial.print(",");
    // Serial.println(keyStateMonitor[BTN_3]);
    // 暂停任务 100ms，以避免过多占用 CPU 资源
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    vTaskDelayUntil(&xLastWakeTime,REFRESH_PERIOD);
}

/********************************display device init***********************/
/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp );
}

void my_disp_drv_init()
{
    static lv_disp_drv_t disp_drv;
    
    button_init();
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );
}
/********************************Input device init***********************/
void my_button_regist()
{
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);      /*Basic initialization*/
  indev_drv.type = LV_INDEV_TYPE_ENCODER;
  indev_drv.read_cb = encoder_callback;
  // indev_drv.long_press_repeat_time = 5000;
  /*Register the driver in LVGL and save the created input device object*/
  lv_indev_t * my_indev = lv_indev_drv_register(&indev_drv);

  my_group = lv_group_create();
  lv_indev_set_group(my_indev,my_group);
}

