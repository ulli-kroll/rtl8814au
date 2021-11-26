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
#ifndef __COMMON_H2C_H__
#define __COMMON_H2C_H__

/* ---------------------------------------------------------------------------------------------------------
 * ----------------------------------    H2C CMD DEFINITION    ------------------------------------------------
 * ---------------------------------------------------------------------------------------------------------
 * 88e, 8723b, 8812, 8821, 92e use the same FW code base */
enum h2c_cmd {
	/* Common Class: 000 */
	H2C_RSVD_PAGE = 0x00,
	H2C_MEDIA_STATUS_RPT = 0x01,
	H2C_SCAN_ENABLE = 0x02,
	H2C_KEEP_ALIVE = 0x03,
	H2C_DISCON_DECISION = 0x04,
	H2C_PSD_OFFLOAD = 0x05,
	H2C_CUSTOMER_STR_REQ = 0x06,
	H2C_AP_OFFLOAD = 0x08,
	H2C_BCN_RSVDPAGE = 0x09,
	H2C_PROBERSP_RSVDPAGE = 0x0A,
	H2C_FCS_RSVDPAGE = 0x10,
	H2C_FCS_INFO = 0x11,
	H2C_AP_WOW_GPIO_CTRL = 0x13,
	H2C_CHNL_SWITCH_OPER_OFFLOAD = 0x1C,
	H2C_SINGLE_CHANNELSWITCH_V2 = 0x1D,

	/* PoweSave Class: 001 */
	H2C_SET_PWR_MODE = 0x20,
	H2C_PS_TUNING_PARA = 0x21,
	H2C_PS_TUNING_PARA2 = 0x22,
	H2C_P2P_LPS_PARAM = 0x23,
	H2C_P2P_PS_OFFLOAD = 0x24,
	H2C_PS_SCAN_ENABLE = 0x25,
	H2C_SAP_PS_ = 0x26,
	H2C_INACTIVE_PS_ = 0x27, /* Inactive_PS */
	H2C_FWLPS_IN_IPS_ = 0x28,
#ifdef CONFIG_LPS_POFF
	H2C_LPS_POFF_CTRL = 0x29,
	H2C_LPS_POFF_PARAM = 0x2A,
#endif
#ifdef CONFIG_LPS_PG
	H2C_LPS_PG_INFO = 0x2B,
#endif

#ifdef CONFIG_FW_MULTI_PORT_SUPPORT
	H2C_DEFAULT_PORT_ID = 0x2C,
#endif
	/* Dynamic Mechanism Class: 010 */
	H2C_MACID_CFG = 0x40,
	H2C_TXBF = 0x41,
	H2C_RSSI_SETTING = 0x42,
	H2C_AP_REQ_TXRPT = 0x43,
	H2C_INIT_RATE_COLLECT = 0x44,
	H2C_IQ_CALIBRATION	= 0x45,

	H2C_RA_MASK_3SS = 0x46,/* for 8814A */
	H2C_RA_PARA_ADJUST = 0x47,/* CONFIG_RA_DBG_CMD */
	H2C_DYNAMIC_TX_PATH = 0x48,/* for 8814A */

	H2C_FW_TRACE_EN = 0x49,
#ifdef RTW_PER_CMD_SUPPORT_FW
	H2C_REQ_PER_RPT = 0x4e,
#endif
	/* BT Class: 011 */
	H2C_B_TYPE_TDMA = 0x60,
	H2C_BT_INFO = 0x61,
	H2C_FORCE_BT_TXPWR = 0x62,
	H2C_BT_IGNORE_WLANACT = 0x63,
	H2C_DAC_SWING_VALUE = 0x64,
	H2C_ANT_SEL_RSV = 0x65,
	H2C_WL_OPMODE = 0x66,
	H2C_BT_MP_OPER = 0x67,
	H2C_BT_CONTROL = 0x68,
	H2C_BT_WIFI_CTRL = 0x69,
	H2C_BT_FW_PATCH = 0x6A,
	/* WOWLAN Class: 100 */
	H2C_WOWLAN = 0x80,
	H2C_REMOTE_WAKE_CTRL = 0x81,
	H2C_AOAC_GLOBAL_INFO = 0x82,
	H2C_AOAC_RSVD_PAGE = 0x83,
	H2C_AOAC_RSVD_PAGE2 = 0x84,
	H2C_D0_SCAN_OFFLOAD_CTRL = 0x85,
	H2C_D0_SCAN_OFFLOAD_INFO = 0x86,
	H2C_CHNL_SWITCH_OFFLOAD = 0x87,
	H2C_AOAC_RSVDPAGE3 = 0x88,
	H2C_P2P_OFFLOAD_RSVD_PAGE = 0x8A,
	H2C_P2P_OFFLOAD = 0x8B,
#ifdef CONFIG_FW_HANDLE_TXBCN
	H2C_FW_BCN_OFFLOAD = 0xBA,
#endif
	H2C_RESET_TSF = 0xC0,
#ifdef CONFIG_FW_CORRECT_BCN
	H2C_BCNHWSEQ = 0xC5,
#endif
	H2C_CUSTOMER_STR_W1 = 0xC6,
	H2C_CUSTOMER_STR_W2 = 0xC7,
	H2C_CUSTOMER_STR_W3 = 0xC8,
#ifdef DBG_FW_DEBUG_MSG_PKT
	H2C_FW_DBG_MSG_PKT = 0xE1,
#endif /*DBG_FW_DEBUG_MSG_PKT*/
	H2C_MAXID,
};

#define H2C_INACTIVE_PS_LEN		4
#define H2C_RSVDPAGE_LOC_LEN		5
#ifdef CONFIG_FW_MULTI_PORT_SUPPORT
#define H2C_DEFAULT_PORT_ID_LEN		2
#define H2C_MEDIA_STATUS_RPT_LEN		4
#else
#define H2C_MEDIA_STATUS_RPT_LEN		3
#endif
#define H2C_KEEP_ALIVE_CTRL_LEN	2
#define H2C_DISCON_DECISION_LEN		3
#define H2C_AP_OFFLOAD_LEN		3
#define H2C_AP_WOW_GPIO_CTRL_LEN	4
#define H2C_AP_PS_LEN			2
#define H2C_PWRMODE_LEN			7
#define H2C_PSTUNEPARAM_LEN			4
#define H2C_MACID_CFG_LEN		7
#define H2C_BTMP_OPER_LEN			5
#define H2C_WOWLAN_LEN			7
#define H2C_REMOTE_WAKE_CTRL_LEN	3
#define H2C_AOAC_GLOBAL_INFO_LEN	2
#define H2C_AOAC_RSVDPAGE_LOC_LEN	7
#define H2C_SCAN_OFFLOAD_CTRL_LEN	4
#define H2C_BT_FW_PATCH_LEN			6
#define H2C_RSSI_SETTING_LEN		4
#define H2C_AP_REQ_TXRPT_LEN		3
#define H2C_FORCE_BT_TXPWR_LEN		3
#define H2C_BCN_RSVDPAGE_LEN		5
#define H2C_PROBERSP_RSVDPAGE_LEN	5
#define H2C_P2PRSVDPAGE_LOC_LEN	5
#define H2C_P2P_OFFLOAD_LEN	3
#ifdef CONFIG_LPS_PG
#ifdef CONFIG_RTL8822C
	#define H2C_LPS_PG_INFO_LEN		4
#else
	#define H2C_LPS_PG_INFO_LEN		2
#endif
	#define H2C_LPSPG_LEN			16
#endif
#ifdef CONFIG_LPS_POFF
	#define H2C_LPS_POFF_CTRL_LEN		1
	#define H2C_LPS_POFF_PARAM_LEN		5
#endif


#ifdef DBG_FW_DEBUG_MSG_PKT
	#define H2C_FW_DBG_MSG_PKT_LEN	2
#endif /*DBG_FW_DEBUG_MSG_PKT*/

#define H2C_SINGLE_CHANNELSWITCH_V2_LEN 2

#define eq_mac_addr(a, b)						(((a)[0] == (b)[0] && (a)[1] == (b)[1] && (a)[2] == (b)[2] && (a)[3] == (b)[3] && (a)[4] == (b)[4] && (a)[5] == (b)[5]) ? 1 : 0)
#define cp_mac_addr(des, src)					((des)[0] = (src)[0], (des)[1] = (src)[1], (des)[2] = (src)[2], (des)[3] = (src)[3], (des)[4] = (src)[4], (des)[5] = (src)[5])
#define cpIpAddr(des, src)					((des)[0] = (src)[0], (des)[1] = (src)[1], (des)[2] = (src)[2], (des)[3] = (src)[3])



/* _RSVDPAGE_LOC_CMD_0x00 */
#define SET_H2CCMD_RSVDPAGE_LOC_PROBE_RSP(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)
#define SET_H2CCMD_RSVDPAGE_LOC_PSPOLL(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)
#define SET_H2CCMD_RSVDPAGE_LOC_NULL_DATA(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 8, __Value)
#define SET_H2CCMD_RSVDPAGE_LOC_QOS_NULL_DATA(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+3, 0, 8, __Value)
#define SET_H2CCMD_RSVDPAGE_LOC_BT_QOS_NULL_DATA(__pH2CCmd, __Value)SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 0, 8, __Value)

/* _MEDIA_STATUS_RPT_PARM_CMD_0x01 */
#define SET_H2CCMD_MSRRPT_PARM_OPMODE(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)), 0, 1, (__Value))
#define SET_H2CCMD_MSRRPT_PARM_MACID_IND(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)), 1, 1, (__Value))
#define SET_H2CCMD_MSRRPT_PARM_MIRACAST(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)), 2, 1, (__Value))
#define SET_H2CCMD_MSRRPT_PARM_MIRACAST_SINK(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)), 3, 1, (__Value))
#define SET_H2CCMD_MSRRPT_PARM_ROLE(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)), 4, 4, (__Value))
#define SET_H2CCMD_MSRRPT_PARM_MACID(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)) + 1, 0, 8, (__Value))
#define SET_H2CCMD_MSRRPT_PARM_MACID_END(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)) + 2, 0, 8, (__Value))
#define SET_H2CCMD_MSRRPT_PARM_PORT_NUM(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)) + 3, 0, 3, (__Value))

#define GET_H2CCMD_MSRRPT_PARM_OPMODE(__pH2CCmd)		LE_BITS_TO_1BYTE(((u8 *)(__pH2CCmd)), 0, 1)
#define GET_H2CCMD_MSRRPT_PARM_MIRACAST(__pH2CCmd)		LE_BITS_TO_1BYTE(((u8 *)(__pH2CCmd)), 2, 1)
#define GET_H2CCMD_MSRRPT_PARM_MIRACAST_SINK(__pH2CCmd)	LE_BITS_TO_1BYTE(((u8 *)(__pH2CCmd)), 3, 1)
#define GET_H2CCMD_MSRRPT_PARM_ROLE(__pH2CCmd)			LE_BITS_TO_1BYTE(((u8 *)(__pH2CCmd)), 4, 4)

#define H2C_MSR_ROLE_RSVD	0
#define H2C_MSR_ROLE_STA	1
#define H2C_MSR_ROLE_AP		2
#define H2C_MSR_ROLE_GC		3
#define H2C_MSR_ROLE_GO		4
#define H2C_MSR_ROLE_TDLS	5
#define H2C_MSR_ROLE_ADHOC	6
#define H2C_MSR_ROLE_MESH	7
#define H2C_MSR_ROLE_MAX	8

extern const char *const _h2c_msr_role_str[];
#define h2c_msr_role_str(role) (((role) >= H2C_MSR_ROLE_MAX) ? _h2c_msr_role_str[H2C_MSR_ROLE_MAX] : _h2c_msr_role_str[(role)])

#define H2C_MSR_FMT "%s %s%s"
#define H2C_MSR_ARG(h2c_msr) \
	GET_H2CCMD_MSRRPT_PARM_OPMODE((h2c_msr)) ? " C" : "", \
	h2c_msr_role_str(GET_H2CCMD_MSRRPT_PARM_ROLE((h2c_msr))), \
	GET_H2CCMD_MSRRPT_PARM_MIRACAST((h2c_msr)) ? (GET_H2CCMD_MSRRPT_PARM_MIRACAST_SINK((h2c_msr)) ? " MSINK" : " MSRC") : ""

s32 rtw_hal_set_FwMediaStatusRpt_cmd(_adapter *adapter, bool opmode, bool miracast, bool miracast_sink, u8 role, u8 macid, bool macid_ind, u8 macid_end);
s32 rtw_hal_set_FwMediaStatusRpt_single_cmd(_adapter *adapter, bool opmode, bool miracast, bool miracast_sink, u8 role, u8 macid);
s32 rtw_hal_set_FwMediaStatusRpt_range_cmd(_adapter *adapter, bool opmode, bool miracast, bool miracast_sink, u8 role, u8 macid, u8 macid_end);

/* _KEEP_ALIVE_CMD_0x03 */
#define SET_H2CCMD_KEEPALIVE_PARM_ENABLE(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_KEEPALIVE_PARM_ADOPT(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)
#define SET_H2CCMD_KEEPALIVE_PARM_PKT_TYPE(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 2, 1, __Value)
#define SET_H2CCMD_KEEPALIVE_PARM_PORT_NUM(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 3, 3, __Value)
#define SET_H2CCMD_KEEPALIVE_PARM_CHECK_PERIOD(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd+1, 0, 8, __Value)

/* _DISCONNECT_DECISION_CMD_0x04 */
#define SET_H2CCMD_DISCONDECISION_PARM_ENABLE(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_DISCONDECISION_PARM_ADOPT(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)
#define SET_H2CCMD_DISCONDECISION_PARM_TRY_BCN_FAIL_EN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 2, 1, __Value)
#define SET_H2CCMD_DISCONDECISION_PARM_DISCONNECT_EN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 3, 1, __Value)
#define SET_H2CCMD_DISCONDECISION_PORT_NUM(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 4, 3, __Value)
#define SET_H2CCMD_DISCONDECISION_PARM_CHECK_PERIOD(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd+1, 0, 8, __Value)
#define SET_H2CCMD_DISCONDECISION_PARM_TRY_PKT_NUM(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd+2, 0, 8, __Value)
#define SET_H2CCMD_DISCONDECISION_PARM_TRY_OK_BCN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd+3, 0, 8, __Value)

/* _AP_Offload 0x08 */
#define SET_H2CCMD_AP_WOWLAN_EN(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)
/* _BCN_RsvdPage	0x09 */
#define SET_H2CCMD_AP_WOWLAN_RSVDPAGE_LOC_BCN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)
/* _Probersp_RsvdPage 0x0a */
#define SET_H2CCMD_AP_WOWLAN_RSVDPAGE_LOC_ProbeRsp(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)
/* _Probersp_RsvdPage 0x13 */
#define SET_H2CCMD_AP_WOW_GPIO_CTRL_INDEX(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 4, __Value)
#define SET_H2CCMD_AP_WOW_GPIO_CTRL_C2H_EN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 4, 1, __Value)
#define SET_H2CCMD_AP_WOW_GPIO_CTRL_PLUS(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 5, 1, __Value)
#define SET_H2CCMD_AP_WOW_GPIO_CTRL_HIGH_ACTIVE(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 6, 1, __Value)
#define SET_H2CCMD_AP_WOW_GPIO_CTRL_EN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 7, 1, __Value)
#define SET_H2CCMD_AP_WOW_GPIO_CTRL_DURATION(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)
#define SET_H2CCMD_AP_WOW_GPIO_CTRL_C2H_DURATION(__pH2CCmd, __Value)SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 8, __Value)
/* _AP_PS 0x26 */
#define SET_H2CCMD_AP_WOW_PS_EN(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_AP_WOW_PS_32K_EN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)
#define SET_H2CCMD_AP_WOW_PS_RF(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 2, 1, __Value)
#define SET_H2CCMD_AP_WOW_PS_DURATION(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)

/* INACTIVE_PS 0x27, duration unit is TBTT */
#define SET_H2CCMD_INACTIVE_PS_EN(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_INACTIVE_IGNORE_PS(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)
#define SET_H2CCMD_INACTIVE_PERIOD_SCAN_EN(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 2, 1, __Value)
#define SET_H2CCMD_INACTIVE_DISBBRF(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 3, 1, __Value)
#define SET_H2CCMD_INACTIVE_PS_FREQ(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE(__pH2CCmd + 1, 0, 8, __Value)
#define SET_H2CCMD_INACTIVE_PS_DURATION(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE(__pH2CCmd + 2, 0, 8, __Value)
#define SET_H2CCMD_INACTIVE_PS_PERIOD_SCAN_TIME(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE(__pH2CCmd + 3, 0, 8, __Value)

#ifdef CONFIG_LPS_POFF
/*PARTIAL OFF Control 0x29*/
#define SET_H2CCMD_LPS_POFF_CTRL_EN(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
/*PARTIAL OFF PARAM   0x2A*/
#define SET_H2CCMD_LPS_POFF_PARAM_RDVLD(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_LPS_POFF_PARAM_WRVLD(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)
#define SET_H2CCMD_LPS_POFF_PARAM_STARTADDL(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE(__pH2CCmd+1, 0, 8, __Value)
#define SET_H2CCMD_LPS_POFF_PARAM_STARTADDH(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE(__pH2CCmd+2, 0, 8, __Value)
#define SET_H2CCMD_LPS_POFF_PARAM_ENDADDL(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE(__pH2CCmd+3, 0, 8, __Value)
#define SET_H2CCMD_LPS_POFF_PARAM_ENDADDH(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE(__pH2CCmd+4, 0, 8, __Value)
#endif

#ifdef CONFIG_FW_MULTI_PORT_SUPPORT
/* DEFAULT PORT ID 0x2C*/
#define SET_H2CCMD_DFTPID_PORT_ID(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)), 0, 8, (__Value))
#define SET_H2CCMD_DFTPID_MAC_ID(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(((u8 *)(__pH2CCmd)) + 1, 0, 8, (__Value))
#endif

/* CHNL SWITCH OPER OFFLOAD 0x1C */
#define SET_H2CCMD_CH_SW_OPER_OFFLOAD_CH_NUM(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)
#define SET_H2CCMD_CH_SW_OPER_OFFLOAD_BW_MODE(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd) + 1, 0, 2, __Value)
#define SET_H2CCMD_CH_SW_OPER_OFFLOAD_BW_40M_SC(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd) + 1, 2, 3, __Value)
#define SET_H2CCMD_CH_SW_OPER_OFFLOAD_BW_80M_SC(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd) + 1, 5, 3, __Value)
#define SET_H2CCMD_CH_SW_OPER_OFFLOAD_RFE_TYPE(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd) + 2, 0, 4, __Value)

/* H2C_SINGLE_CHANNELSWITCH_V2 = 0x1D */
#define SET_H2CCMD_SINGLE_CH_SWITCH_V2_CENTRAL_CH_NUM(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)
#define SET_H2CCMD_SINGLE_CH_SWITCH_V2_PRIMARY_CH_IDX(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd) + 1, 0, 4, __Value)
#define SET_H2CCMD_SINGLE_CH_SWITCH_V2_BW(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd) + 1, 4, 4, __Value)



/* _WoWLAN PARAM_CMD_0x80 */
#define SET_H2CCMD_WOWLAN_FUNC_ENABLE(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_WOWLAN_PATTERN_MATCH_ENABLE(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)
#define SET_H2CCMD_WOWLAN_MAGIC_PKT_ENABLE(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 2, 1, __Value)
#define SET_H2CCMD_WOWLAN_UNICAST_PKT_ENABLE(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 3, 1, __Value)
#define SET_H2CCMD_WOWLAN_ALL_PKT_DROP(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 4, 1, __Value)
#define SET_H2CCMD_WOWLAN_GPIO_ACTIVE(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 5, 1, __Value)
#define SET_H2CCMD_WOWLAN_REKEY_WAKE_UP(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 6, 1, __Value)
#define SET_H2CCMD_WOWLAN_DISCONNECT_WAKE_UP(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 7, 1, __Value)
#define SET_H2CCMD_WOWLAN_GPIONUM(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 7, __Value)
#define SET_H2CCMD_WOWLAN_DATAPIN_WAKE_UP(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 7, 1, __Value)
#define SET_H2CCMD_WOWLAN_GPIO_DURATION(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 8, __Value)
#define SET_H2CCMD_WOWLAN_GPIO_PULSE_EN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+3, 0, 1, __Value)
#define SET_H2CCMD_WOWLAN_GPIO_PULSE_COUNT(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+3, 1, 7, __Value)
#define SET_H2CCMD_WOWLAN_DISABLE_UPHY(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 0, 1, __Value)
#define SET_H2CCMD_WOWLAN_HST2DEV_EN(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 1, 1, __Value)
#define SET_H2CCMD_WOWLAN_GPIO_DURATION_MS(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 2, 1, __Value)
#define SET_H2CCMD_WOWLAN_CHANGE_UNIT(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 2, 1, __Value)
#define SET_H2CCMD_WOWLAN_UNIT_FOR_UPHY_DISABLE(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 3, 1, __Value)
#define SET_H2CCMD_WOWLAN_TAKE_PDN_UPHY_DIS_EN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 4, 1, __Value)
#define SET_H2CCMD_WOWLAN_GPIO_INPUT_EN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 5, 1, __Value)
#define SET_H2CCMD_WOWLAN_DEV2HST_EN(__pH2CCmd, __Value) 	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 7, 1, __Value)
#define SET_H2CCMD_WOWLAN_TIME_FOR_UPHY_DISABLE(__pH2CCmd, __Value) SET_BITS_TO_LE_1BYTE((__pH2CCmd)+5, 0, 8, __Value)
#define SET_H2CCMD_WOWLAN_RISE_HST2DEV(__pH2CCmd, __Value) 	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+6, 2, 1, __Value)

/* _REMOTE_WAKEUP_CMD_0x81 */
#define SET_H2CCMD_REMOTE_WAKECTRL_ENABLE(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_ARP_OFFLOAD_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_NDP_OFFLOAD_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 2, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_GTK_OFFLOAD_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 3, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_NLO_OFFLOAD_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 4, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_FW_UNICAST_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 7, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_P2P_OFFLAD_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_NBNS_FILTER_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 2, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_TKIP_OFFLOAD_EN(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 3, 1, __Value)

#define SET_H2CCMD_REMOTE_WAKE_CTRL_ARP_ACTION(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 1, __Value)
#define SET_H2CCMD_REMOTE_WAKE_CTRL_FW_PARSING_UNTIL_WAKEUP(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 4, 1, __Value)

/* AOAC_GLOBAL_INFO_0x82 */
#define SET_H2CCMD_AOAC_GLOBAL_INFO_PAIRWISE_ENC_ALG(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 8, __Value)
#define SET_H2CCMD_AOAC_GLOBAL_INFO_GROUP_ENC_ALG(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)

/* AOAC_RSVDPAGE_LOC_0x83 */
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_REMOTE_WAKE_CTRL_INFO(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd), 0, 8, __Value)
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_ARP_RSP(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_NEIGHBOR_ADV(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 8, __Value)
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_GTK_RSP(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+3, 0, 8, __Value)
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_GTK_INFO(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+4, 0, 8, __Value)
#ifdef CONFIG_GTK_OL
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_GTK_EXT_MEM(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd)+5, 0, 8, __Value)
#endif /* CONFIG_GTK_OL */
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_NDP_INFO(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+6, 0, 8, __Value)

/* AOAC_RSVDPAGE_2_0x84 */

/* AOAC_RSVDPAGE_3_0x88 */
#ifdef CONFIG_PNO_SUPPORT
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_NLO_INFO(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE((__pH2CCmd), 0, 8, __Value)
#endif
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_AOAC_REPORT(__pH2CCmd, __Value) \
	SET_BITS_TO_LE_1BYTE((__pH2CCmd) + 1, 0, 8, __Value)

#ifdef CONFIG_PNO_SUPPORT
/* D0_Scan_Offload_Info_0x86 */
#define SET_H2CCMD_AOAC_NLO_FUN_EN(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE((__pH2CCmd), 3, 1, __Value)
#define SET_H2CCMD_AOAC_NLO_IPS_EN(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE((__pH2CCmd), 4, 1, __Value)
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_PROBE_PACKET(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_SCAN_INFO(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 8, __Value)
#define SET_H2CCMD_AOAC_RSVDPAGE_LOC_SSID_INFO(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+3, 0, 8, __Value)
#endif /* CONFIG_PNO_SUPPORT */

#ifdef CONFIG_LPS_PG
#define SET_H2CCMD_LPSPG_SEC_CAM_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)/*SecurityCAM_En*/
#define SET_H2CCMD_LPSPG_MBID_CAM_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)/*BSSIDCAM_En*/
#define SET_H2CCMD_LPSPG_PMC_CAM_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 2, 1, __Value)/*PatternMatchCAM_En*/
#define SET_H2CCMD_LPSPG_MACID_SEARCH_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 3, 1, __Value)/*MACIDSearch_En*/
#define SET_H2CCMD_LPSPG_TXSC_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 4, 1, __Value)/*TXSC_En*/
#define SET_H2CCMD_LPSPG_MU_RATE_TB_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 5, 1, __Value)/*MURateTable_En*/
#define SET_H2CCMD_LPSPG_LOC(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value)/*Loc_LPS_PG*/
#define SET_H2CCMD_LPSPG_DPK_INFO_LOC(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+2, 0, 8, __Value)/*Loc_LPS_PG_DPK_info*/
#define SET_H2CCMD_LPSPG_IQK_INFO_LOC(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd) + 3, 0, 8, __Value)/*Loc_IQK_result*/
#endif

#ifdef DBG_FW_DEBUG_MSG_PKT
#define SET_H2CCMD_FW_DBG_MSG_PKT_EN(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)/*sniffer_dbg_en*/
#define SET_H2CCMD_RSVDPAGE_LOC_FW_DBG_MSG_PKT(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 8, __Value) /*loc_debug_packet*/
#endif /*DBG_FW_DEBUG_MSG_PKT*/

#ifdef DBG_RSVD_PAGE_CFG
#define RSVD_PAGE_CFG(ops, v1, v2, v3)	\
	RTW_INFO("=== [RSVD][%s]-NeedPage:%d, TotalPageNum:%d TotalPacketLen:%d ===\n",	\
		ops, v1, v2, v3)
#else
#define RSVD_PAGE_CFG(ops, v1, v2, v3) do {} while (0)
#endif

/* ---------------------------------------------------------------------------------------------------------
 * -------------------------------------------    Structure    --------------------------------------------------
 * --------------------------------------------------------------------------------------------------------- */
typedef struct _RSVDPAGE_LOC {
	u8 LocProbeRsp;
	u8 LocPsPoll;
	u8 LocNullData;
	u8 LocQosNull;
	u8 LocBTQosNull;
	u8 LocApOffloadBCN;
#ifdef DBG_FW_DEBUG_MSG_PKT
	u8 loc_fw_dbg_msg_pkt;
#endif /*DBG_FW_DEBUG_MSG_PKT*/
} RSVDPAGE_LOC, *PRSVDPAGE_LOC;

struct rsvd_page_cache_t {
	char *name;
	u8 loc;
	u8 page_num;
	u8 *data;
	u32 size;
};

bool rsvd_page_cache_update_all(struct rsvd_page_cache_t *cache, u8 loc
	, u8 txdesc_len, u32 page_size, u8 *info, u32 info_len);
bool rsvd_page_cache_update_data(struct rsvd_page_cache_t *cache, u8 *info
	, u32 info_len);
void rsvd_page_cache_free_data(struct rsvd_page_cache_t *cache);
void rsvd_page_cache_free(struct rsvd_page_cache_t *cache);

#endif
void dump_TX_FIFO(PADAPTER padapter, u8 page_num, u16 page_size);
u8 rtw_hal_set_fw_media_status_cmd(_adapter *adapter, u8 mstatus, u8 macid);

#ifdef RTW_PER_CMD_SUPPORT_FW
u8 rtw_hal_set_req_per_rpt_cmd(_adapter *adapter, u8 group_macid,
			       u8 rpt_type, u32 macid_bitmap);
#endif
