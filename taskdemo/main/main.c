#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void pressure_task(void *data)
{
printf("Pressure task created\n");
vTaskDelete(NULL);
}
void app_main(void)
{
    int i = 0;
    xTaskCreate(pressure_task, "press_tsk", 2048, NULL, 3, NULL);
    while (1) {
        printf("[%d] Hello world!\n", i);
        i++;
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
