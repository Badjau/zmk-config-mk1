#include "layer.h"
#include "../assets/custom_fonts.h"
#include <zephyr/kernel.h>

void draw_layer_status(lv_obj_t *canvas, const struct status_state *state) {
  lv_draw_label_dsc_t label_dsc;
  // init_label_dsc(&label_dsc, LVGL_FOREGROUND, &pixel_operator_mono,
  // LV_TEXT_ALIGN_CENTER);
  init_label_dsc(&label_dsc, LVGL_FOREGROUND, &pixel_operator_mono,
                 LV_TEXT_ALIGN_LEFT);

  char text[10] = {};

  if (state->layer_label == NULL) {
    sprintf(text, "Layer %i", state->layer_index);
  } else {
    strcpy(text, state->layer_label);
    to_uppercase(text);
  }

  lv_canvas_draw_text(canvas, 0, 146, 68, &label_dsc, text);
}
