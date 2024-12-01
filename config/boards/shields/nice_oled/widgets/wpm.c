#include "wpm.h"
#include "../assets/custom_fonts.h"
#include <math.h>
#include <zephyr/kernel.h>

LV_IMG_DECLARE(gauge);
LV_IMG_DECLARE(grid);

// bongo_cat.c
LV_IMG_DECLARE(bongo_cat_none);
LV_IMG_DECLARE(bongo_cat_left1);
LV_IMG_DECLARE(bongo_cat_left2);
LV_IMG_DECLARE(bongo_cat_right1);
LV_IMG_DECLARE(bongo_cat_right2);
LV_IMG_DECLARE(bongo_cat_both1);
LV_IMG_DECLARE(bongo_cat_both1_open);
LV_IMG_DECLARE(bongo_cat_both2);

static void draw_gauge(lv_obj_t *canvas, const struct status_state *state) {
  lv_draw_img_dsc_t img_dsc;
  lv_draw_img_dsc_init(&img_dsc);

  lv_canvas_draw_img(canvas, 0, 70, &gauge, &img_dsc);
  // lv_canvas_draw_img(canvas, 16, 43, &gauge, &img_dsc);
}

static void draw_needle(lv_obj_t *canvas, const struct status_state *state) {
  lv_draw_line_dsc_t line_dsc;
  init_line_dsc(&line_dsc, LVGL_FOREGROUND, 1);

  int centerX = 12; // 16 default
  int centerY = 90; // 100 gut, 66 default
  int offset = 5;   // 5 def, largo de la aguja
  int value = state->wpm[9];

#if IS_ENABLED(CONFIG_NICE_OLED_GEM_ANIMATION_WPM_FIXED_RANGE)
  float max = CONFIG_NICE_OLED_GEM_ANIMATION_WPM_FIXED_RANGE_MAX;
#else
  float max = 0;
  for (int i = 0; i < 10; i++) {
    if (state->wpm[i] > max) {
      max = state->wpm[i];
    }
  }
#endif
  if (max == 0)
    max = 100;
  if (value < 0)
    value = 0;
  if (value > max)
    value = max;

  float radius = 25.45585;
  float angleDeg = 225 + ((float)value / max) * 90;
  float angleRad = angleDeg * (3.14159 / 180.0f);

  /* int needleStartX = 33 + (int)(13 * cos(4.71239)); // 33 + (int)(13 * 0) =
  33
  * int needleStartY = 66 + (int)(13 * sin(4.71239)); // 66 + (int)(13 * -1) =
  53
  * int needleEndX = 33 + (int)(25.45585 * cos(4.71239)); // 33 +
  (int)(25.45585 * 0) = 33
  * int needleEndY = 66 + (int)(25.45585 * sin(4.71239)); 66 + (int)(25.45585 *
  -1) = 40 */
  int needleStartX = centerX + (int)(offset * cos(angleRad));
  int needleStartY = centerY + (int)(offset * sin(angleRad));
  int needleEndX = centerX + (int)(radius * cos(angleRad));
  int needleEndY = centerY + (int)(radius * sin(angleRad));

  lv_point_t points[2] = {{needleStartX, needleStartY},
                          {needleEndX, needleEndY}};
  // canvas, points, number of points, line_dsc
  lv_canvas_draw_line(canvas, points, 2, &line_dsc);
  // lv_canvas_draw_line(canvas, points, 2, &line_dsc);
}

static void draw_grid(lv_obj_t *canvas) {
  lv_draw_img_dsc_t img_dsc;
  lv_draw_img_dsc_init(&img_dsc);

  lv_canvas_draw_img(canvas, -1, 95, &grid, &img_dsc);
  // lv_canvas_draw_img(canvas, -1, 100, &grid, &img_dsc);
}

static void draw_graph(lv_obj_t *canvas, const struct status_state *state) {
  lv_draw_line_dsc_t line_dsc;
  init_line_dsc(&line_dsc, LVGL_FOREGROUND, 2);
  lv_point_t points[10];

#if IS_ENABLED(CONFIG_NICE_OLED_GEM_ANIMATION_WPM_FIXED_RANGE)
  int max = CONFIG_NICE_OLED_GEM_ANIMATION_WPM_FIXED_RANGE_MAX;
  if (max == 0) {
    max = 100;
  }

  int value = 0;
  for (int i = 0; i < 10; i++) {
    value = state->wpm[i];
    if (value > max) {
      value = max;
    }
    // modificar aqui par la posicion de la grafica
    points[i].x = -36 + i * 7.4;
    points[i].y = 127 - (value * 32 / max);
    // points[i].y = 132 - (value * 32 / max);
  }
#else
  int max = 0;
  int min = 256;

  for (int i = 0; i < 10; i++) {
    if (state->wpm[i] > max) {
      max = state->wpm[i];
    }
    if (state->wpm[i] < min) {
      min = state->wpm[i];
    }
  }

  int range = max - min;
  if (range == 0) {
    range = 1;
  }

  for (int i = 0; i < 10; i++) {
    points[i].x = 0 + i * 7.4;
    points[i].y = 97 - (state->wpm[i] - min) * 32 / range;
  }
#endif

  lv_canvas_draw_line(canvas, points, 10, &line_dsc);
}

static void draw_label(lv_obj_t *canvas, const struct status_state *state) {
  lv_draw_label_dsc_t label_dsc_wpm;
  init_label_dsc(&label_dsc_wpm, LVGL_FOREGROUND, &pixel_operator_mono,
                 LV_TEXT_ALIGN_LEFT);

  char wpm_text[10] = {};

  snprintf(wpm_text, sizeof(wpm_text), "%d", state->wpm[9]);
  // if wpm < 10, elsse if wpm => 10 and wpm < 100, else wpm >= 100
  if (state->wpm[9] < 10) {
    lv_canvas_draw_text(canvas, 12, 75, 50, &label_dsc_wpm, wpm_text);
  } else if (state->wpm[9] >= 10 && state->wpm[9] < 100) {
    lv_canvas_draw_text(canvas, 8, 75, 50, &label_dsc_wpm, wpm_text);
  } else {
    lv_canvas_draw_text(canvas, 5, 75, 50, &label_dsc_wpm, wpm_text);
  }
  // lv_canvas_draw_text(canvas, 0, 103, 50, &label_dsc_wpm, wpm_text);
}

static void draw_bongocat(lv_obj_t *canvas, const struct status_state *state) {
  lv_obj_t *art = lv_animimg_create(canvas);
  lv_obj_center(art);

  const lv_img_dsc_t *idle_imgs[] = {
      &bongo_cat_both1_open,
      &bongo_cat_both1_open,
      &bongo_cat_both1_open,
      &bongo_cat_both1,
  };
  const lv_img_dsc_t *slow_imgs[] = {
      &bongo_cat_left1,  &bongo_cat_both1, &bongo_cat_both1,
      &bongo_cat_right1, &bongo_cat_both1, &bongo_cat_both1,
      &bongo_cat_left1,  &bongo_cat_both1, &bongo_cat_both1,
  };
  const lv_img_dsc_t *mid_imgs[] = {
      &bongo_cat_left2,  &bongo_cat_left1,  &bongo_cat_none,
      &bongo_cat_right2, &bongo_cat_right1, &bongo_cat_none,
  };
  const lv_img_dsc_t *fast_imgs[] = {
      &bongo_cat_both2,
      &bongo_cat_both1,
      &bongo_cat_none,
      &bongo_cat_none,
  };

  int animation_speed;

  if (state->wpm[9] < 5) {
    lv_animimg_set_src(art, (const void **)idle_imgs,
                       sizeof(idle_imgs) / sizeof(lv_img_dsc_t *));
    animation_speed = 10000;
  } else if (state->wpm[9] < 30) {
    lv_animimg_set_src(art, (const void **)slow_imgs,
                       sizeof(slow_imgs) / sizeof(lv_img_dsc_t *));
    animation_speed = 2000;
  } else if (state->wpm[9] < 70) {
    lv_animimg_set_src(art, (const void **)mid_imgs,
                       sizeof(mid_imgs) / sizeof(lv_img_dsc_t *));
    animation_speed = 500;
  } else {
    lv_animimg_set_src(art, (const void **)fast_imgs,
                       sizeof(fast_imgs) / sizeof(lv_img_dsc_t *));
    animation_speed = 200;
  }

  lv_animimg_set_duration(art, animation_speed);
  lv_animimg_set_repeat_count(art, LV_ANIM_REPEAT_INFINITE);
  lv_animimg_start(art);
}

void draw_wpm_status(lv_obj_t *canvas, const struct status_state *state) {
  draw_gauge(canvas, state);
  draw_needle(canvas, state);
  draw_grid(canvas);
  draw_graph(canvas, state);
  draw_label(canvas, state);
  // TODO: STAR
  // draw_bongocat(canvas, state);
  // TODO: END
}
