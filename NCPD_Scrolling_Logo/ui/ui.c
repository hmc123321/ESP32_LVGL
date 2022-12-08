// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void scroll_ncpd_Animation(lv_obj_t * TargetObject, int delay);
void scroll_police_Animation(lv_obj_t * TargetObject, int delay);
lv_obj_t * ui_Screen1;
lv_obj_t * ui_ncpdText;
lv_obj_t * ui_policeText;
lv_obj_t * ui_Mask;
void ui_event_launch(lv_event_t * e);
lv_obj_t * ui_launch;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void scroll_ncpd_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 5000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, 0, -832);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_0);

}
void scroll_police_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 5000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, 0, -832);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 1800);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_0);

}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ncpdText = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_ncpdText, &ui_img_ncpd_text_png);
    lv_obj_set_width(ui_ncpdText, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ncpdText, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ncpdText, 303);
    lv_obj_set_y(ui_ncpdText, 0);
    lv_obj_set_align(ui_ncpdText, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ncpdText, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ncpdText, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_scrollbar_mode(ui_ncpdText, LV_SCROLLBAR_MODE_OFF);

    ui_policeText = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_policeText, &ui_img_police_text_png);
    lv_obj_set_width(ui_policeText, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_policeText, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_policeText, 416);
    lv_obj_set_y(ui_policeText, 0);
    lv_obj_set_align(ui_policeText, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_policeText, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_policeText, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Mask = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_Mask, &ui_img_ncpd_logo_background_320172_png);
    lv_obj_set_width(ui_Mask, 320);
    lv_obj_set_height(ui_Mask, 172);
    lv_obj_set_align(ui_Mask, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Mask, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Mask, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

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
