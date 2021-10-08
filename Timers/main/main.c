#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timer.h"

TimerHandle_t pt_handle;

void *const pt_timerid;

void pressure_task(void *data)
{
xTimerStart(pt_handle,0);
while(1)
{
printf("Pressure Started\n");
pt_handle = xTimerCreate("pt_timer", pdMS_TO_TICKS(1500), pdTRUE, &pt_timerid, pt_timer_handler);
printf("Pressure Ended\n");
vTaskDelay(1000 / portTICK_PERIOD_MS);
}
}

void pt_timer_handler(TimerHandle_t xTimer)
{
printf("Timer Fired\n");
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
