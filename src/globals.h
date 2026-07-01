#pragma once

// ================== PINS ==================

// Cap LoRa-1262 IO expander, audio codec (ES8311), keyboard (TCA8418)
#define PIN_I2C_INTERNAL_SDA                     8
#define PIN_I2C_INTERNAL_SCL                     9

// Cap LoRa-1262 IO expander
#define LORA_IOE_I2C_ADDRESS                     0x43

// LCD (ST7789V2)
#define TFT_SPI_HOST                             SPI3_HOST
#define PIN_TFT_SCK                              36
#define PIN_TFT_MOSI                             35
#define PIN_TFT_RST                              33
#define PIN_TFT_DC                               34
#define PIN_TFT_CS                               37
#define PIN_TFT_BL                               38

// Audio codec (ES8311)
#define AUDIO_I2C_ADDRESS                        0x18
#define PIN_AUDIO_SCLK                           41
#define PIN_AUDIO_ASDOUT                         46
#define PIN_AUDIO_LRCK                           43
#define PIN_AUDIO_DSDIN                          42
#define AUDIO_SAMPLE_RATE                        16000
#define AUDIO_MAX_SAFE_VOLUME                    28000.0f
#define AUDIO_BUFFER_SIZE                        256

// Keyboard (TCA8418)
#define KEYBOARD_I2C_ADDRESS                     0x34
#define PIN_KEYBOARD_INT                         11
