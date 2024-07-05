#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NUM,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer: Default Alphanumeric Keys
     * ,--------------------------------------------------.                    ,--------------------------------------------------.
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |                          |   Y  |   U  |   I  |   O  |   P  |  Bksp |
     * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |                          |   H  |   J  |   K  |   L  |  ;   |  '    |
     * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
     * | Ctrl |   Z  |   X  |   C  |   V  |   B  |                          |   N  |   M  |  ,   |  .   |  /   | Enter|
     * |------+------+------+------+------+------+------+------|            |------+------+------+------+------+------+------|
     * | cmd | MO(1)| Shift|                                          | space | MO(2) | RAlt |
     * `------------------------------------------------'                    `------------------------------------------------'
     */
    [_BASE] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                  KC_LCMD, MO(_NUM), KC_LSFT,                   KC_SPC, MO(_FN), KC_RALT
    ),

    /* Number Layer: Function keys, Numbers, Navigation
     * ,--------------------------------------------------.                    ,--------------------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                          |   6  |   7  |   8  |   9  |   0  |  Del  |
     * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
     * | Tab  |  xxx |  xxx |  xxx |  xxx |  xxx |                          | Left | Down |  Up  | Right|  xxx |  \    |
     * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
     * | Ctrl |  xxx |  xxx |  xxx |  xxx |  xxx |                          |  xxx |  -   |  =   |  [   |  ]   |  xxx |
     * |------+------+------+------+------+------+------+------|            |------+------+------+------+------+------+------|
     * | cmd |  xxx | Shift |                                        | space |  MO(2) | RAlt|
     * `------------------------------------------------'                    `------------------------------------------------'
     */
    [_NUM] = LAYOUT_split_3x6_3(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_TAB,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_BSLS,
        KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_NO,
                                  KC_LCMD, KC_NO,   KC_LSFT,                    KC_SPC, KC_NO,   KC_RALT
    ),

    /* Function Layer: Media, Mouse Controls
     * ,--------------------------------------------------.                    ,--------------------------------------------------.
     * | F1   | F2   | F3   | F4   | F5   | F6   |                          | F7   | F8   | F9   | F10  | F11  | F12   |
     * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
     * |  Tab | mclk | mclk | mclk | mwup | mwdn |                          | cleft| cdown|  cup |cright|  mac0|  mac1 |
     * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
     * | Ctrl | mute | vol+ | vol- | sshot|  xxx |                          |  xxx |  xxx |  xxx |  xxx |  xxx |  xxx |
     * |------+------+------+------+------+------+------+------|            |------+------+------+------+------+------+------|
     * | cmd |  xxx | Shift |                                       | space |  MO(2) | RAlt |
     * `------------------------------------------------'                    `------------------------------------------------'
     */
    [_FN] = LAYOUT_split_3x6_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TAB,   KC_BTN1, KC_BTN3, KC_BTN2, KC_WH_U, KC_WH_D,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ACL0, KC_ACL1,
        KC_LCTL, KC_MUTE, KC_VOLU, KC_VOLD, KC_PSCR, KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                  KC_LCMD, KC_NO,   KC_LSFT,                    KC_SPC, KC_NO,   KC_RALT
    )
};


