#include <lvgl.h>
#include <TFT_eSPI.h>
#include <demos/lv_demos.h>
#include <examples/lv_examples.h>

/*micro defines*/
#define BTN_1 15
#define BTN_2 13 
#define BTN_3 26
/*declare functions*/
bool button_read(lv_indev_drv_t * drv, lv_indev_data_t*data);
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p );
void button_init();
void my_button_regist();
void my_disp_drv_init();

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
    // lv_example_btn_1();
    lv_demo_benchmark(LV_DEMO_BENCHMARK_MODE_RENDER_AND_DRIVER);          // OK
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
  indev_drv.read_cb = button_read;
  indev_drv.long_press_repeat_time = 500;
  /*Register the driver in LVGL and save the created input device object*/
  lv_indev_t * my_indev = lv_indev_drv_register(&indev_drv);

  my_group = lv_group_create();
  // lv_group_add_obj(my_group);
  lv_indev_set_group(my_indev,my_group);
}

bool button_read(lv_indev_drv_t * drv, lv_indev_data_t*data){
  data->key = last_key();            /*Get the last pressed or released key*/
                                     /* use LV_KEY_ENTER for encoder press */
  if(key_pressed()) data->state = LV_INDEV_STATE_PR;
  else {
      data->state = LV_INDEV_STATE_REL;
      /* Optionally you can also use enc_diff, if you have encoder*/
      data->enc_diff = enc_get_new_moves();
  }

  return false; /*No buffering now so no more data read*/
}