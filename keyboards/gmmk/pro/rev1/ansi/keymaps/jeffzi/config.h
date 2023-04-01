#pragma once

// Force n-key rollover
#define FORCE_NKRO

#undef DEBOUNCE
/* High debounce time is required to avoid key chattering because of the debouncing
 * algorithm sym_eager_pk */
#define DEBOUNCE 40

#ifdef RGB_MATRIX_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_TIMEOUT 300000      // 5 minutes (5 * 60 * 1000ms)
#    define RGB_MATRIX_KEYPRESSES          // Enables REACTIVE & SPLASH modes
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS // Enables Heatmap, Rain

// RGB step values
#    define RGBLIGHT_HUE_STEP \
        32 // The number of steps to cycle through the hue by (default 10)
#    define RGBLIGHT_SAT_STEP \
        17 // The number of steps to increment the saturation by (default 17)
#    define RGBLIGHT_VAL_STEP \
        17 // The number of steps to increment the brightness by (default 17)

// Startup values, when none have been set
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#    define RGB_MATRIX_DEFAULT_HUE 0
#    define RGB_MATRIX_DEFAULT_SAT 255
#    define RGB_MATRIX_DEFAULT_VAL 127
#    define RGB_MATRIX_DEFAULT_SPD 127
#    define RGB_TRIGGER_ON_KEYDOWN

#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE

// These effects seems to be necessary to have full leds + reactive effect...
// #undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #undef ENABLE_RGB_MATRIX_BREATHING
// #undef ENABLE_RGB_MATRIX_BAND_VAL
// #undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
// #undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #undef ENABLE_RGB_MATRIX_CYCLE_ALL
// #undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
// #undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #undef ENABLE_RGB_MATRIX_PIXEL_RAIN
// #undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #undef ENABLE_RGB_MATRIX_DIGITAL_RAIN

// Uncomment any #undef line below to turn OFF any default enabled RGB background effect
// (enabled in keyboards/gmmk/pro/config.h).
#    undef ENABLE_RGB_MATRIX_ALPHAS_MODS

#    undef ENABLE_RGB_MATRIX_BAND_SAT
#    undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT

#    undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    undef ENABLE_RGB_MATRIX_RAINBOW_BEACON

#    undef ENABLE_RGB_MATRIX_DUAL_BEACON
#    undef ENABLE_RGB_MATRIX_RAINDROPS
#    undef ENABLE_RGB_MATRIX_HUE_BREATHING
#    undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#    undef ENABLE_RGB_MATRIX_HUE_WAVE
#    undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#    undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL

// #    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    undef ENABLE_RGB_MATRIX_SPLASH
#    undef ENABLE_RGB_MATRIX_MULTISPLASH
#    undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#    undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
