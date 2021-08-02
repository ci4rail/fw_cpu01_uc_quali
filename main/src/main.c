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
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "ota_server.h"
#include "com_test.h"

bool diagnostic_cb(void)
{
    /* signal that everything is okay */
    return true;
}

void app_main(void)
{
    /* initialize ota update */
    init_ota();

    com1_test_start();

    for(;;){
        ESP_LOGI("main", "Alive");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
