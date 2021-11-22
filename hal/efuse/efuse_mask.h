/******************************************************************************
 *
 * Copyright(c) 2016 - 2017 Realtek Corporation.
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

#ifdef CONFIG_USB_HCI

	#if defined(CONFIG_RTL8812A)
		#include "rtl8812a/HalEfuseMask8812A_USB.h"
	#endif

	#if defined(CONFIG_RTL8821A)
		#include "rtl8812a/HalEfuseMask8821A_USB.h"
	#endif

	#if defined(CONFIG_RTL8814A)
		#include "rtl8814a/HalEfuseMask8814A_USB.h"
	#endif

	#if defined(CONFIG_RTL8822B)
		#include "rtl8822b/HalEfuseMask8822B_USB.h"
	#endif

	#if defined(CONFIG_RTL8821C)
		#include "rtl8821c/HalEfuseMask8821C_USB.h"
	#endif
	
	#if defined(CONFIG_RTL8822C)
		#include "rtl8822c/HalEfuseMask8822C_USB.h"
	#endif
	#if defined(CONFIG_RTL8814B)
		#include "rtl8814b/HalEfuseMask8814B_USB.h"
	#endif
#endif /*CONFIG_USB_HCI*/

#ifdef CONFIG_SDIO_HCI
	#if defined(CONFIG_RTL8821A)
		#include "rtl8812a/HalEfuseMask8821A_SDIO.h"
	#endif

	#if defined(CONFIG_RTL8821C)
		#include "rtl8821c/HalEfuseMask8821C_SDIO.h"
	#endif

	#if defined(CONFIG_RTL8822B)
		#include "rtl8822b/HalEfuseMask8822B_SDIO.h"
	#endif

	#if defined(CONFIG_RTL8822C)
		#include "rtl8822c/HalEfuseMask8822C_SDIO.h"
	#endif

#endif /*CONFIG_SDIO_HCI*/
