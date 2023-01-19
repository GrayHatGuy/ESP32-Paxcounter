#ifndef __LORACONF_H__
#define __LORACONF_H__

#if (HAS_LORA)

/************************************************************
 * LMIC LoRaWAN configuration
 *
 * Read the values from TTN console (or whatever applies), insert them here,
 * and rename this file to src/loraconf.h
 *
 * You can configure OTAA or ABP Activation. In order to use ABP, uncomment
 * (enable) the following line, but you should only do so, if you have good 
 * reasons for not using OTAA.
 * 
 *************************************************************/

//#define LORA_ABP

#ifndef LORA_ABP
/************************************************************
 * OTAA configuration
 * 
 * DEVEUI, APPEUI and APPKEY should all be specified in MSB format as 
 * displayed in TTN console, so you can cut & paste from there. This is different
 * from standard LMIC-Arduino which expects DEVEUI and APPEUI in LSB format.
 * For TTN, APPEUI in MSB format always starts with 0x70, 0xB3, 0xD5.
 * Set your DEVEUI here, if your device has have a fixed one. 
 * If you leave this untouched, then the DEVEUI will be derived from device's 
 * MAC adress during startup and will be displayed on device's screen as well as
 * on serial console, if you set 'verbose 1' in paxcounter.conf and 
 * 'debug_level 3' in platformio.ini.
 * If using a board with Microchip 24AA02E64 Uinique ID for deveui, the DEVEUI 
 * will be overwritten by the one contained in the Microchip module.
 *
 ************************************************************/

static const u1_t DEVEUI[8] = {0x60, 0x81, 0xF9, 0xC1, 0x37, 0xE7, 0xC0, 0x06};

static const u1_t APPEUI[8] = {0x60, 0x81, 0xF9, 0xBB, 0xA4, 0x6D, 0xB3, 0x53};

static const u1_t APPKEY[16] = {0xAC, 0xA5, 0xCB, 0xD3, 0x34, 0x51, 0x26, 0x8B, 
                                0x1F, 0xEE, 0xC0, 0xDD, 0xC2, 0x0F, 0x2F, 0x26};

#endif

#ifdef LORA_ABP
/************************************************************
 * ABP configuration (for development)
 *
 * Get your
 *   - Network Session Key (NWKSKEY)
 *   - App Session Key and your (APPSKEY)
 *   - Device Address (DEVADDR)
 * from e.g. TTN console and replace the example values below.
 * 
 * NOTE: Use MSB format (as displayed in TTN console, so you can cut & paste
 * from there)
 *
 * NOTE: You may also need to adjust lorawan_abp.cpp in order to configure
 * different channels and data rate channels to match your country's regulations
 * and your network's settings.
 * 
 ************************************************************/

// ID of LoRaAlliance assigned Network (for a list, see e.g. here
// https://www.thethingsnetwork.org/docs/lorawan/prefix-assignments.html)
static const u1_t NETID = 0x13; // TTN

static const u1_t NWKSKEY[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00};

static const u1_t APPSKEY[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00};

static const u4_t DEVADDR =
    0x00000000; // <-- Change this address for every node!

// set additional ABP parameters in loraconf_abp.cpp
void setABPParameters();

#endif

#endif // HAS_LORA

#endif // __LORACONF_H__
