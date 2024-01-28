#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"



extern "C" void app_main();

//#define LED_PIN GPIO_NUM_2

constexpr gpio_num_t LED_PIN = GPIO_NUM_2;

void app_main()
{
    // La siguiente linea de codigo config. el GPIO2 (led0) como salida
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while(1)
    {
        //led0 1 ENCENDIDO, 0 APAGADO
        gpio_set_level(LED_PIN, 1);

        // //DELAY -> en milisegundos -> 0,5 s
        // vTaskDelay(500/portTICK_PERIOD_MS);

        vTaskDelay(pdMS_TO_TICKS(500));

        //led0 1 ENCENDIDO, 0 APAGADO
        gpio_set_level(LED_PIN, 0);

        //DELAY -> en milisegundos -> 0,5 s
        vTaskDelay(500/portTICK_PERIOD_MS);
    }


    /*OTRA FORMA DE HACERLO:*/

    // Setup:
    // _t -> estructura o tipo
    // Define la variable config con el tipo gpio_config()
    // gpio_config_t config;
    // // Modo de funcionamiento
    // config.mode = GPIO_MODE_OUTPUT;
    // // GPIO pin: set with bit mask, each bit maps to a GPIO
    // // Movemos 1 en el pin 2 para así configurar el pin que queremos
    // config.pin_bit_mask = (1<<LED_PIN);
    // // GPIO interrupt type
    // // Para este ejemplo lo tendremos deshabilitado
    // config.intr_type = GPIO_INTR_DISABLE;
    // config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    // config.pull_up_en = GPIO_PULLUP_DISABLE;

    // // Mandamos la configuración
    // gpio_config(&config);


    // uint64_t pin_bit_mask;          /*!< GPIO pin: set with bit mask, each bit maps to a GPIO */
    // gpio_mode_t mode;               /*!< GPIO mode: set input/output mode                     */
    // gpio_pullup_t pull_up_en;       /*!< GPIO pull-up                                         */
    // gpio_pulldown_t pull_down_en;   /*!< GPIO pull-down                                       */
    // gpio_int_type_t intr_type;      /*!< GPIO interrupt type                                  */

}