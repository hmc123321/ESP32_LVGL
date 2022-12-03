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

void test1_Animation(lv_obj_t * TargetObject, int delay);
extern lv_obj_t * ui_Screen1;
void ui_event_Screen1_ImgButton3(lv_event_t * e);
extern lv_obj_t * ui_Screen1_ImgButton3;
extern lv_obj_t * ui_Screen1_Label1;


LV_IMG_DECLARE(ui_img_lvgl_btn1_png);    // assets\lvgl_btn1.png
LV_IMG_DECLARE(ui_img_lvgl_btn2_png);    // assets\lvgl_btn2.png


LV_FONT_DECLARE(ui_font_Font2);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
