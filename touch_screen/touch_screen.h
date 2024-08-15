#ifndef TOUCH_SCREEN_TOUCH_H
#define TOUCH_SCREEN_TOUCH_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>
#include "../softspi.h"

/**
 * Parameters for calibration.
 */
#ifndef TOUCH_SCREEN_MARGIN
#define TOUCH_SCREEN_MARGIN 0
#endif
#ifndef TOUCH_SCREEN_ADC_MAX
#define TOUCH_SCREEN_ADC_MAX 0x07FF
#endif
/**
 * Read parameters
 */
#define TOUCH_SCREEN_DFR_MODE 3
#define TOUCH_SCREEN_SER_MODE 4
#define TOUCH_SCREEN_READ_X 0x90
#define TOUCH_SCREEN_READ_Y 0xD0

#define TOUCH_ROTATION_0 0
#define TOUCH_ROTATION_90 1
#define TOUCH_ROTATION_180 2
#define TOUCH_ROTATION_270 3
#define TOUCH_INVERT_Y 4

#ifndef TOUCH_ROTATION
#define TOUCH_ROTATION (TOUCH_ROTATION_180 | TOUCH_INVERT_Y)
#endif

#if ((TOUCH_ROTATION == TOUCH_ROTATION_0) || (TOUCH_ROTATION == (TOUCH_ROTATION_270 | TOUCH_INVERT_Y)))
#define CALC_X(width, x) (x)
#define CALC_Y(height, y) (y)
#elif ((TOUCH_ROTATION == TOUCH_ROTATION_90) || (TOUCH_ROTATION == (TOUCH_ROTATION_180 | TOUCH_INVERT_Y)))
#define CALC_X(width, x) ((width) - (x))
#define CALC_Y(height, y) (y)
#elif ((TOUCH_ROTATION == TOUCH_ROTATION_180) || (TOUCH_ROTATION == (TOUCH_ROTATION_90 | TOUCH_INVERT_Y)))
#define CALC_X(width, x) ((width) - (x))
#define CALC_Y(height, y) ((height) - (y))
#elif (TOUCH_ROTATION == TOUCH_ROTATION_270 || (TOUCH_ROTATION == (TOUCH_ROTATION_0 | TOUCH_INVERT_Y)))
#define CALC_X(width, x) (x)
#define CALC_Y(height, y) ((height) - (y))
#else
#error "Invalid touch screen rotation"
#endif

#define TOUCH_SCREEN_PARAMS_ROTATE 1
#define TOUCH_SCREEN_PARAMS_INVERT_X 2
#define TOUCH_SCREEN_PARAMS_INVERT_Y 4

	void touch_screen_init(softspi_port_t* spiport, uint16_t width, uint16_t height, uint8_t cs_pin, uint8_t penirq_pin);
	void touch_screen_get_calibration(uint16_t *x1, uint16_t *y1, uint16_t *x2, uint16_t *y2);
	void touch_screen_set_calibration(float adc_x1, float adc_y1, float adc_x2, float adc_y2);
	void touch_screen_get_adc(uint16_t *adc_x, uint16_t *adc_y, uint8_t max_samples);
	bool touch_screen_is_touching();
	void touch_screen_get_position(uint16_t *x, uint16_t *y, uint8_t max_samples);

#ifdef __cplusplus
}
#endif
#endif