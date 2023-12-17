#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"



extern "C" void app_main();

#define LED_PIN GPIO_NUM_2

void app_main()
{
    // La siguiente linea de codigo config. el GPIO2 (led0) como salida
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while(1)
    {
        //led0 1 ENCENDIDO, 0 APAGADO
        gpio_set_level(LED_PIN, 1);

        //DELAY -> en milisegundos -> 0,5 s
        vTaskDelay(500/portTICK_PERIOD_MS);

        //led0 1 ENCENDIDO, 0 APAGADO
        gpio_set_level(LED_PIN, 0);

        //DELAY -> en milisegundos -> 0,5 s
        vTaskDelay(500/portTICK_PERIOD_MS);
    }

}