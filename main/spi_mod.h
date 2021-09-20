#ifndef _spi_mod_h
#define _spi_mod_h

#define DMA_CHAN    2

#define PIN_NUM_MISO 19
#define PIN_NUM_MOSI 23
#define PIN_NUM_CLK  18
#define PIN_NUM_CS   25

#define PIN_NUM_DC   4
#define PIN_NUM_RST  5
#define PIN_NUM_BCKL 6

spi_device_handle_t spi_init(void);

#endif
