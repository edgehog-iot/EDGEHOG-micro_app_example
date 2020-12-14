idf_component_register(INCLUDE_DIRS "include")

add_prebuilt_library(edgehog_micro "libedgehog_micro.a" REQUIRES nvs_flash mbedtls bt protocomm wifi_provisioning app_update mqtt json esp_https_ota driver protobuf-c)

target_link_libraries(${COMPONENT_LIB} INTERFACE edgehog_micro)
