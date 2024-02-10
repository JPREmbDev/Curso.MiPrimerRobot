#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"



extern "C" void app_main();

// #define LED_PIN GPIO_NUM_2
// #define BUTTON GPIO_NUM_17
constexpr gpio_num_t LED_PIN = GPIO_NUM_2;
constexpr gpio_num_t BUTTON  = GPIO_NUM_4;

void app_main()
{


    // Config Ejercicio Tema 4
    // Suponiendo  que el led azul caen 2Vm y que queremos que pasen 2mA
    // Que R necesitamos:
    // V = R*I -> Vesp=3.3A; 2 = R * 2mA ----> R = (3.3-2)V/(2mA)
    // R = 650 ~ 680 Ohmios 
    // Setup
    // Creamos la estructura con la configuración
    gpio_config_t config;
    config.mode = GPIO_MODE_OUTPUT;
    config.pin_bit_mask = (1<<LED_PIN);
    config.intr_type = GPIO_INTR_DISABLE;
    config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    config.pull_up_en = GPIO_PULLUP_DISABLE;
    // Enviamos la estructura con la configuración del LED
    gpio_config(&config);
    // Hacemos la configuración del Pulsador:
    config.mode = GPIO_MODE_INPUT;
    config.pin_bit_mask = (1<<BUTTON);
    config.pull_down_en = GPIO_PULLDOWN_ENABLE;
    // Envamos la configuración del Pulsador:
    gpio_config(&config);




    // // Setup:
    // // _t -> estructura o tipo
    // // Define la variable config con el tipo gpio_config()
    // gpio_config_t config;
    // // // Modo de funcionamiento
    // config.mode = GPIO_MODE_OUTPUT;
    // // // GPIO pin: set with bit mask, each bit maps to a GPIO
    // // // Movemos 1 en el pin 2 para así configurar el pin que queremos
    // config.pin_bit_mask = (1<<LED_PIN);
    // // // GPIO interrupt type    
    // // // Para este ejemplo lo tendremos deshabilitado
    // config.intr_type = GPIO_INTR_DISABLE;
    // config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    // config.pull_up_en = GPIO_PULLUP_DISABLE;


    // //config.

    // // // Mandamos la configuración
    // gpio_config(&config);



    // // La siguiente linea de codigo config. el GPIO2 (led0) como salida
    // gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    // gpio_set_direction(BUTTON, GPIO_MODE_INPUT);

    // // Necesitaremos una resistencia de PULL-DOWN
    // // Nuestro ESP32 tiene una resistencia de PULL-DOWN Y PULL-UP configurables por SOFTWARE
    // gpio_set_pull_mode(BUTTON, GPIO_PULLDOWN_ONLY);


    while(1)
    {
        // Para leer el estado de nuestro PULSADOR usaremos get_level:
        // int gpio_get_level(gpio_num_t gpio_num)
        // gpio_num -> numero del PIN que queremos leer:
        // devuelve un INT -> necesitamos una variable que almacene este valor:
        int state_bt = gpio_get_level(BUTTON);

        if(state_bt)
        {
            gpio_set_level(LED_PIN, 1);
        }
        else
        {
            gpio_set_level(LED_PIN, 0);
        } 

        vTaskDelay(pdMS_TO_TICKS(200));



        // led0 1 ENCENDIDO, 0 APAGADO
        // esp_err_t gpio_set_level(gpio_num_t gpio_num, uint32_t level)
        // gpio_num -> numero del PIN
        // level    -> Alto o bajo
        // gpio_set_level(LED_PIN, 1);

        // // //DELAY -> en milisegundos -> 0,5 s
        // // vTaskDelay(500/portTICK_PERIOD_MS);

        // vTaskDelay(pdMS_TO_TICKS(1000));

        // //led0 1 ENCENDIDO, 0 APAGADO
        // gpio_set_level(LED_PIN, 0);

        // //DELAY -> en milisegundos -> 0,5 s
        //  vTaskDelay(pdMS_TO_TICKS(1000));
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