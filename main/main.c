#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

#include "edgehog_micro.h"

static void my_main(void);

void app_main(void){
    init_edgehog(my_main, "my_company");
}

void my_main(void){
    while(true){
        esp_chip_info_t chip_info;
        esp_chip_info(&chip_info);
        printf("This is SENSE-D47 with %d CPU cores, WiFi%s%s, ",
                chip_info.cores,
                (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
                (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

        printf("silicon revision %d, ", chip_info.revision);

        printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
                (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

        printf("Minimum free heap size: %d bytes\n", esp_get_minimum_free_heap_size());

        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}