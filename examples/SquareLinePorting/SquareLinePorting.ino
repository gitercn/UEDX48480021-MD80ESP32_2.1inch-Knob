#include <Arduino.h>
#include <ESP_Panel_Library.h>
#include <lvgl.h>
#include "lvgl_port_v8.h"
#include <ESP_Knob.h>
#include <Button.h>
#include <ui.h>

// 新增全局变量
#define MESSAGE_GEAR_SHIFT "KNOB_GEAR_SHIFT::"
#define MESSAGE_KNOB_VALUE "KNOB_VALUE::"
#define MESSAGE_KNOB_ROTATE "KNOB_ROTATE::"
#define MESSAGE_KNOB_PUSH "KNOB_PUSH::-"
#define MESSAGE_KNOB_PUSH_DOUBLE "KNOB_PUSH_DOUBLE::-"
#define MESSAGE_KNOB_LONG "KNOB_LONG_PRESS::-"

int encoder = 0;
int knob_value = 0;
const char *GEARS = "PRND";
char last_gear[2] = "P";

// LVGL 组件定义
lv_obj_t *label_gear;
lv_obj_t *label_encoder;

#ifdef KNOB21
#define GPIO_NUM_KNOB_PIN_A 6
#define GPIO_NUM_KNOB_PIN_B 5
#define GPIO_BUTTON_PIN GPIO_NUM_0
#endif

ESP_Knob *knob;
Button *btn;

// 更新 LVGL 显示内容
void update_display() {
  // 计算档位
  int idx = encoder / 4;
  idx = idx < 0 ? 0 : idx;
  idx = idx > 3 ? 3 : idx;
  char gear = GEARS[idx];
  char gearStr[2] = { gear, '\0' };

  // 更新档位标签
  lv_label_set_text(label_gear, gearStr);

  // 更新编码器值标签
  char encoder_str[4];
  snprintf(encoder_str, 4, "%d", encoder);
  lv_label_set_text(label_encoder, encoder_str);

  // 串口输出
  if (strcmp(last_gear, gearStr)) {
    strcpy(last_gear, gearStr);
    Serial.printf("%s%s\n", MESSAGE_GEAR_SHIFT, last_gear);
  }
  Serial.printf("%s%d\n", MESSAGE_KNOB_VALUE, knob_value);
}

// 旋钮事件回调
void onKnobLeftEventCallback(int count, void *usr_data) {
  encoder--;
  knob_value--;
  encoder = encoder < 0 ? 0 : encoder;
  Serial.printf("%s-\n", MESSAGE_KNOB_ROTATE);

  lvgl_port_lock(-1);
  update_display();
  lvgl_port_unlock();
}

void onKnobRightEventCallback(int count, void *usr_data) {
  encoder++;
  knob_value++;
  encoder = encoder > 19 ? 19 : encoder;
  Serial.printf("%s+\n", MESSAGE_KNOB_ROTATE);

  lvgl_port_lock(-1);
  update_display();
  lvgl_port_unlock();
}

// 按钮事件回调
static void SingleClickCb(void *button_handle, void *usr_data) {
  Serial.println(MESSAGE_KNOB_PUSH);
  lvgl_port_lock(-1);

  lvgl_port_unlock();
}

static void DoubleClickCb(void *button_handle, void *usr_data) {
  Serial.println(MESSAGE_KNOB_PUSH_DOUBLE);
  lvgl_port_lock(-1);

  lvgl_port_unlock();
}


static void LongPressStartCb(void *button_handle, void *usr_data) {
  Serial.println(MESSAGE_KNOB_LONG);
  lvgl_port_lock(-1);
  // 此处可添加按钮长按的 UI 操作
  lvgl_port_unlock();
}

void setup() {
  Serial.begin(115200);
  Serial.println("LVGL Gear Shift Demo");

  // 初始化硬件
  ESP_Panel *panel = new ESP_Panel();
  panel->init();
  panel->begin();

  // 初始化旋钮
  knob = new ESP_Knob(GPIO_NUM_KNOB_PIN_A, GPIO_NUM_KNOB_PIN_B);
  knob->begin();
  knob->attachLeftEventCallback(onKnobLeftEventCallback);
  knob->attachRightEventCallback(onKnobRightEventCallback);

  // 初始化按钮
  btn = new Button(GPIO_BUTTON_PIN, false);
  btn->attachSingleClickEventCb(&SingleClickCb, NULL);
  btn->attachDoubleClickEventCb(&DoubleClickCb, NULL);
  btn->attachLongPressStartEventCb(&LongPressStartCb, NULL);

  // 初始化 LVGL
  lvgl_port_init(panel->getLcd(), panel->getTouch());

  // 创建 UI 组件
  lvgl_port_lock(-1);
  lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0xC0C0C0), LV_PART_MAIN);

  // 档位标签（大字体居中）
  label_gear = lv_label_create(lv_scr_act());
  lv_obj_set_style_text_font(label_gear, &lv_font_montserrat_40, LV_PART_MAIN);
  lv_label_set_text(label_gear, "P");
  lv_obj_align(label_gear, LV_ALIGN_CENTER, -10, -50);
  lv_obj_set_style_transform_zoom(label_gear, 500, LV_PART_MAIN);


  // 编码器值标签（底部显示）
  label_encoder = lv_label_create(lv_scr_act());
  lv_obj_set_style_text_font(label_encoder, &lv_font_montserrat_20, LV_PART_MAIN);
  lv_label_set_text(label_encoder, "0");
  lv_obj_align(label_encoder, LV_ALIGN_BOTTOM_MID, 0, -20);

  lvgl_port_unlock();
}

void loop() {
  delay(10);
}
