/**
 * @file edgehog_micro.h
 * @author Riccardo Mereu
 * @copyright SECO S.p.A
 * @date 11 Dec 2020
 * @brief File holding EDGEHO-micro core header.
 */

#pragma once

#include <esp_log.h>
#include "freertos/FreeRTOS.h"
#include <freertos/task.h>

#define EDGEHOG_GPIO 32
#define POWER_OUT_ENABLE_GPIO 25
#define GPIO_EDGE_OUTPUT_PIN_SEL  ((1ULL<<EDGEHOG_GPIO) | (1ULL<<POWER_OUT_ENABLE_GPIO))

typedef void (*func_void_ptr)(void);

void on_ready_task();

/**
 * @brief Init function for EDGEHOG-micro firmware
 * 
 * After performing init procedure for modem, WiFi, mqtt and, if needed, BLE 
 * it starts the loop given by the user.
 * 
 * @param app_start_cb[in] the user function called in loop.
 * @param company_name[in] the user company name, if NULL default is "seco".
 */
void init_edgehog(func_void_ptr app_start_cb, const char* company_name);