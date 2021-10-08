#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t pressure_handler;
TaskHandle_t temperature_handler;

void pressure_task(void *data)
{
while(1)
{
printf("Pressure task started\n");
//--------
printf("pressure task ended\n");
vTaskDelay(2000 / portTICK_PERIOD_MS);
}
}

void temperature_task(void *data)
{
while(1)
{
printf("temperature task started\n");
//--------
printf("temperature task ended\n");
vTaskDelay(3000 / portTICK_PERIOD_MS);
vTaskDelete(NULL);
}
}

void app_main(void)
{
    int i = 0;
    xTaskCreate(pressure_task, "press_tsk", 2048, NULL, 3, &pressure_handler);
    xTaskCreate(temperature_task, "temp_tsk", 2048, NULL, 3, &temperature_handler);
    while (1) {
        printf("[%d] Hello world!\n", i);
        i++;
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
