# max6675-esp-idf
An example of how to use esp-idf to read a MAX6675 temprature sensor

## Motivation

It is hard to get an example of a raw SPI device on internet using Espressif esp-idf, so I made this version which works as expected. Please, fell fre to add comments or suggestions.

## Pins map:

| ESP32 | MAX6675 |
|-------+---------|
|    19 | SO      |
|    23 | NC      |
|    18 | SCK     |
|    25 | CS      |


## Compatibilty

The code was tested only is ESP32. For ESP32-S2, ESP32-C3, etc., the code must be adapted.

