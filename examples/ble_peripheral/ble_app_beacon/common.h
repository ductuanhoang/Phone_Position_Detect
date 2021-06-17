#ifndef __common_h__
#define __common_h__

#ifdef __cplusplus9
extern "C" {
#endif

#include "nrf52.h"
#include "nrf_gpio.h"
#include "sdk_common.h"
#include "nrfx_gpiote.h"
#include "nrf_drv_gpiote.h"

#define BUCK_ENABLE  1
#define BUCK_DISABLE 0

#define TX_POWER_MAX    (4)
#define TX_POWER_HIGH   (3)
#define TX_POWER_MEDIUM (0)
#define TX_POWER_LOW    (-4)
#define TX_POWER_MIN    (-40)

void nRF52_GetMACAddr(uint8_t _macAddr[]);
void nRF52_GetMACString(char _macAddr[]);
void nRF52_SetTXPower(int8_t txPower);
void nRF52_GPIO_InterruptInit(uint8_t _buttonPin, nrfx_gpiote_evt_handler_t evt_handler);
void nRF52_BuckPowerFunc(uint8_t _buckAction);

#ifdef __cplusplus
}
#endif

#endif

