// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void test1_Animation(lv_obj_t * TargetObject, int delay);
lv_obj_t * ui_Screen1;
void ui_event_Screen1_ImgButton3(lv_event_t * e);
lv_obj_t * ui_Screen1_ImgButton3;
lv_obj_t * ui_Screen1_Label1;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void test1_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, 0, 160);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 500);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_1, 0, 40);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_1);
    lv_anim_t PropertyAnimation_2;
    lv_anim_init(&PropertyAnimation_2);
    lv_anim_set_time(&PropertyAnimation_2, 500);
    lv_anim_set_user_data(&PropertyAnimation_2, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_2, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_2, 0, -40);
    lv_anim_set_path_cb(&PropertyAnimation_2, lv_anim_path_ease_in);
    lv_anim_set_delay(&PropertyAnimation_2, delay + 500);
    lv_anim_set_playback_time(&PropertyAnimation_2, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_2, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_2, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_2, 0);
    lv_anim_set_early_apply(&PropertyAnimation_2, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_2, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_2);
    lv_anim_t PropertyAnimation_3;
    lv_anim_init(&PropertyAnimation_3);
    lv_anim_set_time(&PropertyAnimation_3, 1000);
    lv_anim_set_user_data(&PropertyAnimation_3, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_3, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_3, 0, -160);
    lv_anim_set_path_cb(&PropertyAnimation_3, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_3, delay + 1000);
    lv_anim_set_playback_time(&PropertyAnimation_3, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_3, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_3, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_3, 0);
    lv_anim_set_early_apply(&PropertyAnimation_3, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_3, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_3);
    lv_anim_t PropertyAnimation_4;
    lv_anim_init(&PropertyAnimation_4);
    lv_anim_set_time(&PropertyAnimation_4, 500);
    lv_anim_set_user_data(&PropertyAnimation_4, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_4, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_4, 0, -40);
    lv_anim_set_path_cb(&PropertyAnimation_4, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_4, delay + 1000);
    lv_anim_set_playback_time(&PropertyAnimation_4, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_4, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_4, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_4, 0);
    lv_anim_set_early_apply(&PropertyAnimation_4, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_4, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_4);
    lv_anim_t PropertyAnimation_5;
    lv_anim_init(&PropertyAnimation_5);
    lv_anim_set_time(&PropertyAnimation_5, 500);
    lv_anim_set_user_data(&PropertyAnimation_5, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_5, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_5, 0, 40);
    lv_anim_set_path_cb(&PropertyAnimation_5, lv_anim_path_ease_in);
    lv_anim_set_delay(&PropertyAnimation_5, delay + 1500);
    lv_anim_set_playback_time(&PropertyAnimation_5, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_5, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_5, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_5, 0);
    lv_anim_set_early_apply(&PropertyAnimation_5, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_5, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_5);

}

///////////////////// FUNCTIONS ////////////////////
void ui_event_Screen1_ImgButton3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        test1_Animation(ui_Screen1_ImgButton3, 20);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_ImgButton3 = lv_imgbtn_create(ui_Screen1);
    lv_imgbtn_set_src(ui_Screen1_ImgButton3, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_lvgl_btn1_png, NULL);
    lv_imgbtn_set_src(ui_Screen1_ImgButton3, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_lvgl_btn2_png, NULL);
    lv_obj_set_width(ui_Screen1_ImgButton3, 86);
    lv_obj_set_height(ui_Screen1_ImgButton3, 31);
    lv_obj_set_x(ui_Screen1_ImgButton3, -80);
    lv_obj_set_y(ui_Screen1_ImgButton3, 0);
    lv_obj_set_align(ui_Screen1_ImgButton3, LV_ALIGN_CENTER);

    ui_Screen1_Label1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Label1, 320);
    lv_obj_set_height(ui_Screen1_Label1, 172);
    lv_obj_set_align(ui_Screen1_Label1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_Screen1_Label1, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_Screen1_Label1, "NIGHT CITY POLICE DEPARTMENT    ");
    lv_obj_set_style_text_color(ui_Screen1_Label1, lv_color_hex(0x56E2E3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label1, &ui_font_Font2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Screen1_ImgButton3, ui_event_Screen1_ImgButton3, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
}
