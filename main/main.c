#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
#include "esp_system.h"
#include "esp_err.h"


#define DO_GPIO GPIO_NUM_10
#define LED_PIN GPIO_NUM_2
int state = 0;
QueueHandle_t interputQueue;

const char *TAG = "GPIO Interrupt Example";
static void IRAM_ATTR gpio_interrupt_handler(void *args)
{
    int pinNumber = (int)args;
    xQueueSendFromISR(interputQueue, &pinNumber, NULL);
}

void SensorTask(void *arg)
{
    int pinNumber, count = 0;
    while (true)
    {
        if (xQueueReceive(interputQueue, &pinNumber, portMAX_DELAY))
        {
            ESP_LOGI(TAG,"GPIO %d was pressed %d times. The state is %d\n", pinNumber, count++, gpio_get_level(DO_GPIO));
            gpio_set_level(LED_PIN, gpio_get_level(DO_GPIO));
        }
    }
}

void app_main(void)
{
    gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    gpio_pad_select_gpio(DO_GPIO);
    gpio_set_direction(DO_GPIO, GPIO_MODE_INPUT);
    gpio_pulldown_en(DO_GPIO);
    gpio_pullup_dis(DO_GPIO);
    gpio_set_intr_type(DO_GPIO, GPIO_INTR_POSEDGE);

    interputQueue = xQueueCreate(10, sizeof(int));
    xTaskCreate(SensorTask, "Sensor_Task", 2048, NULL, 1, NULL);

    gpio_install_isr_service(0);
    gpio_isr_handler_add(DO_GPIO, gpio_interrupt_handler, (void *)DO_GPIO);
}
