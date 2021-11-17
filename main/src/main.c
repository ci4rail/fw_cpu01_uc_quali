/*
Copyright © 2021 Ci4Rail GmbH
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
 http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include "com_test.h"
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "io4edge_core.h"

static char* TAG = "main";

// example hostname
static const char* hostname = "ESP32S2";
// example default instance name
static const char* instance = "cpu01uc-usb_io_ctrl";

static bool application_is_working(void)
{
    ESP_LOGI(TAG, "application_is_working called");
    return true;
}

void app_main(void)
{
    static io4edge_core_config_t io4edge_core_config = {
        .core_server_priority = 5, .application_is_working = application_is_working};

    ESP_ERROR_CHECK(io4edge_new_esp_nvs_hw_inventory(&io4edge_core_config.hw_inventory_provider));
    ESP_ERROR_CHECK(io4edge_core_init(hostname, instance));

    com1_test_start();

    ESP_ERROR_CHECK(io4edge_core_start(&io4edge_core_config));

    for (;;) {
        ESP_LOGI(TAG, "Alive");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
