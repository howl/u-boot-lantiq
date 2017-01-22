/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/lantiq/io.h>
#include <asm/arch/soc.h>
#include <asm/arch/gphy.h>

static inline void ltq_gphy_copy(const void *fw_start, const void *fw_end,
				ulong dst_addr)
{
	const ulong fw_len = (ulong) fw_end - (ulong) fw_start;
	const ulong addr = CKSEG1ADDR(dst_addr);

	debug("ltq_gphy_copy: addr %08lx, fw_start %p, fw_end %p\n",
		addr, fw_start, fw_end);

	memcpy((void *) addr, fw_start, fw_len);
}

void ltq_gphy_phy11g_a1x_load(ulong addr)
{
	extern ulong __ltq_fw_phy11g_a1x_start;
	extern ulong __ltq_fw_phy11g_a1x_end;

	ltq_gphy_copy(&__ltq_fw_phy11g_a1x_start, &__ltq_fw_phy11g_a1x_end,
			addr);
}

void ltq_gphy_phy11g_a2x_load(ulong addr)
{
	extern ulong __ltq_fw_phy11g_a2x_start;
	extern ulong __ltq_fw_phy11g_a2x_end;

	ltq_gphy_copy(&__ltq_fw_phy11g_a2x_start, &__ltq_fw_phy11g_a2x_end,
			addr);
}

void ltq_gphy_phy22f_a1x_load(ulong addr)
{
	extern ulong __ltq_fw_phy22f_a1x_start;
	extern ulong __ltq_fw_phy22f_a1x_end;

	ltq_gphy_copy(&__ltq_fw_phy22f_a1x_start, &__ltq_fw_phy22f_a1x_end,
			addr);
}

void ltq_gphy_phy22f_a2x_load(ulong addr)
{
	extern ulong __ltq_fw_phy22f_a2x_start;
	extern ulong __ltq_fw_phy22f_a2x_end;

	ltq_gphy_copy(&__ltq_fw_phy22f_a2x_start, &__ltq_fw_phy22f_a2x_end,
			addr);
}
