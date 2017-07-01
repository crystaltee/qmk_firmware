#include "xd60.h"
#include "action_layer.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Base Layer
  KEYMAP(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_DEL,    \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
      KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,          KC_ENT,    \
      KC_LSFT, KC_LSFT,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_NO,  F(2),    KC_UP,    F(0),    \
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RALT, KC_LCTL,  KC_LEFT, KC_DOWN,  KC_RIGHT),

  // 1: Function Layer 1
  KEYMAP(
      KC_GRV,  KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,    KC_F11,  KC_F12,  KC_BSPC,  KC_DEL,    \
      KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,  KC_NO,           KC_PSCR,   \
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO,  KC_NO,          KC_ENT,    \
      KC_LSFT, KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,  KC_NO,  KC_SLSH,    F(3),    F(0),    \
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RALT, F(1),  KC_HOME, KC_PGDOWN,  KC_END),

  // 2: Function Layer 2 + RGB Layer
  KEYMAP(
      KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,    \
      KC_NO,   RGB_TOG, RGB_MOD, KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,             KC_NO,    \
      KC_NO,   RGB_HUI, RGB_SAI, RGB_VAI, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,             KC_NO,    \
      KC_NO,   KC_NO,   RGB_HUD, RGB_SAD, RGB_VAD,KC_NO,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    \
      KC_NO,   KC_NO,   KC_NO,                            KC_NO,                           KC_NO,   F(1),    KC_NO,   KC_NO,    KC_NO),

};

// Custom Actions
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Function Layer 1
    [1] = ACTION_LAYER_MOMENTARY(2),  // to Function Layer 2 + RGB
    [2] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_SLSH), //Right Shift tap will trigger ?/, hold will trigger Shift
    [3] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_PGUP), //Right Shift tap will trigger Page Up, hold will trigger Shift
};

// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) { register_code(KC_RSFT); }
      else { unregister_code(KC_RSFT); }
      break;
  }

  return MACRO_NONE;
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
