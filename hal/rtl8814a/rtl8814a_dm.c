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
/* ************************************************************
 * Description:
 *
 * This file is for 92CE/92CU dynamic mechanism only
 *
 *
 * ************************************************************ */
#define _RTL8814A_DM_C_

/* ************************************************************
 * include files
 * ************************************************************
 * #include <drv_types.h> */
#include <rtl8814a_hal.h>

/* ************************************************************
 * Global var
 * ************************************************************ */
#ifdef CONFIG_SUPPORT_HW_WPS_PBC
static void dm_CheckPbcGPIO(_adapter *padapter)
{
	u8	tmp1byte;
	u8	bPbcPressed = _FALSE;

	if (!padapter->registrypriv.hw_wps_pbc)
		return;

#if defined(CONFIG_USB_HCI) || defined(CONFIG_SDIO_HCI)

	tmp1byte = rtw_read8(padapter, REG_GPIO_EXT_CTRL_8814A);
	/* RTW_INFO("CheckPbcGPIO - %x\n", tmp1byte); */

	if (tmp1byte == 0xff)
		return ;
	else if (tmp1byte & BIT3) {
		/* Here we only set bPbcPressed to TRUE. After trigger PBC, the variable will be set to FALSE */
		RTW_INFO("CheckPbcGPIO - PBC is pressed\n");
		bPbcPressed = _TRUE;
	}

#endif

	if (_TRUE == bPbcPressed) {
		/* Here we only set bPbcPressed to true */
		/* After trigger PBC, the variable will be set to false */
		RTW_INFO("CheckPbcGPIO - PBC is pressed\n");

		rtw_request_wps_pbc_event(padapter);
	}
}
#endif /* #ifdef CONFIG_SUPPORT_HW_WPS_PBC */

/*
 * Initialize GPIO setting registers
 *   */
#ifdef CONFIG_USB_HCI
static void
dm_InitGPIOSetting(
		PADAPTER	Adapter
)
{
	PHAL_DATA_TYPE		pHalData = GET_HAL_DATA(Adapter);

	u8	tmp1byte;

	tmp1byte = rtw_read8(Adapter, REG_GPIO_MUXCFG);
	tmp1byte &= (GPIOSEL_GPIO | ~GPIOSEL_ENBT);

	rtw_write8(Adapter, REG_GPIO_MUXCFG, tmp1byte);
}
#endif
/* ************************************************************
 * functions
 * ************************************************************ */
static void Init_ODM_ComInfo_8814(PADAPTER	Adapter)
{
	PHAL_DATA_TYPE	pHalData = GET_HAL_DATA(Adapter);
	struct dm_struct		*pDM_Odm = &(pHalData->odmpriv);
	u32 SupportAbility = 0;

	u8	cut_ver, fab_ver;

	Init_ODM_ComInfo(Adapter);

	fab_ver = ODM_TSMC;
	if (IS_A_CUT(pHalData->version_id))
		cut_ver = ODM_CUT_A;
	else if (IS_B_CUT(pHalData->version_id))
		cut_ver = ODM_CUT_B;
	else if (IS_C_CUT(pHalData->version_id))
		cut_ver = ODM_CUT_C;
	else if (IS_D_CUT(pHalData->version_id))
		cut_ver = ODM_CUT_D;
	else if (IS_E_CUT(pHalData->version_id))
		cut_ver = ODM_CUT_E;
	else
		cut_ver = ODM_CUT_A;

	odm_cmn_info_init(pDM_Odm, ODM_CMNINFO_FAB_VER, fab_ver);
	odm_cmn_info_init(pDM_Odm, ODM_CMNINFO_CUT_VER, cut_ver);

}

void
rtl8814_InitHalDm(
		PADAPTER	Adapter
)
{
	PHAL_DATA_TYPE	pHalData = GET_HAL_DATA(Adapter);
	struct dm_struct		*pDM_Odm = &(pHalData->odmpriv);

#ifdef CONFIG_USB_HCI
	dm_InitGPIOSetting(Adapter);
#endif /* CONFIG_USB_HCI */
	rtw_phydm_init(Adapter);
	/* Adapter->fix_rate = 0xFF; */
}


void
rtl8814_HalDmWatchDog(
		PADAPTER	Adapter
)
{
	BOOLEAN		bFwCurrentInPSMode = _FALSE;
	u8 bFwPSAwake = _TRUE;
	PHAL_DATA_TYPE	pHalData = GET_HAL_DATA(Adapter);
	struct dm_struct		*pDM_Odm = &(pHalData->odmpriv);
	struct pwrctrl_priv *pwrpriv = adapter_to_pwrctl(Adapter);
	u8 in_lps = _FALSE;

	if (!rtw_is_hw_init_completed(Adapter))
		goto skip_dm;

#ifdef CONFIG_LPS
	bFwCurrentInPSMode = pwrpriv->bFwCurrentInPSMode;
	rtw_hal_get_hwreg(Adapter, HW_VAR_FWLPS_RF_ON, &bFwPSAwake);
#endif

	if ((rtw_is_hw_init_completed(Adapter))
	    && ((!bFwCurrentInPSMode) && bFwPSAwake)) {

		rtw_hal_check_rxfifo_full(Adapter);
		/*  */
		/* Dynamically switch RTS/CTS protection. */
		/*  */


	}

#ifdef CONFIG_DISABLE_ODM
	goto skip_dm;
#endif
#ifdef CONFIG_LPS
	if (pwrpriv->bLeisurePs && bFwCurrentInPSMode && pwrpriv->pwr_mode != PS_MODE_ACTIVE)
		in_lps = _TRUE;
#endif

	rtw_phydm_watchdog(Adapter, in_lps);

skip_dm:

#ifdef CONFIG_SUPPORT_HW_WPS_PBC
	/* Check GPIO to determine current Pbc status. */
	dm_CheckPbcGPIO(Adapter);
#endif

	return;
}

void rtl8814_init_dm_priv(PADAPTER Adapter)
{
	PHAL_DATA_TYPE	pHalData = GET_HAL_DATA(Adapter);
	struct dm_struct		*podmpriv = &pHalData->odmpriv;

	Init_ODM_ComInfo_8814(Adapter);
	odm_init_all_timers(podmpriv);
}

void rtl8814_deinit_dm_priv(PADAPTER Adapter)
{
	PHAL_DATA_TYPE	pHalData = GET_HAL_DATA(Adapter);
	struct dm_struct		*podmpriv = &pHalData->odmpriv;
	/* _rtw_spinlock_free(&pHalData->odm_stainfo_lock); */
	odm_cancel_all_timers(podmpriv);
}
