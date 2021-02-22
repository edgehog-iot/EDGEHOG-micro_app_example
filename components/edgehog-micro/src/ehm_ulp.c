#include "ehm_ulp.h"
#include "ulp_edgehog-micro.h"

extern const uint8_t ulp_main_bin_start[] asm("_binary_ulp_edgehog_micro_bin_start");
extern const uint8_t ulp_main_bin_end[]   asm("_binary_ulp_edgehog_micro_bin_end");

/**
 * @brief Inits ULP for battery monitoring
 */
void init_ulp(){
    esp_err_t err = ulp_load_binary(0, ulp_main_bin_start,
            (ulp_main_bin_end - ulp_main_bin_start) / sizeof(uint32_t));
    ESP_ERROR_CHECK(err);

    adc1_ulp_enable();
    ulp_high_thr = 2800;
    ulp_set_wakeup_period(0, 20000);
    ESP_ERROR_CHECK(esp_sleep_enable_ulp_wakeup());
} 

/**
 * @brief Runs ULP battery monitoring program
 */
void start_ulp(){
    /* Reset sample counter */
    ulp_sample_counter = 0;

    /* Start the program */
    esp_err_t err = ulp_run(&ulp_entry - RTC_SLOW_MEM);
    ESP_ERROR_CHECK(err);
}