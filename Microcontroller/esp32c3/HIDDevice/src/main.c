#include <driver/gpio.h>
#include "driver/uart.h"

#include "esp_system.h"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "string.h"

#include "HW/ble_hw.h"
#include "HW/gap.h"


#define GPIO_OUTPUT_IO_0     (GPIO_NUM_8)
#define GPIO_OUTPUT_PIN_SEL  ((1ULL<<GPIO_OUTPUT_IO_0))
#define TXD_PIN              (GPIO_NUM_21)
#define RXD_PIN              (GPIO_NUM_20)

static const int RX_BUF_SIZE = 1024;

void init(void){
    const uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };
    // We won't use a buffer for sending data.
    uart_driver_install(UART_NUM_1, RX_BUF_SIZE * 2, 0, 0, NULL, 0);
    uart_param_config(UART_NUM_1, &uart_config);
    uart_set_pin(UART_NUM_1, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}

void init_gpio(void) {
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);
}

int sendData(const char* logName, const char* data)
{
    const int len = strlen(data);
    const int txBytes = uart_write_bytes(UART_NUM_1, data, len);
    ESP_LOGI(logName, "Wrote %d bytes", txBytes);
    return txBytes;
}

static void tx_task(void *arg)
{
    static const char *TX_TASK_TAG = "TX_TASK";
    esp_log_level_set(TX_TASK_TAG, ESP_LOG_INFO);
    while (1) {
        ESP_LOGE(TX_TASK_TAG, "Hello world");
        sendData(TX_TASK_TAG, "Hello world\n");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

static void rx_task(void *arg)
{
    static const char *RX_TASK_TAG = "RX_TASK";
    esp_log_level_set(RX_TASK_TAG, ESP_LOG_INFO);
    uint8_t* data = (uint8_t*) malloc(RX_BUF_SIZE + 1);
    while (1) {
        const int rxBytes = uart_read_bytes(UART_NUM_1, data, RX_BUF_SIZE, 1000 / portTICK_PERIOD_MS);
        if (rxBytes > 0) {
            data[rxBytes] = 0;
            ESP_LOGI(RX_TASK_TAG, "Read %d bytes: '%s'", rxBytes, data);
            ESP_LOG_BUFFER_HEXDUMP(RX_TASK_TAG, data, rxBytes, ESP_LOG_INFO);
        }
    }
    free(data);
}

void blink_task(void *pvParameter)
{
    while (1) {
        gpio_set_level(GPIO_OUTPUT_IO_0, 1); // Set GPIO high
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
        gpio_set_level(GPIO_OUTPUT_IO_0, 0); // Set GPIO low
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
    }
}

void app_main(void){
    init();
    init_gpio();
    if (!init_ble()) {
        ESP_LOGE(GATTS_TAG, "BLE initialization failed");
        return;
    }

    xTaskCreate(&blink_task, "blink_task", 2048, NULL, 5, NULL);
    xTaskCreate(&tx_task, "tx_task", 2048, NULL, 5, NULL);
    xTaskCreate(&rx_task, "rx_task", 2048, NULL, 5, NULL);


}