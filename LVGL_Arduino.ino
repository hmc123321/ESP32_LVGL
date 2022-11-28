#include <lvgl.h>
#include <TFT_eSPI.h>
#include <demos/lv_demos.h>
#include <examples/lv_examples.h>

/*micro defines*/
#define BTN_1 15
#define BTN_2 13 
#define BTN_3 26

#define PRESSED_OK 2
#define PRESSED_NEXT 1
#define PRESSED_PREV -1
#define PRESSED_NONE 0
/*declare functions*/
void encoder_callback(lv_indev_drv_t * drv, lv_indev_data_t*data);
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p );
void my_button_regist();
void my_disp_drv_init();
void button_init();
int16_t button_process();

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 172;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * 10 ];

lv_group_t * my_group;//绑定控件与按键的组

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

void setup()
{
    lv_init();
    tft.begin();          /* TFT init */
    tft.setRotation( 1 ); /* Landscape orientation, flipped */
    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );

    /*Initialize the drivers*/
    my_disp_drv_init();
    my_button_regist();
//以下写你自己的控件代码  
    lv_obj_t * btn1 = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btn1,60,30);
    lv_obj_align(btn1,LV_ALIGN_CENTER,0,-60);
    lv_obj_t * btn1_label = lv_label_create(btn1);
    lv_label_set_text(btn1_label,"BTN 1");

     lv_obj_t * btn2 = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btn2,60,30);
    lv_obj_align(btn2,LV_ALIGN_CENTER,0,-20);
    lv_obj_t * btn2_label = lv_label_create(btn2);
    lv_label_set_text(btn2_label,"BTN 2");

     lv_obj_t * btn3 = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btn3,60,30);
    lv_obj_align(btn3,LV_ALIGN_CENTER,0,20);
    lv_obj_t * btn3_label = lv_label_create(btn3);
    lv_label_set_text(btn3_label,"BTN 3");

    lv_obj_t * slider1 = lv_slider_create(lv_scr_act());
    lv_slider_set_range(slider1,0,20);
    lv_obj_set_size(slider1,100,20);
    lv_obj_align(slider1,LV_ALIGN_CENTER,0,60);

    lv_group_add_obj(my_group,btn1);
    lv_group_add_obj(my_group,btn2);
    lv_group_add_obj(my_group,btn3);
    lv_group_add_obj(my_group,slider1);
}

void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    delay( 5 );
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
void button_init()
{
  pinMode(BTN_1,INPUT_PULLUP);
  pinMode(BTN_2,INPUT_PULLUP);
  pinMode(BTN_3,INPUT_PULLUP);
}

void my_button_regist()
{
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);      /*Basic initialization*/
  indev_drv.type = LV_INDEV_TYPE_ENCODER;
  indev_drv.read_cb = encoder_callback;
  indev_drv.long_press_repeat_time = 500;
  /*Register the driver in LVGL and save the created input device object*/
  lv_indev_t * my_indev = lv_indev_drv_register(&indev_drv);

  my_group = lv_group_create();
  // lv_group_add_obj(my_group);
  lv_indev_set_group(my_indev,my_group);
}

void encoder_callback(lv_indev_drv_t * drv, lv_indev_data_t*data){
  int16_t temp = button_process();
  if (temp == PRESSED_OK)
  {
    data->state = LV_INDEV_STATE_PR;
  }
  else {
    data->state = LV_INDEV_STATE_REL;
    data->enc_diff = temp;
  }
}

int16_t button_process()
{
  int16_t key_pressing_cnt_1 = 0,key_pressing_cnt_2 = 0,key_pressing_cnt_3 = 0;
  int16_t temp;
  //temp【 -1：按下了“+”；+1：按下了“-”；2：按下了“OK"；0：两个及以上一起按无效】
  for (int i=0;i<12;i++)//12个采样窗口
  {
    if(digitalRead(BTN_1)==0)
    {
      key_pressing_cnt_1++;
    }
    else 
    {
      key_pressing_cnt_1--;
    }
    if(digitalRead(BTN_2)==0)
    {
      key_pressing_cnt_2++;
    }
    else 
    {
      key_pressing_cnt_2--;
    }
    if(digitalRead(BTN_3)==0)
    {
      key_pressing_cnt_3++;
    }
    else 
    {
      key_pressing_cnt_3--;
    }
    delay(1);
  }

  if (((key_pressing_cnt_1 >=8)|(key_pressing_cnt_2 >=8)|(key_pressing_cnt_3 >=8)) >= 2)//同时按下两个及以上
  {
    temp = PRESSED_NONE;
  }
  else if(key_pressing_cnt_1 >=8)
  {
    temp = PRESSED_NEXT;
  }
  else if(key_pressing_cnt_2 >=8)
  {
    temp = PRESSED_OK;
  }
  else if(key_pressing_cnt_3 >=8)
  {
    temp = PRESSED_PREV;
  }
  return temp;
}