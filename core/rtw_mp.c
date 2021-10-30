/******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 *****************************************************************************/
#define _RTW_MP_C_
#include <drv_types.h>

#include "../hal/phydm/phydm_precomp.h"
#if defined(CONFIG_RTL8723B) || defined(CONFIG_RTL8821A)
	#include <rtw_bt_mp.h>
#endif

#ifdef CONFIG_MP_VHT_HW_TX_MODE
#define CEILING_POS(X) ((X - (int)(X)) > 0 ? (int)(X + 1) : (int)(X))
#define CEILING_NEG(X) ((X - (int)(X)) < 0 ? (int)(X - 1) : (int)(X))
#define ceil(X) (((X) > 0) ? CEILING_POS(X) : CEILING_NEG(X))

int rtfloor(float x)
{
	int i = x - 2;
	while
	(++i <= x - 1)
		;
	return i;
}
#endif

