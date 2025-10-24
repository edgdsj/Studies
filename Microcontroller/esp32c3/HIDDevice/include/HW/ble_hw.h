#ifndef BLE_HW_H
#define BLE_HW_H

#include "esp_system.h"
#include "esp_log.h"

#include "nvs_flash.h"
#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_bt.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gatt_common_api.h"

static const char *GATTS_TAG = "GATTS_DEMO";

bool init_ble(void);

#endif // BLE_HW_H 