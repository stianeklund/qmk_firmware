#include QMK_KEYBOARD_H

enum {
    TD_WIN_E,    // Tap once for LGUI, twice for LGUI + E
    TD_ALT_GR,   // Tap once for .. hold for ALT-GR Layer 5
    TD_HOME_END, // Tap once for Home, twice for End
    TD_ALT_TAB   // Quickly switch between windows
};

qk_tap_dance_action_t tap_dance_actions [] = {
    [TD_WIN_E] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_E)),
    [TD_ALT_GR] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, MT(MOD_RALT, KC_TRNS)),
    [TD_HOME_END] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
    [TD_ALT_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, LALT(KC_TAB)),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_5x6(
            LT(4,KC_ESC), KC_1, KC_2, KC_3, KC_4, KC_5,                               KC_6, KC_7, KC_8, KC_9, KC_0, LT(4,KC_MINS),
            KC_TAB, KC_Q, KC_D, KC_R, KC_W, KC_B,                                     KC_J, KC_F, KC_U, KC_P, KC_SCLN, KC_BSLS,
            KC_LCTL, KC_A, KC_S, KC_H, KC_T, KC_G,                                    KC_Y, KC_N, KC_E, KC_O, KC_I, KC_QUOT,
            KC_LSFT, KC_Z, KC_X, KC_M, KC_C, KC_V,                                    KC_K, KC_L, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                           KC_LEFT, LT(2,KC_RGHT),                                                    LT(2, KC_UP), KC_DOWN,
                                  LT(1,KC_BSPC), LT(2,KC_DEL),                      RALT_T(KC_ENT), LT(1, KC_SPC),

                                         TD(TD_ALT_TAB), TO(3),                  TO(3), LT(3, KC_RALT),
                                         TD(TD_HOME_END), TD(TD_WIN_E),   TD(TD_WIN_E), TD(TD_HOME_END)),

                /* LT(2,KC_BSPC), LT(1,KC_DEL),             LT(2,KC_ENT), LT(1,KC_SPC),
                LT(2,KC_HOME), KC_LALT,                     KC_RALT, KC_RCTL,
                LT(3,KC_END),  KC_LGUI,                     LT(3,KC_GRV), KC_COPY), */


	[1] = LAYOUT_5x6(
            KC_EQL, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
            KC_PPLS, KC_BSLS, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,                    KC_RPRN, KC_P7, KC_P8, KC_P9, KC_MINS, KC_PPLS,
            KC_GRV, KC_LPRN, KC_RPRN, LSFT(KC_LBRC), RSFT(KC_RBRC), RSFT(KC_LBRC),   RSFT(KC_RBRC), KC_P4, KC_P5, KC_P6, KC_EQL, KC_EQL,
            KC_UNDS, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC,                            KC_RBRC, KC_P1, KC_P2, KC_P3, KC_NO, KC_UNDS,
                              KC_TRNS, KC_TRNS,                                                       KC_TRNS, KC_TRNS,
                                         LSFT(KC_LBRC), RSFT(KC_RBRC),                   KC_TRNS, KC_P0,

                                                        KC_COPY, KC_PSTE,   KC_PSTE, KC_COPY,
                                                        KC_TRNS, TO(0),     TO(0),   KC_TRNS),
	[2] = LAYOUT_5x6(
            KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
            KC_TRNS, LALT_T(KC_F7), KC_HOME, KC_PGDN, KC_PGUP, KC_END,                  KC_RBRC, KC_TRNS, KC_NLCK, KC_INS, KC_SLCK, KC_MUTE,
            KC_LCTL, KC_UP, KC_DOWN, KC_LEFT, KC_RGHT, LSFT(KC_LBRC),                 RSFT(KC_RBRC), KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_VOLU,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LPRN,                     KC_RPRN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,
                              KC_TRNS, KC_TRNS,                                                         KC_EQL, KC_TRNS,
                                         KC_TRNS, KC_TRNS,                                        KC_TRNS, KC_TRNS,

                                                    KC_GRV, KC_LCTL,      KC_RCTL, KC_GRV,
                                                    KC_TRNS, TO(0),       TO(0), LGUI(KC_L)),
	[3] = LAYOUT_5x6(
            KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U,                         KC_WH_U, KC_HOME, KC_UP, KC_NO, KC_NO, KC_END,
            KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                         KC_WH_D, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                          KC_NO, KC_NO,                                                             KC_NO, KC_NO,
                                      KC_ACL1, KC_ACL2,                             KC_ACL2, KC_ACL1,
                                                    KC_ACL0, TO(0),   KC_NO, KC_ACL0,
                                                    KC_NO,   TO(0),   TO(0), KC_TRNS),
	[4] = LAYOUT_5x6(
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, EEP_RST,                               EEP_RST, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET,                                 RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                          KC_NO, KC_NO,                                                             KC_NO, KC_NO,
                                       KC_NO, KC_NO,                               KC_NO, KC_NO,
                                                    KC_NO, KC_NO,     KC_NO, KC_NO,
                                                    KC_NO, KC_NO,     KC_NO, KC_TRNS),
    [5] = LAYOUT_5x6(
            LT(4,KC_ESC), KC_1, KC_2, KC_3, KC_4, KC_5,                               KC_6, KC_7, KC_8, KC_9, KC_0, LT(4,KC_MINS),
            KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                     KC_Y, KC_U, KC_I, RALT(KC_O), KC_P, KC_BSLS,
            KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                                    KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
            KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                    KC_M, KC_N, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                           KC_LEFT, KC_RGHT,                                                      KC_UP, KC_DOWN,
                                  LT(2,KC_BSPC), LT(1,KC_DEL),                      LT(2,KC_ENT), LT(1,KC_SPC),

                                            KC_LALT, KC_LGUI,             KC_RCTL, KC_RALT,
                                            LT(2,KC_HOME),TO(0),      TO(0), LT(3,KC_GRV)),
};
