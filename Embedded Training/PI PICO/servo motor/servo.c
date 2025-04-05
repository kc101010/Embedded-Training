#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define SERVO_GPIO 16
#define LED_GPIO 25

#define POINT_180 2300
#define POINT_0 700

#define DELAY 1000

/**from https://www.i-programmer.info/programming/hardware/14849-the-pico-in-c-basic-pwm.html?start=2
uint32_t pwm_set_freq_duty(uint slice, uint chan, uint32_t f, int d)
{
    uint32_t clock = 125000000;
    uint32_t divider16 = clock / f / 4096 + (clock % (f * 4096) != 0);

    if (divider16 / 16 == 0)
    {
        divider16 = 16;
    }

    uint32_t wrap = clock * 16 / divider16 / f - 1;

    pwm_set_clkdiv_int_frac(slice, divider16 / 16, divider16 & 0xF);

    pwm_set_wrap(slice, wrap);
    pwm_set_chan_level(slice, chan, wrap * d / 100);

    return wrap;
}

/**pwm_set_freq_duty(servo_pwm_slice, servo_chan, 50, 7864 );
        pwm_set_enabled(servo_pwm_slice, true);**/    

void ServoMoveTo(float degree)
{
    if (degree > 180.0)
    {
        return;
    }

    if (degree < 0)
    {
        return;
    }

    int duty = (((float)(POINT_180 - POINT_0) / 180.0) * degree) + POINT_0;

    pwm_set_gpio_level(SERVO_GPIO, duty);
}

int main()
{
    //init GPIO pins
    gpio_init(SERVO_GPIO);
    gpio_init(LED_GPIO);

    //setup for on-board LED
    gpio_set_dir(LED_GPIO, GPIO_OUT);

    //setup for PWM to control SG90 servo
    gpio_set_function(SERVO_GPIO, GPIO_FUNC_PWM);
    pwm_set_gpio_level(SERVO_GPIO, 0);

    uint servo_pwm_slice = pwm_gpio_to_slice_num(SERVO_GPIO);
    uint servo_chan = pwm_gpio_to_channel(SERVO_GPIO);

    uint32_t clk = clock_get_hz(clk_sys);
    uint32_t div = clk / (20000 * 50);

    if(div < 1)
    {
        div = 1;
    }

    if (div > 255)
    {
        div = 255;
    }

    pwm_config cfg = pwm_get_default_config();
    pwm_config_set_clkdiv(&cfg, (float) div);

    pwm_config_set_wrap(&cfg, 20000);

    pwm_init(servo_pwm_slice, &cfg, false);

    pwm_set_enabled(servo_pwm_slice, true);

    //main loop - flashes LED, controls servo
    while(true)
    {
        gpio_put(LED_GPIO, 1);
        sleep_ms(DELAY);

        ServoMoveTo(180.0);
        sleep_ms(DELAY);

        gpio_put(LED_GPIO, 0);
        sleep_ms(DELAY);

        ServoMoveTo(0.0);
        sleep_ms(DELAY);

    }

    return 0;
}