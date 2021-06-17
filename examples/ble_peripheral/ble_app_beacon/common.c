#include "nordic_common.h"
#include "bsp.h"
#include "nrf_soc.h"
#include "nrf_sdh.h"
#include "nrf_sdh_ble.h"
#include "ble_advdata.h"
#include "common.h"
#include "ble_gap.h"
#include "nrf_gpio.h"
#include "sdk_common.h"

void nRF52_GetMACAddr(uint8_t _macAddr[])
{
	// NRF_FICR->DEVICEADDR[1] is MSB MAC Addressfeq 
	// NRF_FICR->DEVICEADDR[0] is LSB MAC Address 
	memset(_macAddr, 0, 8);
	
	_macAddr[0] = (uint8_t)(NRF_FICR->DEVICEADDR[1] >> 24) ;
	_macAddr[1] = (uint8_t)(NRF_FICR->DEVICEADDR[1] >> 16) ;
	_macAddr[2] = (uint8_t)(NRF_FICR->DEVICEADDR[1] >> 8) ;
	_macAddr[3] = (uint8_t)(NRF_FICR->DEVICEADDR[1] );
	_macAddr[4] = (uint8_t)(NRF_FICR->DEVICEADDR[0] >> 24) ;
	_macAddr[5] = (uint8_t)(NRF_FICR->DEVICEADDR[0] >> 16) ;
	_macAddr[6] = (uint8_t)(NRF_FICR->DEVICEADDR[0] >> 8) ;
	_macAddr[7] = (uint8_t)(NRF_FICR->DEVICEADDR[0] );

}

void nRF52_GetMACString(char _macAddr[])
{
	char _MAC_MSB[10] = {0}, _MAC_LSB[10] = {0};

	snprintf(_MAC_MSB, 10, "%u", (uint32_t)NRF_FICR->DEVICEADDR[1]);
	snprintf(_MAC_LSB, 10, "%u", (uint32_t)NRF_FICR->DEVICEADDR[0]);
	
	strcpy(_macAddr, _MAC_MSB);
	strcat(_macAddr, _MAC_LSB);
}



void nRF52_SetTXPower(int8_t txPower)
{
	sd_ble_gap_tx_power_set(BLE_GAP_TX_POWER_ROLE_ADV, BLE_GAP_TX_POWER_ROLE_ADV, txPower);
}

void nRF52_GPIO_InterruptInit(uint8_t _buttonPin, nrfx_gpiote_evt_handler_t evt_handler)
{
	nrf_drv_gpiote_init();
	nrf_drv_gpiote_in_config_t in_config = GPIOTE_CONFIG_IN_SENSE_TOGGLE(true);
  	in_config.pull = NRF_GPIO_PIN_NOPULL;
	
	nrf_drv_gpiote_in_init(_buttonPin, &in_config, evt_handler);
	nrf_drv_gpiote_in_event_enable(_buttonPin, true);
}

void nRF52_BuckPowerFunc(uint8_t _buckAction)
{
	//NRF_POWER->DCDCEN = _buckAction;
	sd_power_dcdc_mode_set(_buckAction);
}

