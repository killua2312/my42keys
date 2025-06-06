#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NUM,
    _FN,
    _COMB
};

enum custom_keycodes {
    CS_MACRO,
    LAYER_COMBO
};

// Define combo events
enum combo_events {
    COMBO_LAYER,  // Combo to activate _COMB layer
};

const uint16_t PROGMEM layer_combo[] = {MO(_NUM), MO(_FN), COMBO_END};
combo_t key_combos[] = {
    [COMBO_LAYER] = COMBO(layer_combo, LAYER_COMBO)
};

bool is_combo_active = false;

// Make sure to put this in your config.h file instead of here:
// #define COMBO_TERM 200

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CS_MACRO:
            if (record->event.pressed) {
                // Press Cmd + Shift
                register_code(KC_LCMD);
                register_code(KC_LSFT);
            } else {
                // Release Cmd + Shift
                unregister_code(KC_LSFT);
                unregister_code(KC_LCMD);
            }
            return false;
            
        case LAYER_COMBO:
            if (record->event.pressed) {
                layer_on(_COMB);
                is_combo_active = true;
            } else {
                layer_off(_COMB);
                is_combo_active = false;
            }
            return false;

        // Add handling for the layer keys to ensure combo layer is properly managed
        case MO(_NUM):
        case MO(_FN):
            if (!record->event.pressed && is_combo_active) {
                layer_off(_COMB);
                is_combo_active = false;
            }
            return true;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                  KC_LCMD, MO(_NUM), KC_LSFT,                   KC_SPC,  MO(_FN), KC_RALT
    ),
    [_NUM] = LAYOUT_split_3x6_3(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_BSLS,
        KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_NO,   CS_MACRO,                  KC_NO,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_ENT,
                                  KC_LCMD, KC_TRNS,  KC_LSFT,                   KC_SPC,  KC_TRNS, KC_RALT
    ),
    [_FN] = LAYOUT_split_3x6_3(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        KC_TAB,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ENT,
                                  KC_LCMD, KC_TRNS,  KC_LSFT,                   KC_SPC,  KC_TRNS, KC_RALT
    ),
   [_COMB] = LAYOUT_split_3x6_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TAB,  KC_BTN1, KC_BTN3, KC_BTN2, KC_WH_U, KC_WH_D,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ACL0, KC_ACL1,
        KC_LCTL, KC_MUTE, KC_VOLU, KC_VOLD, KC_PSCR, KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ENT,
                                  KC_LCMD, KC_TRNS,  KC_LSFT,                   KC_SPC,  KC_TRNS, KC_RALT
   )
};
