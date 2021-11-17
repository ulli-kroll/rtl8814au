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
#ifndef __HAL_IC_CFG_H__
#define __HAL_IC_CFG_H__

#define RTL8188E_SUPPORT				0
#define RTL8812A_SUPPORT				0
#define RTL8821A_SUPPORT				0
#define RTL8723B_SUPPORT				0
#define RTL8723D_SUPPORT				0
#define RTL8192E_SUPPORT				0
#define RTL8192F_SUPPORT				0
#define RTL8814A_SUPPORT				0
#define RTL8195A_SUPPORT				0
#define RTL8197F_SUPPORT				0
#define RTL8703B_SUPPORT				0
#define RTL8188F_SUPPORT				0
#define RTL8822B_SUPPORT				0
#define RTL8821B_SUPPORT				0
#define RTL8821C_SUPPORT				0
#define RTL8710B_SUPPORT				0
#define RTL8814B_SUPPORT				0
#define RTL8824B_SUPPORT				0
#define RTL8198F_SUPPORT				0
#define RTL8195B_SUPPORT				0
#define RTL8822C_SUPPORT				0
#define RTL8721D_SUPPORT				0
#define RTL8812F_SUPPORT				0
#define RTL8197G_SUPPORT				0
#define RTL8710C_SUPPORT				0


/*#if (RTL8188E_SUPPORT==1)*/
#define RATE_ADAPTIVE_SUPPORT			0
#define POWER_TRAINING_ACTIVE			0

#ifdef CONFIG_MULTIDRV
#endif

#ifdef CONFIG_RTL8812A
	#undef RTL8812A_SUPPORT
	#define RTL8812A_SUPPORT				1
	#ifndef CONFIG_FW_C2H_PKT
		#define CONFIG_FW_C2H_PKT
	#endif
	#ifdef CONFIG_BEAMFORMING
		#define CONFIG_BEAMFORMER_FW_NDPA
		#define BEAMFORMING_SUPPORT		1	/*for phydm beamforming*/
		#define SUPPORT_MU_BF				0
	#endif /*CONFIG_BEAMFORMING*/
	#define CONFIG_RTS_FULL_BW
#endif

#ifdef CONFIG_RTL8821A
	#undef RTL8821A_SUPPORT
	#define RTL8821A_SUPPORT				1
	#ifndef CONFIG_FW_C2H_PKT
		#define CONFIG_FW_C2H_PKT
	#endif
	#ifdef CONFIG_BEAMFORMING
		#define CONFIG_BEAMFORMER_FW_NDPA
		#define BEAMFORMING_SUPPORT		1	/*for phydm beamforming*/
		#define SUPPORT_MU_BF				0
	#endif
	#define CONFIG_RTS_FULL_BW
#endif

#ifdef CONFIG_RTL8814A
	#undef RTL8814A_SUPPORT
	#define RTL8814A_SUPPORT				1
	#ifndef CONFIG_FW_C2H_PKT
		#define CONFIG_FW_C2H_PKT
	#endif
	#define CONFIG_FW_CORRECT_BCN
	#ifdef CONFIG_BEAMFORMING
		#define BEAMFORMING_SUPPORT		1	/*for phydm beamforming*/
		#define SUPPORT_MU_BF				0
	#endif
	#define CONFIG_RTS_FULL_BW
#endif

#ifdef CONFIG_RTL8188GTV
	#undef RTL8188F_SUPPORT
	#define RTL8188F_SUPPORT				1
	#ifndef CONFIG_FW_C2H_PKT
		#define CONFIG_FW_C2H_PKT
	#endif
	#ifndef CONFIG_RTW_MAC_HIDDEN_RPT
		#define CONFIG_RTW_MAC_HIDDEN_RPT
	#endif
	#ifndef CONFIG_RTW_CUSTOMER_STR
		#define CONFIG_RTW_CUSTOMER_STR
	#endif
	#define CONFIG_RTS_FULL_BW
#endif

#ifdef CONFIG_RTL8822B
	#undef RTL8822B_SUPPORT
	#define RTL8822B_SUPPORT				1
	#ifndef CONFIG_FW_C2H_PKT
		#define CONFIG_FW_C2H_PKT
	#endif /* CONFIG_FW_C2H_PKT */
	#define RTW_TX_PA_BIAS	/* Adjust TX PA Bias from eFuse */
	#define CONFIG_DFS	/* Enable 5G band 2&3 channel */
	#define RTW_AMPDU_AGG_RETRY_AND_NEW

	#ifdef CONFIG_CONCURRENT_MODE
		#define CONFIG_AP_PORT_SWAP
		#define CONFIG_FW_MULTI_PORT_SUPPORT
	#endif /* CONFIG_CONCURRENT_MODE */

	/*
	 * Beamforming related definition
	 */
	/* Only support new beamforming mechanism */
	#ifdef CONFIG_BEAMFORMING
		#define RTW_BEAMFORMING_VERSION_2
	#endif /* CONFIG_BEAMFORMING */

	#ifndef CONFIG_RTW_MAC_HIDDEN_RPT
		#define CONFIG_RTW_MAC_HIDDEN_RPT
	#endif /* CONFIG_RTW_MAC_HIDDEN_RPT */

	#ifndef DBG_RX_DFRAME_RAW_DATA
		#define DBG_RX_DFRAME_RAW_DATA
	#endif /* DBG_RX_DFRAME_RAW_DATA */

	#ifndef RTW_IQK_FW_OFFLOAD
		#define RTW_IQK_FW_OFFLOAD
	#endif /* RTW_IQK_FW_OFFLOAD */

	/* Checksum offload feature */
	/*#define CONFIG_TCP_CSUM_OFFLOAD_TX*/
	#if defined(CONFIG_TCP_CSUM_OFFLOAD_TX) && !defined(CONFIG_RTW_NETIF_SG)
		#define CONFIG_RTW_NETIF_SG
	#endif
	#define CONFIG_TCP_CSUM_OFFLOAD_RX

	#define CONFIG_ADVANCE_OTA

	#ifdef CONFIG_MCC_MODE
		#define CONFIG_MCC_MODE_V2
		#define CONFIG_MCC_PHYDM_OFFLOAD
	#endif /* CONFIG_MCC_MODE */

	#if defined(CONFIG_TDLS) && defined(CONFIG_TDLS_CH_SW)
		#define CONFIG_TDLS_CH_SW_V2
	#endif

	#ifndef RTW_CHANNEL_SWITCH_OFFLOAD
		#ifdef CONFIG_TDLS_CH_SW_V2
			#define RTW_CHANNEL_SWITCH_OFFLOAD
		#endif
	#endif /* RTW_CHANNEL_SWITCH_OFFLOAD */

	#define CONFIG_SUPPORT_FIFO_DUMP
	#define CONFIG_HW_P0_TSF_SYNC
	#define CONFIG_BCN_RECV_TIME
	#define CONFIG_RTS_FULL_BW

	#ifdef CONFIG_LPS
		/* #define CONFIG_LPS_ACK */	/* Supported after FW v30 */
	#endif
#endif /* CONFIG_RTL8822B */

#ifdef CONFIG_RTL8822C
	#undef RTL8822C_SUPPORT
	#define RTL8822C_SUPPORT				1
	/*#define DBG_LA_MODE*/
	#ifndef CONFIG_FW_C2H_PKT
		#define CONFIG_FW_C2H_PKT
	#endif /* CONFIG_FW_C2H_PKT */
	#define RTW_TX_PA_BIAS	/* Adjust TX PA Bias from eFuse */
	#define CONFIG_DFS	/* Enable 5G band 2&3 channel */

	#ifdef CONFIG_CONCURRENT_MODE
		#define CONFIG_AP_PORT_SWAP
		#define CONFIG_FW_MULTI_PORT_SUPPORT
	#endif /* CONFIG_CONCURRENT_MODE */

	/*
	 * Beamforming related definition
	 */
	/* Only support new beamforming mechanism */
	#ifdef CONFIG_BEAMFORMING
		#define RTW_BEAMFORMING_VERSION_2
	#endif /* CONFIG_BEAMFORMING */

	#ifndef CONFIG_RTW_MAC_HIDDEN_RPT
		#define CONFIG_RTW_MAC_HIDDEN_RPT
	#endif /* CONFIG_RTW_MAC_HIDDEN_RPT */

	#ifndef DBG_RX_DFRAME_RAW_DATA
		#define DBG_RX_DFRAME_RAW_DATA
	#endif /* DBG_RX_DFRAME_RAW_DATA */

	#ifndef RTW_IQK_FW_OFFLOAD
		/* #define RTW_IQK_FW_OFFLOAD */
	#endif /* RTW_IQK_FW_OFFLOAD */
	#define CONFIG_ADVANCE_OTA

	#ifdef CONFIG_MCC_MODE
		#define CONFIG_MCC_MODE_V2
	#endif /* CONFIG_MCC_MODE */

	#if defined(CONFIG_TDLS) && defined(CONFIG_TDLS_CH_SW)
		#define CONFIG_TDLS_CH_SW_V2
	#endif

	#ifndef RTW_CHANNEL_SWITCH_OFFLOAD
		#ifdef CONFIG_TDLS_CH_SW_V2
			#define RTW_CHANNEL_SWITCH_OFFLOAD
		#endif
	#endif /* RTW_CHANNEL_SWITCH_OFFLOAD */

	#define CONFIG_SUPPORT_FIFO_DUMP
	#define CONFIG_HW_P0_TSF_SYNC
	#define CONFIG_BCN_RECV_TIME

	/*#define CONFIG_TCP_CSUM_OFFLOAD_TX*/
	#if defined(CONFIG_TCP_CSUM_OFFLOAD_TX) && !defined(CONFIG_RTW_NETIF_SG)
		#define CONFIG_RTW_NETIF_SG
	#endif
	#define CONFIG_TCP_CSUM_OFFLOAD_RX

	#define CONFIG_RTS_FULL_BW
	
	#ifdef CONFIG_LPS
		#define CONFIG_LPS_ACK	/* Supported after FW v07 */
		#define CONFIG_LPS_1T1R /* Supported after FW v07 */
	#endif

	#define CONFIG_BT_EFUSE_MASK
#endif /* CONFIG_RTL8822C */

#ifdef CONFIG_RTL8821C
	#undef RTL8821C_SUPPORT
	#define RTL8821C_SUPPORT				1
	#ifndef CONFIG_FW_C2H_PKT
		#define CONFIG_FW_C2H_PKT
	#endif
	#ifdef CONFIG_NO_FW
		#ifdef CONFIG_RTW_MAC_HIDDEN_RPT
			#undef CONFIG_RTW_MAC_HIDDEN_RPT
		#endif
	#else
		#ifndef CONFIG_RTW_MAC_HIDDEN_RPT
			#define CONFIG_RTW_MAC_HIDDEN_RPT
		#endif
	#endif
	#define LOAD_FW_HEADER_FROM_DRIVER
	#define CONFIG_PHY_CAPABILITY_QUERY
	#ifdef CONFIG_CONCURRENT_MODE
	#define CONFIG_AP_PORT_SWAP
	#define CONFIG_FW_MULTI_PORT_SUPPORT
	#endif
	#define CONFIG_SUPPORT_FIFO_DUMP
	#ifndef RTW_IQK_FW_OFFLOAD
		#define RTW_IQK_FW_OFFLOAD
	#endif /* RTW_IQK_FW_OFFLOAD */
	/*#define CONFIG_AMPDU_PRETX_CD*/
	/*#define DBG_PRE_TX_HANG*/

	/* Beamforming related definition */
	/* Only support new beamforming mechanism */
	#ifdef CONFIG_BEAMFORMING
		#define RTW_BEAMFORMING_VERSION_2
	#endif /* CONFIG_BEAMFORMING */
	#define CONFIG_HW_P0_TSF_SYNC
	#define CONFIG_BCN_RECV_TIME
	#define CONFIG_RTS_FULL_BW

	#ifdef CONFIG_LPS
		/* #define CONFIG_LPS_ACK */	/* Supported after FW v25 */
	#endif
#endif /*CONFIG_RTL8821C*/

#ifdef CONFIG_RTL8814B
	#undef RTL8814B_SUPPORT
	#define RTL8814B_SUPPORT				1
	#ifndef CONFIG_FW_C2H_PKT
		#define CONFIG_FW_C2H_PKT
	#endif /* CONFIG_FW_C2H_PKT */
	#define RTW_TX_PA_BIAS	/* Adjust TX PA Bias from eFuse */
	//#define CONFIG_DFS	/* Enable 5G band 2&3 channel */
	#define RTW_AMPDU_AGG_RETRY_AND_NEW

	#ifdef CONFIG_CONCURRENT_MODE
		/*#define CONFIG_AP_PORT_SWAP*/
		#define CONFIG_FW_MULTI_PORT_SUPPORT
		#define CONFIG_SUPPORT_AP_PORT1
	#endif /* CONFIG_CONCURRENT_MODE */

	/*
	 * Beamforming related definition
	 */
	/* Only support new beamforming mechanism */
	#ifdef CONFIG_BEAMFORMING
		#define RTW_BEAMFORMING_VERSION_2
	#endif /* CONFIG_BEAMFORMING */

	#ifndef DBG_RX_DFRAME_RAW_DATA
		#define DBG_RX_DFRAME_RAW_DATA
	#endif /* DBG_RX_DFRAME_RAW_DATA */

	#ifndef RTW_IQK_FW_OFFLOAD
		#define RTW_IQK_FW_OFFLOAD
	#endif /* RTW_IQK_FW_OFFLOAD */

	/* Checksum offload feature */
	/*#define CONFIG_TCP_CSUM_OFFLOAD_TX*/ /* not ready */
	#define CONFIG_TCP_CSUM_OFFLOAD_RX

	#define CONFIG_ADVANCE_OTA

	#ifdef CONFIG_MCC_MODE
		#define CONFIG_MCC_MODE_V2
		#define CONFIG_MCC_PHYDM_OFFLOAD
	#endif /* CONFIG_MCC_MODE */

	#if defined(CONFIG_TDLS) && defined(CONFIG_TDLS_CH_SW)
		#define CONFIG_TDLS_CH_SW_V2
	#endif

	#ifndef RTW_CHANNEL_SWITCH_OFFLOAD
		#ifdef CONFIG_TDLS_CH_SW_V2
			#define RTW_CHANNEL_SWITCH_OFFLOAD
		#endif
	#endif /* RTW_CHANNEL_SWITCH_OFFLOAD */

	#define CONFIG_SUPPORT_FIFO_DUMP
	#define CONFIG_HW_P0_TSF_SYNC
	#define CONFIG_BCN_RECV_TIME
	#define CONFIG_RTS_FULL_BW

	#define CONFIG_PROTSEL_PORT
	#define CONFIG_PROTSEL_ATIMDTIM
	#define CONFIG_PROTSEL_MACSLEEP

	#define CONFIG_HAS_HW_VAR_BCN_CTRL_ADDR
	#define CONFIG_HAS_HW_VAR_BCN_FUNC
	#define CONFIG_HAS_HW_VAR_MLME_DISCONNECT
	#define CONFIG_HAS_HW_VAR_MLME_JOIN
	#define CONFIG_HAS_HW_VAR_CORRECT_TSF
	#define CONFIG_HAS_TX_BEACON_PAUSE

	#define CONFIG_USE_TSSI
	#define CONFIG_RTW_TX_NPATH_EN		/* 8814B is always 4TX */

	#ifdef CONFIG_LPS
		/* #define CONFIG_LPS_ACK */	/* Supported after FW v04 */
	#endif
#endif /* CONFIG_RTL8814B */

#endif /*__HAL_IC_CFG_H__*/
