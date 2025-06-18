/* ========================================
FileName: dog.h
Date: 15:40 05.September.2022
Author: Marcos Ivan Chow Castro @mctechnology17
Email: mctechnology170318@gmail.com
GitHub: https://github.com/mctechnology17
Brief: QMK oled animations dog_cat
===========================================
                           ╔═╦═╦═╗
                    ╔════╗ ║║║║║╔╝
                    ║╔╗╔╗║ ║║║║║╚╗
                    ╚╝║║╚╝ ║╠═╩╩═╝
                      ║╠═╦═╣╚╦═╦╦═╦╗╔═╦═╦╦╗
                      ║║╩╣═╣║║║║║╬║╚╣╬║╬║║║
                      ╚╩═╩═╩╩╩╩═╩═╩═╩═╬╗╠╗║
                                      ╚═╩═╝

Copyright 2022 Marcos Ivan Chow Castro @mctechnology17
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#define ANIM_SIZE_DOG 96            // numero de pixeles en cada frame del perro
#define ANIM_FRAME_DURATION_DOG 200 // para bongocat y el perro cuanto tiempo mostrar cada frame
extern uint8_t current_wpm_dog;     // NOTE: 3. current_wpm to current_wpm_dog parte como 0
extern led_t   led_usb_state_dog;   // NOTE: 2. led_usb_state to led_usb_state_dog
extern bool    showedJump_dog;      // NOTE: 4. showedJump to showedJump_dog
extern bool    isJumping_dog;       // NOTE: 5. isJumping to isJumping_dog
void           render_dog(int DOG_X, int DOG_Y);

// vim: set fdm=marker:
