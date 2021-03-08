#include QMK_KEYBOARD_H

#define KC_____ KC_TRNS

enum layer_number {
  _QWERTY = 0,
  _QWERTY_MODS,
  _FUNC1,
  _FUNC2,
};

enum combos {
  CMB_DEL
};

enum custom_keycodes {
  KC_HMOD = SAFE_RANGE
};

// QWERTY Homerow Mods
#define KC_LG_A MT(MOD_LGUI, KC_A)
#define KC_LA_S MT(MOD_LALT, KC_S)
#define KC_LC_D MT(MOD_LCTL, KC_D)
#define KC_LS_F MT(MOD_LSFT, KC_F)

#define KC_RS_J MT(MOD_RSFT, KC_J)
#define KC_RC_K MT(MOD_RCTL, KC_K)
#define KC_RA_L MT(MOD_RALT, KC_L)
#define KC_RGSC MT(MOD_RGUI, KC_SCLN)

const uint16_t PROGMEM del_combo[] = {KC_0, KC_BSPC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CMB_DEL] = COMBO(del_combo, KC_DEL)
};


// ├─┬

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,---------------------------------------------------------.                   .----------------------------------------------------------.
           KC_GRV,   KC_1,   KC_2,   KC_3,    KC_4,       KC_5,                           KC_6,    KC_7,     KC_8,   KC_9,    KC_0,   KC_BSPC,\
  //,------------+-------+-------+-------+-------+------------/                   /-----------+--------+---------+-------+--------+----------/
           KC_TAB,   KC_Q,   KC_W,   KC_E,    KC_R,       KC_T,                           KC_Y,    KC_U,     KC_I,   KC_O,    KC_P,   KC_BSLS,\
  //,------------+-------+-------+-------+-------+------------/                   /-----------+--------+---------+-------+--------+----------/
    CTL_T(KC_ESC),   KC_A,   KC_S,   KC_D,    KC_F,       KC_G,                           KC_H,    KC_J,     KC_K,   KC_L, KC_SCLN,   KC_QUOT,\
  //,------------+-------+-------+-------+-------+------------+--------/  /-------/-----------+--------+---------+-------+--------+----------/
          KC_LSFT,   KC_Z,   KC_X,   KC_C,    KC_V,       KC_B, KC_LBRC,   KC_RBRC,       KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,   KC_RSFT,\
  //,------------+-------+-------+-------+-------+------------+--------/  /-------.-----------+--------+---------+-------+--------+-----------/
                                  KC_LALT, KC_LGUI, MO(_FUNC1),  KC_ENT,    KC_SPC, MO(_FUNC2), KC_BSPC, KC_RCTRL \
                                //,------------------------------------,  ,---------------------------------------,
  ),

  [_QWERTY_MODS] = LAYOUT( \
  //,---------------------------------------------------.                    .----------------------------------------------------.
    KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,                     KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,\
  //,------+--------+--------+--------+--------+--------/                    /-------+--------+--------+--------+--------+--------/
    KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,                     KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,\
  //,------+--------+--------+--------+--------+--------/                    /-------+--------+--------+--------+--------+--------/
    KC_____, KC_LG_A, KC_LA_S, KC_LC_D, KC_LS_F, KC_____,                     KC_____, KC_RS_J, KC_RC_K, KC_RA_L, KC_RGSC, KC_____,\
  //,------+--------+--------+--------+--------+--------+--------/  /-------/-------+--------+--------+--------+--------+---------/
    KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,   KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,\
  //,------+--------+--------+--------+--------+--------+--------/  /-------/-------+--------+--------+--------+--------+---------/
                              KC_____, KC_____, KC_____, KC_____,   KC_____, KC_____, KC_____, KC_____ \
                            //,----------------------------------,  ,-----------------------------------,
),

  [_FUNC1] = LAYOUT( \
  //,-----------------------------------------------------.                    .-----------------------------------------------------.
     KC_F11,   KC_F1,   KC_F2,   KC_F3,     KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F12,\
  //,------+--------+--------+--------+----------+--------/                    /--------+--------+--------+--------+--------+--------/
    KC_____, KC_____, KC_____,  KC_END,   KC_____, KC_____,                      KC_____, KC_____,  KC_INS, KC_____,KC_MINUS,  KC_EQL,\
  //,------+--------+--------+--------+----------+--------/                    /--------+--------+--------+--------+--------+--------/
    KC_____, KC_HOME, KC_____, KC_____,   KC_____, KC_____,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_____, KC_____,\
  //,------+--------+--------+--------+----------+--------+--------/   /-------/--------+--------+--------+--------+--------+--------/
    KC_____, KC_____,  KC_DEL, KC_____, S(KC_INS), KC_____, KC_PGUP,    KC_PGDN, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,\
  //,------+--------+--------+--------+----------+--------+--------/   /-------/--------+--------+--------+--------+--------+--------/
                               KC_____,   KC_____, KC_____, KC_____,    KC_____, KC_____, KC_____, KC_____ \
                             //,-----------------------------------,   ,-----------------------------------,
  ),

  [_FUNC2] = LAYOUT( \
  //,----------------------------------------------------.                    .-----------------------------------------------------.
       RESET, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_____,                      KC_____, KC_____, KC_____, KC_PSCR, KC_SLCK, KC_PAUSE,\
  //,-------+--------+--------+--------+--------+--------/                    /--------+--------+--------+--------+--------+--------/
     KC_____, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_____,                      KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,\
  //,-------+--------+--------+--------+--------+--------/                    /--------+--------+--------+--------+--------+--------/
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,\
  //,-------+--------+--------+--------+--------+--------+--------/   /-------/--------+-------+--------+--------+--------+---------/
       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_VOLD,    KC_VOLU, KC_____, KC_MUTE, KC_____,KC_____, KC_____,  KC_____,\
  //,-------+--------+--------+--------+--------+--------+--------/   /-------/--------+--------+--------+--------+--------+--------/
                                KC_____, KC_____, KC_____, KC_____,    KC_HMOD, KC_____, KC_____, KC_____ \
                              //,---------------------------------,   ,-----------------------------------,
  ),

};

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;

  return rotation;
}

const char *read_layer_state(void);
const char *read_rgb_info(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_rgb_info(), false);
    oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}

void suspend_power_down_user(void) {
  oled_clear();
  oled_off();
}

#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    switch (keycode) {
      // Toggle homerow mods, regardless of the current layout.
      case KC_HMOD:
        if (IS_LAYER_ON(_QWERTY_MODS)) {
          layer_off(_QWERTY_MODS);
        }
        else {
          layer_on(_QWERTY_MODS);
        }

      return false;
    }

    // set_timelog();
  }

  return true;
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    default:
      return true;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    default:
      return false;
  }
}
