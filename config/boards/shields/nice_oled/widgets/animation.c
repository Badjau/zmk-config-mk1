#include "animation.h"
#include <stdlib.h>
#include <zephyr/kernel.h>

#if IS_ENABLED(CONFIG_NICE_OLED_GEM_ANIMATION)
LV_IMG_DECLARE(crystal_01);
LV_IMG_DECLARE(crystal_02);
LV_IMG_DECLARE(crystal_03);
LV_IMG_DECLARE(crystal_04);
LV_IMG_DECLARE(crystal_05);
LV_IMG_DECLARE(crystal_06);
LV_IMG_DECLARE(crystal_07);
LV_IMG_DECLARE(crystal_08);
LV_IMG_DECLARE(crystal_09);
LV_IMG_DECLARE(crystal_10);
LV_IMG_DECLARE(crystal_11);
LV_IMG_DECLARE(crystal_12);
LV_IMG_DECLARE(crystal_13);
LV_IMG_DECLARE(crystal_14);
LV_IMG_DECLARE(crystal_15);
LV_IMG_DECLARE(crystal_16);

const lv_img_dsc_t *anim_imgs[] = {
    &crystal_01, &crystal_02, &crystal_03, &crystal_04,
    &crystal_05, &crystal_06, &crystal_07, &crystal_08,
    &crystal_09, &crystal_10, &crystal_11, &crystal_12,
    &crystal_13, &crystal_14, &crystal_15, &crystal_16,
};
#endif

#if IS_ENABLED(CONFIG_NICE_OLED_POKEMON_ANIMATION)
// 01 to 20
LV_IMG_DECLARE(pokemon01);
LV_IMG_DECLARE(pokemon02);
LV_IMG_DECLARE(pokemon03);
LV_IMG_DECLARE(pokemon04);
LV_IMG_DECLARE(pokemon05);
LV_IMG_DECLARE(pokemon06);
LV_IMG_DECLARE(pokemon07);
LV_IMG_DECLARE(pokemon08);
LV_IMG_DECLARE(pokemon09);
LV_IMG_DECLARE(pokemon10);
LV_IMG_DECLARE(pokemon11);
LV_IMG_DECLARE(pokemon12);
LV_IMG_DECLARE(pokemon13);
LV_IMG_DECLARE(pokemon14);
LV_IMG_DECLARE(pokemon15);
LV_IMG_DECLARE(pokemon16);
LV_IMG_DECLARE(pokemon17);
LV_IMG_DECLARE(pokemon18);
LV_IMG_DECLARE(pokemon19);
LV_IMG_DECLARE(pokemon20);

const lv_img_dsc_t *anim_imgs[] = {
    &pokemon01, &pokemon02, &pokemon03, &pokemon04, &pokemon05,
    &pokemon06, &pokemon07, &pokemon08, &pokemon09, &pokemon10,
    &pokemon11, &pokemon12, &pokemon13, &pokemon14, &pokemon15,
    &pokemon16, &pokemon17, &pokemon18, &pokemon19, &pokemon20,
};
#endif

#if IS_ENABLED(CONFIG_NICE_OLED_CUSTOM_ANIMATION)
// 01 to 20
LV_IMG_DECLARE(custom_01);
LV_IMG_DECLARE(custom_02);
LV_IMG_DECLARE(custom_03);
LV_IMG_DECLARE(custom_04);
LV_IMG_DECLARE(custom_05);
LV_IMG_DECLARE(custom_06);
LV_IMG_DECLARE(custom_07);
LV_IMG_DECLARE(custom_08);
LV_IMG_DECLARE(custom_09);
LV_IMG_DECLARE(custom_10);
LV_IMG_DECLARE(custom_11);
LV_IMG_DECLARE(custom_12);
LV_IMG_DECLARE(custom_13);
LV_IMG_DECLARE(custom_14);
LV_IMG_DECLARE(custom_15);
LV_IMG_DECLARE(custom_16);
LV_IMG_DECLARE(custom_17);
LV_IMG_DECLARE(custom_18);
LV_IMG_DECLARE(custom_19);
LV_IMG_DECLARE(custom_20);
LV_IMG_DECLARE(custom_21);
LV_IMG_DECLARE(custom_22);
LV_IMG_DECLARE(custom_23);
LV_IMG_DECLARE(custom_24);
LV_IMG_DECLARE(custom_25);
LV_IMG_DECLARE(custom_26);
LV_IMG_DECLARE(custom_27);
LV_IMG_DECLARE(custom_28);
LV_IMG_DECLARE(custom_29);
LV_IMG_DECLARE(custom_30);
LV_IMG_DECLARE(custom_31);
LV_IMG_DECLARE(custom_32);
LV_IMG_DECLARE(custom_33);
LV_IMG_DECLARE(custom_34);
LV_IMG_DECLARE(custom_35);
LV_IMG_DECLARE(custom_36);
LV_IMG_DECLARE(custom_37);
LV_IMG_DECLARE(custom_38);
LV_IMG_DECLARE(custom_39);
LV_IMG_DECLARE(custom_40);
LV_IMG_DECLARE(custom_41);
LV_IMG_DECLARE(custom_42);
LV_IMG_DECLARE(custom_43);
LV_IMG_DECLARE(custom_44);
LV_IMG_DECLARE(custom_45);

const lv_img_dsc_t *anim_imgs[] = {
    &custom_01, &custom_01, &custom_02, &custom_02, &custom_01, &custom_01, 
    &custom_02, &custom_02, &custom_03, &custom_03, &custom_03, &custom_04, 
    &custom_04, &custom_03, &custom_03, &custom_04, &custom_05, &custom_05, 
    &custom_05, &custom_06, &custom_06, &custom_08, &custom_08, &custom_09, 
    &custom_09, &custom_08, &custom_08, &custom_09, &custom_09, &custom_10, 
    &custom_10, &custom_11, 
    &custom_11, &custom_11, &custom_12, &custom_12, &custom_12, &custom_14, 
    &custom_14, &custom_14, &custom_15, &custom_15, &custom_14, &custom_14, 
    &custom_15, &custom_15, &custom_14, &custom_14, &custom_16, &custom_16, 
    &custom_17, &custom_17, &custom_17, &custom_18, &custom_18, &custom_18, 
    &custom_19, &custom_19, &custom_20, &custom_20, &custom_19, &custom_19, 
    &custom_21, &custom_21, &custom_21, &custom_22, &custom_22, &custom_22, 
    &custom_23, &custom_23, &custom_23, &custom_24, &custom_24, &custom_25, 
    &custom_25, &custom_24, &custom_24, &custom_25, &custom_25, &custom_25, 
    &custom_24, &custom_24, &custom_22, &custom_22, &custom_22, &custom_08, 
    &custom_08, &custom_08, &custom_05, &custom_05, &custom_03, &custom_03,
    &custom_01, &custom_26, &custom_27, &custom_28, &custom_29, &custom_30, 
    &custom_31, &custom_32, &custom_33, &custom_34, &custom_35, &custom_36, 
    &custom_37, &custom_38, &custom_39, &custom_40, &custom_41, &custom_42, 
    &custom_43, &custom_44, &custom_44, &custom_45, &custom_45, &custom_44, 
    &custom_44, &custom_45, &custom_45, &custom_44, &custom_44, &custom_45, 
    &custom_45, &custom_44, 
    &custom_44, &custom_45, &custom_45, &custom_44, &custom_44, &custom_45, 
    &custom_45, 
};
#endif

// NICE_OLEDE_OLED
#if IS_ENABLED(CONFIG_NICE_OLED_VIM)
LV_IMG_DECLARE(vim);
#define FIXED_IMAGE_1 &vim
#endif

#if IS_ENABLED(CONFIG_NICE_OLED_VIP_MARCOS)
LV_IMG_DECLARE(vip_marcos);
#define FIXED_IMAGE_2 &vip_marcos
#endif

void draw_animation(lv_obj_t *canvas, struct zmk_widget_screen *widget) {
#if IS_ENABLED(CONFIG_NICE_OLED_GEM_ANIMATION)
  lv_obj_t *art = lv_animimg_create(widget->obj);
  lv_obj_center(art);

  lv_animimg_set_src(art, (const void **)anim_imgs, 16);
  lv_animimg_set_duration(art, CONFIG_NICE_OLED_GEM_ANIMATION_MS);
  lv_animimg_set_repeat_count(art, LV_ANIM_REPEAT_INFINITE);
  lv_animimg_start(art);

  // fix the error compiling if the images are not used
  lv_obj_t *art2 = NULL; // Para la segunda imagen, si es necesario
#endif

#if IS_ENABLED(CONFIG_NICE_OLED_POKEMON_ANIMATION)
  lv_obj_t *art = lv_animimg_create(widget->obj);
  lv_obj_center(art);

  lv_animimg_set_src(art, (const void **)anim_imgs, 20);
  lv_animimg_set_duration(art, CONFIG_NICE_OLED_POKEMON_ANIMATION_MS);
  lv_animimg_set_repeat_count(art, LV_ANIM_REPEAT_INFINITE);
  lv_animimg_start(art);

  // fix the error compiling if the images are not used
  lv_obj_t *art2 = NULL; // Para la segunda imagen, si es necesario
#endif

#if IS_ENABLED(CONFIG_NICE_OLED_CUSTOM_ANIMATION)
  lv_obj_t *art = lv_animimg_create(widget->obj);
  lv_obj_center(art);

  lv_animimg_set_src(art, (const void **)anim_imgs, 131);
  lv_animimg_set_duration(art, CONFIG_NICE_OLED_CUSTOM_ANIMATION_MS);
  lv_animimg_set_repeat_count(art, LV_ANIM_REPEAT_INFINITE);
  lv_animimg_start(art);

  // fix the error compiling if the images are not used
  lv_obj_t *art2 = NULL; // Para la segunda imagen, si es necesario
#endif

#if IS_ENABLED(CONFIG_NICE_OLED_VIM) || IS_ENABLED(CONFIG_NICE_OLED_VIP_MARCOS)
  lv_obj_t *art = NULL;
  lv_obj_t *art2 = NULL; // Para la segunda imagen, si es necesario

#if IS_ENABLED(CONFIG_NICE_OLED_VIM)
  art = lv_img_create(widget->obj);
  lv_img_set_src(art, FIXED_IMAGE_1); // Fija la primera imagen
#endif

#if IS_ENABLED(CONFIG_NICE_OLED_VIM)
  art2 = lv_img_create(widget->obj);
  lv_img_set_src(art2, FIXED_IMAGE_2); // Fija la segunda imagen
#endif

  // Si no se utilizan las imágenes fijas, se puede usar la lógica aleatoria
  if (!art && !art2) {
    art = lv_img_create(widget->obj);
    int length = sizeof(anim_imgs) / sizeof(anim_imgs[0]);
    srand(k_uptime_get_32());
    int random_index = rand() % length;
    lv_img_set_src(art, anim_imgs[random_index]);
  }
#endif

  // Alineación de las imágenes
  if (art) {
    // lv_obj_align(art, LV_ALIGN_TOP_LEFT, x coordinate, y coordinate);
#if IS_ENABLED(CONFIG_NICE_OLED_GEM_ANIMATION)
    lv_obj_align(art, LV_ALIGN_TOP_LEFT, 18, -18);
#endif
#if IS_ENABLED(CONFIG_NICE_OLED_POKEMON_ANIMATION)
    lv_obj_align(art, LV_ALIGN_TOP_LEFT, -18, -18);
#endif
#if IS_ENABLED(CONFIG_NICE_OLED_CUSTOM_ANIMATION)
    lv_obj_align(art, LV_ALIGN_TOP_LEFT, 18, 0);
#endif
#if IS_ENABLED(CONFIG_NICE_OLED_VIM)
    lv_obj_align(art, LV_ALIGN_TOP_LEFT, 0, 0);
#endif
  }
  if (art2) {
    lv_obj_align(art2, LV_ALIGN_TOP_LEFT, 2,
                 0); // Ajusta la posición de la segunda imagen
    // lv_obj_align(art2, LV_ALIGN_TOP_LEFT, 36, 50); // Ajusta la posición de
    // la segunda imagen
  }
}
