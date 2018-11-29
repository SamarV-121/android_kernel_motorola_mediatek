/*
* Copyright (C) 2016 MediaTek Inc.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See http://www.gnu.org/licenses/gpl-2.0.html for more details.
*/

#ifndef _KD_CAMERA_HW_H_
#define _KD_CAMERA_HW_H_

#include <linux/types.h>
#include "kd_camera_typedef.h"

#define VOL2800 2800000
#define VOL1800 1800000
#define VOL1500 1500000
#define VOL1200 1200000
#define VOL1210 1210000
#define VOL1220 1220000
#define VOL1000 1000000
#define VOL1100 1100000

typedef enum {
	VDD_None,
	PDN,
	RST,
	SensorMCLK,
	AVDD,
	DVDD,
	DOVDD,
	AFVDD,
	SUB_AVDD,
	SUB_DVDD,
	SUB_DOVDD,
	MAIN2_AVDD,
	MAIN2_DVDD,
	MAIN2_DOVDD,
} PowerType;

typedef enum {
	Vol_Low = 0,
	Vol_High = 1,
	Vol_1000 = VOL1000,
	Vol_1100 = VOL1100,
	Vol_1200 = VOL1200,
	Vol_1210 = VOL1210,
	Vol_1220 = VOL1220,
	Vol_1500 = VOL1500,
	Vol_1800 = VOL1800,
	Vol_2800 = VOL2800,
} Voltage;
#define CAMERA_CMRST_PIN            0
#define CAMERA_CMRST_PIN_M_GPIO     0

#define CAMERA_CMPDN_PIN            0
#define CAMERA_CMPDN_PIN_M_GPIO     0

/* FRONT sensor */
#define CAMERA_CMRST1_PIN           0
#define CAMERA_CMRST1_PIN_M_GPIO    0

#define CAMERA_CMPDN1_PIN           0
#define CAMERA_CMPDN1_PIN_M_GPIO    0

#if 0//defined CONFIG_MTK_LEGACY
#include <mach/mt_gpio.h>
#include <mach/mt_pm_ldo.h>
#include "pmic_drv.h"
/*  */
/* Analog */
#define CAMERA_POWER_VCAM_A         PMIC_APP_MAIN_CAMERA_POWER_A
/* Digital */
#define CAMERA_POWER_VCAM_D         PMIC_APP_MAIN_CAMERA_POWER_D
/* AF */
#define CAMERA_POWER_VCAM_AF        PMIC_APP_MAIN_CAMERA_POWER_AF
/* digital io */
#define CAMERA_POWER_VCAM_IO        PMIC_APP_MAIN_CAMERA_POWER_IO
/* Digital for Sub */
#define SUB_CAMERA_POWER_VCAM_D     PMIC_APP_SUB_CAMERA_POWER_D


/* FIXME, should defined in DCT tool */

/* Main sensor */
    /* Common phone's reset pin uses extension GPIO10 of mt6306 */
    #define CAMERA_CMRST_PIN            GPIO_CAMERA_CMRST_PIN
    #define CAMERA_CMRST_PIN_M_GPIO     GPIO_CAMERA_CMRST_PIN_M_GPIO


#define CAMERA_CMPDN_PIN            GPIO_CAMERA_CMPDN_PIN
#define CAMERA_CMPDN_PIN_M_GPIO     GPIO_CAMERA_CMPDN_PIN_M_GPIO

/* FRONT sensor */
#define CAMERA_CMRST1_PIN           GPIO_CAMERA_CMRST1_PIN
#define CAMERA_CMRST1_PIN_M_GPIO    GPIO_CAMERA_CMRST1_PIN_M_GPIO

#define CAMERA_CMPDN1_PIN           GPIO_CAMERA_CMPDN1_PIN
#define CAMERA_CMPDN1_PIN_M_GPIO    GPIO_CAMERA_CMPDN1_PIN_M_GPIO

/* Define I2C Bus Num */
#define SUPPORT_I2C_BUS_NUM1        0
#define SUPPORT_I2C_BUS_NUM2        0
#else
/* Main2 sensor */
#define CAMERA_CMRST2_PIN           0
#define CAMERA_CMRST2_PIN_M_GPIO    0

#define CAMERA_CMPDN2_PIN           0
#define CAMERA_CMPDN2_PIN_M_GPIO    0


#define GPIO_OUT_ONE 1
#define GPIO_OUT_ZERO 0
#define GPIO_UNSUPPORTED 0xff
#define GPIO_SUPPORTED 0
#define GPIO_MODE_GPIO 0

int mtkcam_gpio_set(int PinIdx, int PwrType, int Val);
int mtkcam_gpio_init(struct platform_device *pdev);

#endif /* End of #if defined CONFIG_MTK_LEGACY */

typedef struct {
	PowerType PowerType;
	Voltage Voltage;
	u32 Delay;
} PowerInformation;


typedef struct {
	char *SensorName;
	PowerInformation PowerInfo[12];
} PowerSequence;

typedef struct {
	PowerSequence PowerSeq[16];
} PowerUp;

typedef struct {
	u32 Gpio_Pin;
	u32 Gpio_Mode;
	Voltage Voltage;
} PowerCustInfo;

typedef struct {
	PowerCustInfo PowerCustInfo[10];
} PowerCust;

typedef enum KD_REGULATOR_TYPE_TAG {
	VCAMA,
	VCAMD,
	VCAMIO,
	VCAMAF,
	SUB_VCAMD,
} KD_REGULATOR_TYPE_T;

typedef enum {
	CAMPDN,
	CAMRST,
	CAM1PDN,
	CAM1RST,
	CAMLDO
} CAMPowerType;

extern bool _hwPowerDown(PowerType type);
extern bool _hwPowerOn(PowerType type, int powerVolt);

extern void ISP_MCLK1_EN(BOOL En);
extern void ISP_MCLK2_EN(BOOL En);

int mtkcam_gpio_set(int PinIdx, int PwrType, int Val);
int mtkcam_gpio_init(struct platform_device *pdev);

#endif
