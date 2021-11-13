/******************************************************************************
 *
 * Copyright(c) 2007 - 2019 Realtek Corporation.
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
#define _RTW_DEBUG_C_

#include <drv_types.h>
#include <hal_data.h>

#ifdef CONFIG_RTW_DEBUG
const char *rtw_log_level_str[] = {
	"_DRV_NONE_ = 0",
	"_DRV_ALWAYS_ = 1",
	"_DRV_ERR_ = 2",
	"_DRV_WARNING_ = 3",
	"_DRV_INFO_ = 4",
	"_DRV_DEBUG_ = 5",
	"_DRV_MAX_ = 6",
};
#endif

#ifdef CONFIG_DEBUG_RTL871X
	u64 GlobalDebugComponents = 0;
#endif /* CONFIG_DEBUG_RTL871X */

#include <rtw_version.h>

void dump_drv_version(void *sel)
{
	RTW_PRINT_SEL(sel, "%s %s\n", DRV_NAME, DRIVERVERSION);
	RTW_PRINT_SEL(sel, "build time: %s %s\n", __DATE__, __TIME__);
}

void dump_drv_cfg(void *sel)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 24))
	char *kernel_version = utsname()->release;

	RTW_PRINT_SEL(sel, "\nKernel Version: %s\n", kernel_version);
#endif

	RTW_PRINT_SEL(sel, "Driver Version: %s\n", DRIVERVERSION);
	RTW_PRINT_SEL(sel, "------------------------------------------------\n");
#ifdef CONFIG_IOCTL_CFG80211
	RTW_PRINT_SEL(sel, "CFG80211\n");
#ifdef RTW_USE_CFG80211_STA_EVENT
	RTW_PRINT_SEL(sel, "RTW_USE_CFG80211_STA_EVENT\n");
#endif
	#ifdef CONFIG_RADIO_WORK
	RTW_PRINT_SEL(sel, "CONFIG_RADIO_WORK\n");
	#endif
#else
	RTW_PRINT_SEL(sel, "WEXT\n");
#endif

	RTW_PRINT_SEL(sel, "DBG:%d\n", DBG);
#ifdef CONFIG_RTW_DEBUG
	RTW_PRINT_SEL(sel, "CONFIG_RTW_DEBUG\n");
#endif

#ifdef CONFIG_CONCURRENT_MODE
	RTW_PRINT_SEL(sel, "CONFIG_CONCURRENT_MODE\n");
#endif

#ifdef CONFIG_POWER_SAVING
	RTW_PRINT_SEL(sel, "CONFIG_POWER_SAVING\n");
	#ifdef CONFIG_IPS
	RTW_PRINT_SEL(sel, "CONFIG_IPS\n");
	#endif
	#ifdef CONFIG_LPS
		RTW_PRINT_SEL(sel, "CONFIG_LPS\n");
		#ifdef CONFIG_LPS_LCLK
		RTW_PRINT_SEL(sel, "CONFIG_LPS_LCLK\n");
		#ifdef CONFIG_DETECT_CPWM_BY_POLLING
		RTW_PRINT_SEL(sel, "CONFIG_DETECT_CPWM_BY_POLLING\n");
		#endif
		#endif /*CONFIG_LPS_LCLK*/
		#ifdef CONFIG_LPS_CHK_BY_TP
		RTW_PRINT_SEL(sel, "CONFIG_LPS_CHK_BY_TP\n");
		#endif
		#ifdef CONFIG_LPS_ACK
		RTW_PRINT_SEL(sel, "CONFIG_LPS_ACK\n");
		#endif
	#endif/*CONFIG_LPS*/
#endif

	RTW_PRINT_SEL(sel, "RTW_DEF_MODULE_REGULATORY_CERT=0x%02x\n", RTW_DEF_MODULE_REGULATORY_CERT);

	RTW_PRINT_SEL(sel, "CONFIG_TXPWR_BY_RATE=%d\n", CONFIG_TXPWR_BY_RATE);
	RTW_PRINT_SEL(sel, "CONFIG_TXPWR_BY_RATE_EN=%d\n", CONFIG_TXPWR_BY_RATE_EN);
	RTW_PRINT_SEL(sel, "CONFIG_TXPWR_LIMIT=%d\n", CONFIG_TXPWR_LIMIT);
	RTW_PRINT_SEL(sel, "CONFIG_TXPWR_LIMIT_EN=%d\n", CONFIG_TXPWR_LIMIT_EN);


#ifdef CONFIG_DISABLE_ODM
	RTW_PRINT_SEL(sel, "CONFIG_DISABLE_ODM\n");
#endif

#ifdef CONFIG_MINIMAL_MEMORY_USAGE
	RTW_PRINT_SEL(sel, "CONFIG_MINIMAL_MEMORY_USAGE\n");
#endif

	RTW_PRINT_SEL(sel, "CONFIG_RTW_ADAPTIVITY_EN = %d\n", CONFIG_RTW_ADAPTIVITY_EN);
#if (CONFIG_RTW_ADAPTIVITY_EN)
	RTW_PRINT_SEL(sel, "ADAPTIVITY_MODE = %s\n", (CONFIG_RTW_ADAPTIVITY_MODE) ? "carrier_sense" : "normal");
#endif

#ifdef CONFIG_RTW_80211R
	RTW_PRINT_SEL(sel, "CONFIG_RTW_80211R\n");
#endif

#ifdef CONFIG_RTW_NETIF_SG
	RTW_PRINT_SEL(sel, "CONFIG_RTW_NETIF_SG\n");
#endif

#ifdef CONFIG_RTW_WIFI_HAL
	RTW_PRINT_SEL(sel, "CONFIG_RTW_WIFI_HAL\n");
#endif

#ifdef CONFIG_RTW_TPT_MODE
	RTW_PRINT_SEL(sel, "CONFIG_RTW_TPT_MODE\n");
#endif 

#ifdef CONFIG_USB_HCI
#ifdef CONFIG_USB_INTERRUPT_IN_PIPE
	RTW_PRINT_SEL(sel, "CONFIG_USB_INTERRUPT_IN_PIPE\n");
#endif
#ifdef CONFIG_USB_TX_AGGREGATION
	RTW_PRINT_SEL(sel, "CONFIG_USB_TX_AGGREGATION\n");
#endif
#ifdef CONFIG_USB_RX_AGGREGATION
	RTW_PRINT_SEL(sel, "CONFIG_USB_RX_AGGREGATION\n");
#endif
#ifdef CONFIG_USE_USB_BUFFER_ALLOC_TX
	RTW_PRINT_SEL(sel, "CONFIG_USE_USB_BUFFER_ALLOC_TX\n");
#endif
#ifdef CONFIG_USE_USB_BUFFER_ALLOC_RX
	RTW_PRINT_SEL(sel, "CONFIG_USE_USB_BUFFER_ALLOC_RX\n");
#endif
#ifdef CONFIG_PREALLOC_RECV_SKB
	RTW_PRINT_SEL(sel, "CONFIG_PREALLOC_RECV_SKB\n");
#endif
#ifdef CONFIG_FIX_NR_BULKIN_BUFFER
	RTW_PRINT_SEL(sel, "CONFIG_FIX_NR_BULKIN_BUFFER\n");
#endif
#endif /*CONFIG_USB_HCI*/

	RTW_PRINT_SEL(sel, "CONFIG_IFACE_NUMBER = %d\n", CONFIG_IFACE_NUMBER);
#ifdef CONFIG_MI_WITH_MBSSID_CAM
	RTW_PRINT_SEL(sel, "CONFIG_MI_WITH_MBSSID_CAM\n");
#endif
#ifdef CONFIG_SWTIMER_BASED_TXBCN
	RTW_PRINT_SEL(sel, "CONFIG_SWTIMER_BASED_TXBCN\n");
#endif
#ifdef CONFIG_FW_HANDLE_TXBCN
	RTW_PRINT_SEL(sel, "CONFIG_FW_HANDLE_TXBCN\n");
	RTW_PRINT_SEL(sel, "CONFIG_LIMITED_AP_NUM = %d\n", CONFIG_LIMITED_AP_NUM);
#endif
#ifdef CONFIG_CLIENT_PORT_CFG
	RTW_PRINT_SEL(sel, "CONFIG_CLIENT_PORT_CFG\n");
#endif
#ifdef CONFIG_PCI_TX_POLLING
	RTW_PRINT_SEL(sel, "CONFIG_PCI_TX_POLLING\n");
#endif
	RTW_PRINT_SEL(sel, "CONFIG_RTW_UP_MAPPING_RULE = %s\n", (CONFIG_RTW_UP_MAPPING_RULE == 1) ? "dscp" : "tos");

	RTW_PRINT_SEL(sel, "\n=== XMIT-INFO ===\n");
	RTW_PRINT_SEL(sel, "NR_XMITFRAME = %d\n", NR_XMITFRAME);
	RTW_PRINT_SEL(sel, "NR_XMITBUFF = %d\n", NR_XMITBUFF);
	RTW_PRINT_SEL(sel, "MAX_XMITBUF_SZ = %d\n", MAX_XMITBUF_SZ);
	RTW_PRINT_SEL(sel, "NR_XMIT_EXTBUFF = %d\n", NR_XMIT_EXTBUFF);
	RTW_PRINT_SEL(sel, "MAX_XMIT_EXTBUF_SZ = %d\n", MAX_XMIT_EXTBUF_SZ);
	RTW_PRINT_SEL(sel, "MAX_CMDBUF_SZ = %d\n", MAX_CMDBUF_SZ);

	RTW_PRINT_SEL(sel, "\n=== RECV-INFO ===\n");
	RTW_PRINT_SEL(sel, "NR_RECVFRAME = %d\n", NR_RECVFRAME);
	RTW_PRINT_SEL(sel, "NR_RECVBUFF = %d\n", NR_RECVBUFF);
	RTW_PRINT_SEL(sel, "MAX_RECVBUF_SZ = %d\n", MAX_RECVBUF_SZ);

}

void dump_log_level(void *sel)
{
#ifdef CONFIG_RTW_DEBUG
	int i;

	RTW_PRINT_SEL(sel, "drv_log_level:%d\n", rtw_drv_log_level);
	for (i = 0; i <= _DRV_MAX_; i++) {
		if (rtw_log_level_str[i])
			RTW_PRINT_SEL(sel, "%c %s = %d\n",
				(rtw_drv_log_level == i) ? '+' : ' ', rtw_log_level_str[i], i);
	}
#else
	RTW_PRINT_SEL(sel, "CONFIG_RTW_DEBUG is disabled\n");
#endif
}

void mac_reg_dump(void *sel, _adapter *adapter)
{
	int i, j = 1;

	RTW_PRINT_SEL(sel, "======= MAC REG =======\n");

	for (i = 0x0; i < 0x800; i += 4) {
		if (j % 4 == 1)
			RTW_PRINT_SEL(sel, "0x%04x", i);
		_RTW_PRINT_SEL(sel, " 0x%08x ", rtw_read32(adapter, i));
		if ((j++) % 4 == 0)
			_RTW_PRINT_SEL(sel, "\n");
	}

#ifdef CONFIG_RTL8814A
	{
		for (i = 0x1000; i < 0x1650; i += 4) {
			if (j % 4 == 1)
				RTW_PRINT_SEL(sel, "0x%04x", i);
			_RTW_PRINT_SEL(sel, " 0x%08x ", rtw_read32(adapter, i));
			if ((j++) % 4 == 0)
				_RTW_PRINT_SEL(sel, "\n");
		}
	}
#endif /* CONFIG_RTL8814A */

#if defined(CONFIG_RTL8822B) || defined(CONFIG_RTL8821C) ||defined(CONFIG_RTL8192F) || defined(CONFIG_RTL8822C) || defined(CONFIG_RTL8814B)
	for (i = 0x1000; i < 0x1800; i += 4) {
		if (j % 4 == 1)
			RTW_PRINT_SEL(sel, "0x%04x", i);
		_RTW_PRINT_SEL(sel, " 0x%08x ", rtw_read32(adapter, i));
		if ((j++) % 4 == 0)
			_RTW_PRINT_SEL(sel, "\n");
	}
#endif /* CONFIG_RTL8822B  or 8821c or 8192f*/

#if defined(CONFIG_RTL8814B)
	for (i = 0x2000; i < 0x2800; i += 4) {
		if (j % 4 == 1)
			RTW_PRINT_SEL(sel, "0x%04x", i);
		_RTW_PRINT_SEL(sel, " 0x%08x ", rtw_read32(adapter, i));
		if ((j++) % 4 == 0)
			_RTW_PRINT_SEL(sel, "\n");
	}

	for (i = 0x3000; i < 0x3800; i += 4) {
		if (j % 4 == 1)
			RTW_PRINT_SEL(sel, "0x%04x", i);
		_RTW_PRINT_SEL(sel, " 0x%08x ", rtw_read32(adapter, i));
		if ((j++) % 4 == 0)
			_RTW_PRINT_SEL(sel, "\n");
	}
#endif

}

void bb_reg_dump(void *sel, _adapter *adapter)
{
	int i, j = 1;

	RTW_PRINT_SEL(sel, "======= BB REG =======\n");
	for (i = 0x800; i < 0x1000; i += 4) {
		if (j % 4 == 1)
			RTW_PRINT_SEL(sel, "0x%04x", i);
		_RTW_PRINT_SEL(sel, " 0x%08x ", rtw_read32(adapter, i));
		if ((j++) % 4 == 0)
			_RTW_PRINT_SEL(sel, "\n");
	}

#if defined(CONFIG_RTL8822B) || defined(CONFIG_RTL8821C) || defined(CONFIG_RTL8822C) || defined(CONFIG_RTL8814B)
	for (i = 0x1800; i < 0x2000; i += 4) {
		if (j % 4 == 1)
			RTW_PRINT_SEL(sel, "0x%04x", i);
		_RTW_PRINT_SEL(sel, " 0x%08x ", rtw_read32(adapter, i));
		if ((j++) % 4 == 0)
			_RTW_PRINT_SEL(sel, "\n");
	}
#endif /* CONFIG_RTL8822B */

#if defined(CONFIG_RTL8822C) || defined(CONFIG_RTL8814B)
	for (i = 0x2c00; i < 0x2c60; i += 4) {
		if (j % 4 == 1)
			RTW_PRINT_SEL(sel, "0x%04x", i);
		_RTW_PRINT_SEL(sel, " 0x%08x ", rtw_read32(adapter, i));
		if ((j++) % 4 == 0)
			_RTW_PRINT_SEL(sel, "\n");
	}

	for (i = 0x2d00; i < 0x2df0; i += 4) {
		if (j % 4 == 1)
			RTW_PRINT_SEL(sel, "0x%04x", i);
		_RTW_PRINT_SEL(sel, " 0x%08x ", rtw_read32(adapter, i));
		if ((j++) % 4 == 0)
			_RTW_PRINT_SEL(sel, "\n");
	}	

	for (i = 0x4000; i < 0x4060; i += 4) {
		if (j % 4 == 1)
			RTW_PRINT_SEL(sel, "0x%04x", i);
		_RTW_PRINT_SEL(sel, " 0x%08x ", rtw_read32(adapter, i));
		if ((j++) % 4 == 0)
			_RTW_PRINT_SEL(sel, "\n");
	}	

	for (i = 0x4100; i < 0x4200; i += 4) {
		if (j % 4 == 1)
			RTW_PRINT_SEL(sel, "0x%04x", i);
		_RTW_PRINT_SEL(sel, " 0x%08x ", rtw_read32(adapter, i));
		if ((j++) % 4 == 0)
			_RTW_PRINT_SEL(sel, "\n");
	}	

#endif /* CONFIG_RTL8822C || CONFIG_RTL8814B */

#if defined(CONFIG_RTL8814B)
	for (i = 0x5200; i < 0x5400; i += 4) {
		if (j % 4 == 1)
			RTW_PRINT_SEL(sel, "0x%04x", i);
		_RTW_PRINT_SEL(sel, " 0x%08x ", rtw_read32(adapter, i));
		if ((j++) % 4 == 0)
			_RTW_PRINT_SEL(sel, "\n");
	}
#endif /* CONFIG_RTL8814B */
}

void bb_reg_dump_ex(void *sel, _adapter *adapter)
{
	int i;

	RTW_PRINT_SEL(sel, "======= BB REG =======\n");
	for (i = 0x800; i < 0x1000; i += 4) {
		RTW_PRINT_SEL(sel, "0x%04x", i);
		_RTW_PRINT_SEL(sel, " 0x%08x ", rtw_read32(adapter, i));
		_RTW_PRINT_SEL(sel, "\n");
	}

#if defined(CONFIG_RTL8822B) || defined(CONFIG_RTL8821C) || defined(CONFIG_RTL8822C) || defined(CONFIG_RTL8814B)
	for (i = 0x1800; i < 0x2000; i += 4) {
		RTW_PRINT_SEL(sel, "0x%04x", i);
		_RTW_PRINT_SEL(sel, " 0x%08x ", rtw_read32(adapter, i));
		_RTW_PRINT_SEL(sel, "\n");
	}
#endif /* CONFIG_RTL8822B */
}

void rf_reg_dump(void *sel, _adapter *adapter)
{
	int i, j = 1, path;
	u32 value;
	u8 path_nums = GET_HAL_RFPATH_NUM(adapter);

	RTW_PRINT_SEL(sel, "======= RF REG =======\n");

	for (path = 0; path < path_nums; path++) {
		RTW_PRINT_SEL(sel, "RF_Path(%x)\n", path);
		for (i = 0; i < 0x100; i++) {
			value = rtw_hal_read_rfreg(adapter, path, i, 0xffffffff);
			if (j % 4 == 1)
				RTW_PRINT_SEL(sel, "0x%02x ", i);
			_RTW_PRINT_SEL(sel, " 0x%08x ", value);
			if ((j++) % 4 == 0)
				_RTW_PRINT_SEL(sel, "\n");
		}
	}
}

void rtw_sink_rtp_seq_dbg(_adapter *adapter, u8 *ehdr_pos)
{
	struct recv_priv *precvpriv = &(adapter->recvpriv);
	if (precvpriv->sink_udpport > 0) {
		if (*((u16 *)(ehdr_pos + 0x24)) == cpu_to_be16(precvpriv->sink_udpport)) {
			precvpriv->pre_rtp_rxseq = precvpriv->cur_rtp_rxseq;
			precvpriv->cur_rtp_rxseq = be16_to_cpu(*((u16 *)(ehdr_pos + 0x2C)));
			if (precvpriv->pre_rtp_rxseq + 1 != precvpriv->cur_rtp_rxseq) {
				if(precvpriv->pre_rtp_rxseq == 65535 ) {
					if( precvpriv->cur_rtp_rxseq != 0) {
						RTW_INFO("%s : RTP Seq num from %d to %d\n", __FUNCTION__, precvpriv->pre_rtp_rxseq, precvpriv->cur_rtp_rxseq);
					}
				} else {
					RTW_INFO("%s : RTP Seq num from %d to %d\n", __FUNCTION__, precvpriv->pre_rtp_rxseq, precvpriv->cur_rtp_rxseq);
				}
			}	
		}
	}
}

void sta_rx_reorder_ctl_dump(void *sel, struct sta_info *sta)
{
	struct recv_reorder_ctrl *reorder_ctl;
	int i;

	for (i = 0; i < 16; i++) {
		reorder_ctl = &sta->recvreorder_ctrl[i];
		if (reorder_ctl->ampdu_size != RX_AMPDU_SIZE_INVALID || reorder_ctl->indicate_seq != 0xFFFF) {
			RTW_PRINT_SEL(sel, "tid=%d, enable=%d, ampdu_size=%u, indicate_seq=%u\n"
				, i, reorder_ctl->enable, reorder_ctl->ampdu_size, reorder_ctl->indicate_seq
				     );
		}
	}
}

void dump_tx_rate_bmp(void *sel, struct dvobj_priv *dvobj)
{
	_adapter *adapter = dvobj_get_primary_adapter(dvobj);
	struct rf_ctl_t *rfctl = dvobj_to_rfctl(dvobj);
	u8 bw;

	RTW_PRINT_SEL(sel, "%-6s", "bw");
	if (hal_chk_proto_cap(adapter, PROTO_CAP_11AC))
		_RTW_PRINT_SEL(sel, " %-15s", "vht");

	_RTW_PRINT_SEL(sel, " %-11s %-4s %-3s\n", "ht", "ofdm", "cck");

	for (bw = CHANNEL_WIDTH_20; bw <= CHANNEL_WIDTH_160; bw++) {
		if (!hal_is_bw_support(adapter, bw))
			continue;

		RTW_PRINT_SEL(sel, "%6s", ch_width_str(bw));
		if (hal_chk_proto_cap(adapter, PROTO_CAP_11AC)) {
			_RTW_PRINT_SEL(sel, " %03x %03x %03x %03x"
				, RATE_BMP_GET_VHT_4SS(rfctl->rate_bmp_vht_by_bw[bw])
				, RATE_BMP_GET_VHT_3SS(rfctl->rate_bmp_vht_by_bw[bw])
				, RATE_BMP_GET_VHT_2SS(rfctl->rate_bmp_vht_by_bw[bw])
				, RATE_BMP_GET_VHT_1SS(rfctl->rate_bmp_vht_by_bw[bw])
			);
		}

		_RTW_PRINT_SEL(sel, " %02x %02x %02x %02x"
			, bw <= CHANNEL_WIDTH_40 ? RATE_BMP_GET_HT_4SS(rfctl->rate_bmp_ht_by_bw[bw]) : 0
			, bw <= CHANNEL_WIDTH_40 ? RATE_BMP_GET_HT_3SS(rfctl->rate_bmp_ht_by_bw[bw]) : 0
			, bw <= CHANNEL_WIDTH_40 ? RATE_BMP_GET_HT_2SS(rfctl->rate_bmp_ht_by_bw[bw]) : 0
			, bw <= CHANNEL_WIDTH_40 ? RATE_BMP_GET_HT_1SS(rfctl->rate_bmp_ht_by_bw[bw]) : 0
		);

		_RTW_PRINT_SEL(sel, "  %03x   %01x\n"
			, bw <= CHANNEL_WIDTH_20 ? RATE_BMP_GET_OFDM(rfctl->rate_bmp_cck_ofdm) : 0
			, bw <= CHANNEL_WIDTH_20 ? RATE_BMP_GET_CCK(rfctl->rate_bmp_cck_ofdm) : 0
		);
	}
}

void dump_adapters_status(void *sel, struct dvobj_priv *dvobj)
{
	struct rf_ctl_t *rfctl = dvobj_to_rfctl(dvobj);
	int i;
	_adapter *iface;
	u8 u_ch, u_bw, u_offset;
#if (defined(CONFIG_SUPPORT_MULTI_BCN) && defined(CONFIG_FW_HANDLE_TXBCN)) || defined(CONFIG_CLIENT_PORT_CFG)
	char str_val[64] = {'\0'};
#endif
	dump_mi_status(sel, dvobj);

#if defined(CONFIG_SUPPORT_MULTI_BCN) && defined(CONFIG_FW_HANDLE_TXBCN)
	RTW_PRINT_SEL(sel, "[AP] LIMITED_AP_NUM:%d\n", CONFIG_LIMITED_AP_NUM);
	RTW_PRINT_SEL(sel, "[AP] vap_map:0x%02x\n", dvobj->vap_map);
#endif
#ifdef CONFIG_HW_P0_TSF_SYNC
	RTW_PRINT_SEL(sel, "[AP] p0 tsf sync port = %d\n", dvobj->p0_tsf.sync_port);
	RTW_PRINT_SEL(sel, "[AP] p0 tsf timer offset = %d\n", dvobj->p0_tsf.offset);
#endif
#ifdef CONFIG_CLIENT_PORT_CFG
	RTW_PRINT_SEL(sel, "[CLT] clt_num = %d\n", dvobj->clt_port.num);
	RTW_PRINT_SEL(sel, "[CLT] clt_map = 0x%02x\n", dvobj->clt_port.bmp);
#endif
#ifdef CONFIG_FW_MULTI_PORT_SUPPORT
	RTW_PRINT_SEL(sel, "[MI] default port id:%d\n\n", dvobj->dft.port_id);
#endif /* CONFIG_FW_MULTI_PORT_SUPPORT */

	RTW_PRINT_SEL(sel, "dev status:%s%s\n\n"
		, dev_is_surprise_removed(dvobj) ? " SR" : ""
		, dev_is_drv_stopped(dvobj) ? " DS" : ""
	);

#define P2P_INFO_TITLE_FMT	""
#define P2P_INFO_TITLE_ARG
#define P2P_INFO_VALUE_FMT	""
#define P2P_INFO_VALUE_ARG
#define P2P_INFO_DASH

#ifdef DBG_TSF_UPDATE
#define TSF_PAUSE_TIME_TITLE_FMT " %-5s"
#define TSF_PAUSE_TIME_TITLE_ARG , "tsfup"
#define TSF_PAUSE_TIME_VALUE_FMT " %5d"
#define TSF_PAUSE_TIME_VALUE_ARG , ((iface->mlmeextpriv.tsf_update_required && iface->mlmeextpriv.tsf_update_pause_stime) ? (rtw_get_passing_time_ms(iface->mlmeextpriv.tsf_update_pause_stime) > 99999 ? 99999 : rtw_get_passing_time_ms(iface->mlmeextpriv.tsf_update_pause_stime)) : 0)
#else
#define TSF_PAUSE_TIME_TITLE_FMT ""
#define TSF_PAUSE_TIME_TITLE_ARG
#define TSF_PAUSE_TIME_VALUE_FMT ""
#define TSF_PAUSE_TIME_VALUE_ARG
#endif

#if (defined(CONFIG_SUPPORT_MULTI_BCN) && defined(CONFIG_FW_HANDLE_TXBCN)) || defined(CONFIG_CLIENT_PORT_CFG)
#define INFO_FMT	" %-4s"
#define INFO_ARG	, "info"
#define INFO_CNT_FMT	" %-20s"
#define INFO_CNT_ARG	, str_val
#else
#define INFO_FMT	""
#define INFO_ARG
#define INFO_CNT_FMT	""
#define INFO_CNT_ARG
#endif

	RTW_PRINT_SEL(sel, "%-2s %-15s %c %-3s %-3s %-3s %-17s %-4s %-7s"
		P2P_INFO_TITLE_FMT
		TSF_PAUSE_TIME_TITLE_FMT
		" %s"INFO_FMT"\n"
		, "id", "ifname", ' ', "bup", "nup", "ncd", "macaddr", "port", "ch"
		P2P_INFO_TITLE_ARG
		TSF_PAUSE_TIME_TITLE_ARG
		, "status"INFO_ARG);

	RTW_PRINT_SEL(sel, "---------------------------------------------------------------"
		P2P_INFO_DASH
		"-------\n");

	for (i = 0; i < dvobj->iface_nums; i++) {
		iface = dvobj->padapters[i];
		if (iface) {
			#if (defined(CONFIG_SUPPORT_MULTI_BCN) && defined(CONFIG_FW_HANDLE_TXBCN)) || defined(CONFIG_CLIENT_PORT_CFG)
			_rtw_memset(&str_val, '\0', sizeof(str_val));
			#endif
			#if defined(CONFIG_SUPPORT_MULTI_BCN) && defined(CONFIG_FW_HANDLE_TXBCN)
			if (MLME_IS_AP(iface) || MLME_IS_MESH(iface)) {
				u8 len;
				char *p = str_val;
				char tmp_str[10] = {'\0'};

				len = snprintf(tmp_str, sizeof(tmp_str), "%s", "ap_id:");
				strncpy(p, tmp_str, len);
				p += len;
				_rtw_memset(&tmp_str, '\0', sizeof(tmp_str));
				#ifdef DBG_HW_PORT
				len = snprintf(tmp_str, sizeof(tmp_str), "%d (%d,%d)", iface->vap_id, iface->hw_port, iface->client_port);
				#else
				len = snprintf(tmp_str, sizeof(tmp_str), "%d", iface->vap_id);
				#endif
				strncpy(p, tmp_str, len);
			}
			#endif
			#ifdef CONFIG_CLIENT_PORT_CFG
			if (MLME_IS_STA(iface)) {
				u8 len;
				char *p = str_val;
				char tmp_str[10] = {'\0'};

				len = snprintf(tmp_str, sizeof(tmp_str), "%s", "c_pid:");
				strncpy(p, tmp_str, len);
				p += len;
				_rtw_memset(&tmp_str, '\0', sizeof(tmp_str));
				#ifdef DBG_HW_PORT
				len = snprintf(tmp_str, sizeof(tmp_str), "%d (%d,%d)", iface->client_port, iface->hw_port, iface->client_port);
				#else
				len = snprintf(tmp_str, sizeof(tmp_str), "%d", iface->client_port);
				#endif
				strncpy(p, tmp_str, len);
			}
			#endif

			RTW_PRINT_SEL(sel, "%2d %-15s %c %3u %3u %3u "MAC_FMT" %4hhu %3u,%u,%u"
				P2P_INFO_VALUE_FMT
				TSF_PAUSE_TIME_VALUE_FMT
				" "MLME_STATE_FMT" " INFO_CNT_FMT"\n"
				, i, iface->registered ? ADPT_ARG(iface) : NULL
				, iface->registered ? 'R' : ' '
				, iface->bup
				, iface->netif_up
				, iface->net_closed
				, MAC_ARG(adapter_mac_addr(iface))
				, rtw_hal_get_port(iface)
				, iface->mlmeextpriv.cur_channel
				, iface->mlmeextpriv.cur_bwmode
				, iface->mlmeextpriv.cur_ch_offset
				P2P_INFO_VALUE_ARG
				TSF_PAUSE_TIME_VALUE_ARG
				, MLME_STATE_ARG(iface)
				INFO_CNT_ARG
			);
		}
	}

	RTW_PRINT_SEL(sel, "---------------------------------------------------------------"
		P2P_INFO_DASH
		"-------\n");

	if (rtw_mi_get_ch_setting_union(dvobj_get_primary_adapter(dvobj), &u_ch, &u_bw, &u_offset))
		RTW_PRINT_SEL(sel, "%55s %3u,%u,%u\n"
			, "union:"
			, u_ch, u_bw, u_offset);

	RTW_PRINT_SEL(sel, "%55s %3u,%u,%u offch_state:%d\n"
		, "oper:"
		, dvobj->oper_channel
		, dvobj->oper_bwmode
		, dvobj->oper_ch_offset
		, rfctl->offch_state
	);

#ifdef CONFIG_DFS_MASTER
	if (rfctl->radar_detect_ch != 0) {
		RTW_PRINT_SEL(sel, "%55s %3u,%u,%u"
			, "radar_detect:"
			, rfctl->radar_detect_ch
			, rfctl->radar_detect_bw
			, rfctl->radar_detect_offset
		);

		if (rfctl->radar_detect_by_others)
			_RTW_PRINT_SEL(sel, ", by AP of STA link");
		else {
			u32 non_ocp_ms;
			u32 cac_ms;
			u8 dfs_domain = rtw_odm_get_dfs_domain(dvobj);

			_RTW_PRINT_SEL(sel, ", domain:%u", dfs_domain);

			rtw_get_ch_waiting_ms(rfctl
				, rfctl->radar_detect_ch
				, rfctl->radar_detect_bw
				, rfctl->radar_detect_offset
				, &non_ocp_ms
				, &cac_ms
			);

			if (non_ocp_ms)
				_RTW_PRINT_SEL(sel, ", non_ocp:%d", non_ocp_ms);
			if (cac_ms)
				_RTW_PRINT_SEL(sel, ", cac:%d", cac_ms);
		}

		_RTW_PRINT_SEL(sel, "\n");
	}
#endif /* CONFIG_DFS_MASTER */
}

#define SEC_CAM_ENT_ID_TITLE_FMT "%-2s"
#define SEC_CAM_ENT_ID_TITLE_ARG "id"
#define SEC_CAM_ENT_ID_VALUE_FMT "%2u"
#define SEC_CAM_ENT_ID_VALUE_ARG(id) (id)

#define SEC_CAM_ENT_TITLE_FMT "%-6s %-17s %-32s %-3s %-7s %-2s %-2s %-5s"
#define SEC_CAM_ENT_TITLE_ARG "ctrl", "addr", "key", "kid", "type", "MK", "GK", "valid"
#define SEC_CAM_ENT_VALUE_FMT "0x%04x "MAC_FMT" "KEY_FMT" %3u %-7s %2u %2u %5u"
#define SEC_CAM_ENT_VALUE_ARG(ent) \
	(ent)->ctrl \
	, MAC_ARG((ent)->mac) \
	, KEY_ARG((ent)->key) \
	, ((ent)->ctrl) & 0x03 \
	, security_type_str((((ent)->ctrl) >> 2) & 0x07) \
	, (((ent)->ctrl) >> 5) & 0x01 \
	, (((ent)->ctrl) >> 6) & 0x01 \
	, (((ent)->ctrl) >> 15) & 0x01

void dump_sec_cam_ent(void *sel, struct sec_cam_ent *ent, int id)
{
	if (id >= 0) {
		RTW_PRINT_SEL(sel, SEC_CAM_ENT_ID_VALUE_FMT " " SEC_CAM_ENT_VALUE_FMT"\n"
			, SEC_CAM_ENT_ID_VALUE_ARG(id), SEC_CAM_ENT_VALUE_ARG(ent));
	} else
		RTW_PRINT_SEL(sel, SEC_CAM_ENT_VALUE_FMT"\n", SEC_CAM_ENT_VALUE_ARG(ent));
}

void dump_sec_cam_ent_title(void *sel, u8 has_id)
{
	if (has_id) {
		RTW_PRINT_SEL(sel, SEC_CAM_ENT_ID_TITLE_FMT " " SEC_CAM_ENT_TITLE_FMT"\n"
			, SEC_CAM_ENT_ID_TITLE_ARG, SEC_CAM_ENT_TITLE_ARG);
	} else
		RTW_PRINT_SEL(sel, SEC_CAM_ENT_TITLE_FMT"\n", SEC_CAM_ENT_TITLE_ARG);
}

void dump_sec_cam(void *sel, _adapter *adapter)
{
	struct dvobj_priv *dvobj = adapter_to_dvobj(adapter);
	struct cam_ctl_t *cam_ctl = &dvobj->cam_ctl;
	struct sec_cam_ent ent;
	int i;

	RTW_PRINT_SEL(sel, "HW sec cam:\n");
	dump_sec_cam_ent_title(sel, 1);
	for (i = 0; i < cam_ctl->num; i++) {
		rtw_sec_read_cam_ent(adapter, i, (u8 *)(&ent.ctrl), ent.mac, ent.key);
		dump_sec_cam_ent(sel , &ent, i);
	}
}

void dump_sec_cam_cache(void *sel, _adapter *adapter)
{
	struct dvobj_priv *dvobj = adapter_to_dvobj(adapter);
	struct cam_ctl_t *cam_ctl = &dvobj->cam_ctl;
	int i;

	RTW_PRINT_SEL(sel, "SW sec cam cache:\n");
	dump_sec_cam_ent_title(sel, 1);
	for (i = 0; i < cam_ctl->num; i++) {
		if (dvobj->cam_cache[i].ctrl != 0)
			dump_sec_cam_ent(sel, &dvobj->cam_cache[i], i);
	}

}

static u8 fwdl_test_chksum_fail = 0;
static u8 fwdl_test_wintint_rdy_fail = 0;

bool rtw_fwdl_test_trigger_chksum_fail(void)
{
	if (fwdl_test_chksum_fail) {
		RTW_PRINT("fwdl test case: trigger chksum_fail\n");
		fwdl_test_chksum_fail--;
		return _TRUE;
	}
	return _FALSE;
}

bool rtw_fwdl_test_trigger_wintint_rdy_fail(void)
{
	if (fwdl_test_wintint_rdy_fail) {
		RTW_PRINT("fwdl test case: trigger wintint_rdy_fail\n");
		fwdl_test_wintint_rdy_fail--;
		return _TRUE;
	}
	return _FALSE;
}

static u8 del_rx_ampdu_test_no_tx_fail = 0;

bool rtw_del_rx_ampdu_test_trigger_no_tx_fail(void)
{
	if (del_rx_ampdu_test_no_tx_fail) {
		RTW_PRINT("del_rx_ampdu test case: trigger no_tx_fail\n");
		del_rx_ampdu_test_no_tx_fail--;
		return _TRUE;
	}
	return _FALSE;
}

static u32 g_wait_hiq_empty_ms = 0;

u32 rtw_get_wait_hiq_empty_ms(void)
{
	return g_wait_hiq_empty_ms;
}

static systime sta_linking_test_start_time = 0;
static u32 sta_linking_test_wait_ms = 0;
static u8 sta_linking_test_force_fail = 0;

void rtw_sta_linking_test_set_start(void)
{
	sta_linking_test_start_time = rtw_get_current_time();
}

bool rtw_sta_linking_test_wait_done(void)
{
	return rtw_get_passing_time_ms(sta_linking_test_start_time) >= sta_linking_test_wait_ms;
}

bool rtw_sta_linking_test_force_fail(void)
{
	return sta_linking_test_force_fail;
}

#ifdef CONFIG_AP_MODE
static u16 ap_linking_test_force_auth_fail = 0;
static u16 ap_linking_test_force_asoc_fail = 0;

u16 rtw_ap_linking_test_force_auth_fail(void)
{
	return ap_linking_test_force_auth_fail;
}

u16 rtw_ap_linking_test_force_asoc_fail(void)
{
	return ap_linking_test_force_asoc_fail;
}
#endif

#define RTW_BUFDUMP_BSIZE		16
#if 1
inline void RTW_BUF_DUMP_SEL(uint _loglevel, void *sel, u8 *_titlestring,
					bool _idx_show, const u8 *_hexdata, int _hexdatalen)
{
#ifdef CONFIG_RTW_DEBUG
	int __i;
	u8 *ptr = (u8 *)_hexdata;

	if (_loglevel <= rtw_drv_log_level) {
		if (_titlestring) {
			if (sel == RTW_DBGDUMP)
				RTW_PRINT("");
			_RTW_PRINT_SEL(sel, "%s", _titlestring);
			if (_hexdatalen >= RTW_BUFDUMP_BSIZE)
				_RTW_PRINT_SEL(sel, "\n");
		}

		for (__i = 0; __i < _hexdatalen; __i++) {
			if (((__i % RTW_BUFDUMP_BSIZE) == 0) && (_hexdatalen >= RTW_BUFDUMP_BSIZE)) {
				if (sel == RTW_DBGDUMP)
					RTW_PRINT("");
				if (_idx_show)
					_RTW_PRINT_SEL(sel, "0x%03X: ", __i);
			}
			_RTW_PRINT_SEL(sel, "%02X%s", ptr[__i], (((__i + 1) % 4) == 0) ? "  " : " ");
			if ((__i + 1 < _hexdatalen) && ((__i + 1) % RTW_BUFDUMP_BSIZE) == 0)
				_RTW_PRINT_SEL(sel, "\n");
		}
		_RTW_PRINT_SEL(sel, "\n");
	}
#endif
}
#else
inline void _RTW_STR_DUMP_SEL(void *sel, char *str_out)
{
	if (sel == RTW_DBGDUMP)
		_dbgdump("%s\n", str_out);
	#if defined(_seqdump)
	else
		_seqdump(sel, "%s\n", str_out);
	#endif /*_seqdump*/
}
inline void RTW_BUF_DUMP_SEL(uint _loglevel, void *sel, u8 *_titlestring,
					bool _idx_show, u8 *_hexdata, int _hexdatalen)
{
	int __i, len;
	int __j, idx;
	int block_num, remain_byte;
	char str_out[128] = {'\0'};
	char str_val[32] = {'\0'};
	char *p = NULL;
	u8 *ptr = (u8 *)_hexdata;

	if (_loglevel <= rtw_drv_log_level) {
		/*dump title*/
		p = &str_out[0];
		if (_titlestring) {
			if (sel == RTW_DBGDUMP) {
				len = snprintf(str_val, sizeof(str_val), "%s", DRIVER_PREFIX);
				strncpy(p, str_val, len);
				p += len;
			}
			len = snprintf(str_val, sizeof(str_val), "%s", _titlestring);
			strncpy(p, str_val, len);
			p += len;
		}
		if (p != &str_out[0]) {
			_RTW_STR_DUMP_SEL(sel, str_out);
			_rtw_memset(&str_out, '\0', sizeof(str_out));
		}

		/*dump buffer*/
		block_num = _hexdatalen / RTW_BUFDUMP_BSIZE;
		remain_byte = _hexdatalen % RTW_BUFDUMP_BSIZE;
		for (__i = 0; __i < block_num; __i++) {
			p = &str_out[0];
			if (sel == RTW_DBGDUMP) {
				len = snprintf(str_val, sizeof(str_val), "%s", DRIVER_PREFIX);
				strncpy(p, str_val, len);
				p += len;
			}
			if (_idx_show) {
				len = snprintf(str_val, sizeof(str_val), "0x%03X: ", __i * RTW_BUFDUMP_BSIZE);
				strncpy(p, str_val, len);
				p += len;
			}
			for (__j =0; __j < RTW_BUFDUMP_BSIZE; __j++) {
				idx = __i * RTW_BUFDUMP_BSIZE + __j;
				len = snprintf(str_val, sizeof(str_val), "%02X%s", ptr[idx], (((__j + 1) % 4) == 0) ? "  " : " ");
				strncpy(p, str_val, len);
				p += len;
			}
			_RTW_STR_DUMP_SEL(sel, str_out);
			_rtw_memset(&str_out, '\0', sizeof(str_out));
		}

		p = &str_out[0];
		if ((sel == RTW_DBGDUMP) && remain_byte) {
			len = snprintf(str_val, sizeof(str_val), "%s", DRIVER_PREFIX);
			strncpy(p, str_val, len);
			p += len;
		}
		if (_idx_show && remain_byte) {
			len = snprintf(str_val, sizeof(str_val), "0x%03X: ", block_num * RTW_BUFDUMP_BSIZE);
			strncpy(p, str_val, len);
			p += len;
		}
		for (__i = 0; __i < remain_byte; __i++) {
			idx = block_num * RTW_BUFDUMP_BSIZE + __i;
			len = snprintf(str_val, sizeof(str_val), "%02X%s", ptr[idx], (((__i + 1) % 4) == 0) ? "  " : " ");
			strncpy(p, str_val, len);
			p += len;
		}
		_RTW_STR_DUMP_SEL(sel, str_out);
	}
}

#endif
