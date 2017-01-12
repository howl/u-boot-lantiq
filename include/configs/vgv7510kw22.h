/*
 * Copyright (C) 2015 Martin Blumenstingl <martin.blumenstingl@googlemail.com>
 * Copyright (C) 2016 Mathias Kresin <dev@kresin.me>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MACH_TYPE	"VGV7510KW22"
#define CONFIG_IDENT_STRING	" "CONFIG_MACH_TYPE
#define CONFIG_BOARD_NAME	"Arcadyan VGV7510KW22"

/* Configure SoC */
#define CONFIG_LTQ_SUPPORT_UART			/* Enable ASC and UART */

#define CONFIG_LTQ_SUPPORT_ETHERNET		/* Enable ethernet */

#define CONFIG_LTQ_SUPPORT_NOR_FLASH		/* Have a parallel NOR flash */

#define CONFIG_LTQ_SUPPORT_SPL_NOR_FLASH	/* Build NOR flash SPL */

#define CONFIG_LTQ_SPL_CONSOLE
#define CONFIG_LTQ_SPL_COMP_LZO

#define CONFIG_LTQ_SPL_MC_TUNE

#define CONFIG_SYS_BOOTM_LEN		0x1000000	/* 16 MB */

/* Environment */
#if defined(CONFIG_SYS_BOOT_BRN)
#define CONFIG_SYS_TEXT_BASE		0x80002000
#define CONFIG_SKIP_LOWLEVEL_INIT
#define CONFIG_SYS_DISABLE_CACHE
#define CONFIG_ENV_IS_NOWHERE
#elif defined(CONFIG_SYS_BOOT_NOR)
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(384 * 1024)
#define CONFIG_ENV_SECT_SIZE		(128 * 1024)
#elif defined(CONFIG_SYS_BOOT_NORSPL)
#define CONFIG_SPL_TPL_OFFS		0x800
#define CONFIG_SPL_TPL_SIZE		0x5000
#define CONFIG_SPL_MC_TUNE_OFFS		0x5800
#define CONFIG_SPL_U_BOOT_OFFS		0x6000
#define CONFIG_SPL_U_BOOT_SIZE		0x32000

#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(256 * 1024)
#define CONFIG_ENV_SECT_SIZE		(128 * 1024)
#else
#define CONFIG_ENV_IS_NOWHERE
#endif

#define CONFIG_ENV_SIZE			(128 * 1024)

#define CONFIG_LOADADDR			CONFIG_SYS_LOAD_ADDR

/* Console */
#define CONFIG_LTQ_ADVANCED_CONSOLE
#define CONFIG_BAUDRATE			115200
#define CONFIG_CONSOLE_ASC		1

/* Pull in default board configs for Lantiq XWAY VRX200 */
#include <asm/lantiq/config.h>
#include <asm/arch/config.h>

/* Pull in default OpenWrt configs for Lantiq SoC */
#include "openwrt-lantiq-common.h"

#define CONFIG_EXTRA_ENV_SETTINGS	\
	CONFIG_ENV_LANTIQ_DEFAULTS	\
	"kernel_addr=0xB0080000\0"

#endif /* __CONFIG_H */
