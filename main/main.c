#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"
#include "esp_log.h"

#include "pins.h"
#include "spi_mod.h"

#define TAG "main"

void temp_task(void * pvParams) {
  spi_device_handle_t spi = (spi_device_handle_t) pvParams;

  uint16_t data;
  spi_transaction_t tM = {
    .tx_buffer = NULL,
    .rx_buffer = &data,
    .length = 16,
    .rxlength = 16,
  };

  for (;;) {
    spi_device_acquire_bus(spi, portMAX_DELAY);
    spi_device_transmit(spi, &tM);
    spi_device_release_bus(spi);

    uint16_t res = SPI_SWAP_DATA_RX(data, 16);


    if (res & (1 << 14))
      ESP_LOGE(TAG, "Sensor is not connected\n");
    else {
      res >>= 3;
      printf("SPI res = %d temp=%f\n", res, res * 0.25);
    }

    vTaskDelay(pdMS_TO_TICKS(1000));
  }


void app_main()
{
  spi_device_handle_t spi;
  spi = spi_init();

  xTaskCreate(&temp_task, "temperature_task", 4096, spi, 5, NULL);
}
