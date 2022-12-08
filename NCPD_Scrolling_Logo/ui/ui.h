// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

void scroll_ncpd_Animation(lv_obj_t * TargetObject, int delay);
void scroll_police_Animation(lv_obj_t * TargetObject, int delay);
extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_ncpdText;
extern lv_obj_t * ui_policeText;
extern lv_obj_t * ui_Mask;
void ui_event_launch(lv_event_t * e);


LV_IMG_DECLARE(ui_img_ncpd_text_png);    // assets\NCPD_text.png
LV_IMG_DECLARE(ui_img_police_text_png);    // assets\POLICE_text.png
LV_IMG_DECLARE(ui_img_ncpd_logo_background_320172_png);    // assets\NCPD_logo_background_320172.png




void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
