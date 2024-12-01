download the fonts: https://fonts2u.com/pixel-operator-mono.font
install the font converter: npm install -g lv_font_conv
convert the font:
lv_font_conv --font PixelOperatorMono.ttf --size 8 --format lvgl --bpp 1 --range 0x20-0x7F --no-compress -o pixel_operator_mono.c
