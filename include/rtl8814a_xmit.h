/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
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
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef __RTL8814A_XMIT_H__
#define __RTL8814A_XMIT_H__

typedef struct txdescriptor_8814
{
	// Offset 0
	u32 pktlen:16;
	u32 offset:8;
	u32 bmc:1;
	u32 htc:1;
	u32 ls:1;
}TXDESC_8814, *PTXDESC_8814;


#define OFFSET_SZ	0
#define OFFSET_SHT	16

/*c2h-DWORD 2*/
#define GET_RX_STATUS_DESC_RPT_SEL_8814A(__pRxDesc)			LE_BITS_TO_4BYTE(__pRxDesc+8, 28, 1)

//=====Desc content
//TX Info
//=============
// Dword 0
#define SET_TX_DESC_PKT_SIZE_8814A(__pTxDesc, __Value) 						SET_BITS_TO_LE_4BYTE(__pTxDesc, 0, 16, __Value)
#define SET_TX_DESC_OFFSET_8814A(__pTxDesc, __Value) 							SET_BITS_TO_LE_4BYTE(__pTxDesc, 16, 8, __Value)
#define SET_TX_DESC_BMC_8814A(__pTxDesc, __Value) 							SET_BITS_TO_LE_4BYTE(__pTxDesc, 24, 1, __Value)
#define SET_TX_DESC_LAST_SEG_8814A(__pTxDesc, __Value) 						SET_BITS_TO_LE_4BYTE(__pTxDesc, 26, 1, __Value)
#define SET_TX_DESC_DISQSELSEQ_8814A(__pTxDesc, __Value) 						SET_BITS_TO_LE_4BYTE(__pTxDesc, 31, 1, __Value)

// Dword 1
#define SET_TX_DESC_MACID_8814A(__pTxDesc, __Value) 							SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 0, 7, __Value)
#define SET_TX_DESC_QUEUE_SEL_8814A(__pTxDesc, __Value) 						SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 8, 5, __Value)
#define SET_TX_DESC_RATE_ID_8814A(__pTxDesc, __Value) 							SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 16, 5, __Value)
#define SET_TX_DESC_SEC_TYPE_8814A(__pTxDesc, __Value) 						SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 22, 2, __Value)
#define SET_TX_DESC_PKT_OFFSET_8814A(__pTxDesc, __Value) 						SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 24, 5, __Value)


// Dword 2
#define SET_TX_DESC_PAID_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 0,  9, __Value)
#define SET_TX_DESC_AGG_ENABLE_8814A(__pTxDesc, __Value) 		SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 12, 1, __Value)
#define SET_TX_DESC_BK_8814A(__pTxDesc, __Value) 				SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 16, 1, __Value)
#define SET_TX_DESC_AMPDU_DENSITY_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 20, 3, __Value)
#define SET_TX_DESC_GID_8814A(__pTxDesc, __Value) 			SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 24, 6, __Value)


// Dword 3
#define SET_TX_DESC_HW_SSN_SEL_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 6, 2, __Value)
#define SET_TX_DESC_USE_RATE_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 8, 1, __Value)
#define SET_TX_DESC_DISABLE_FB_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 10, 1, __Value)
#define SET_TX_DESC_CTS2SELF_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 11, 1, __Value)
#define SET_TX_DESC_RTS_ENABLE_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 12, 1, __Value)
#define SET_TX_DESC_NAV_USE_HDR_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 15, 1, __Value)
#define SET_TX_DESC_MAX_AGG_NUM_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 17, 5, __Value)
#define SET_TX_DESC_NDPA_8814A(__pTxDesc, __Value) 		SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 22, 2, __Value)

// Dword 4
#define SET_TX_DESC_TX_RATE_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 0, 7, __Value)
#define SET_TX_DESC_DATA_RATE_FB_LIMIT_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 8, 5, __Value)
#define SET_TX_DESC_RTS_RATE_FB_LIMIT_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 13, 4, __Value)
#define SET_TX_DESC_RETRY_LIMIT_ENABLE_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 17, 1, __Value)
#define SET_TX_DESC_DATA_RETRY_LIMIT_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 18, 6, __Value)
#define SET_TX_DESC_RTS_RATE_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 24, 5, __Value)


// Dword 5
#define SET_TX_DESC_DATA_SC_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 0, 4, __Value)
#define SET_TX_DESC_DATA_SHORT_8814A(__pTxDesc, __Value) 	SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 4, 1, __Value)
#define SET_TX_DESC_DATA_BW_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 5, 2, __Value)
#define SET_TX_DESC_DATA_LDPC_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 7, 1, __Value)
#define SET_TX_DESC_DATA_STBC_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 8, 2, __Value)
#define SET_TX_DESC_RTS_SHORT_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 12, 1, __Value)
#define SET_TX_DESC_RTS_SC_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 13, 4, __Value)

// Dword 6
#define SET_TX_DESC_SW_DEFINE_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 0, 12, __Value)


// Dword 7
#define SET_TX_DESC_TX_DESC_CHECKSUM_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+28, 0, 16, __Value)
#define SET_TX_DESC_USB_TXAGG_NUM_8814A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+28, 24, 8, __Value)


// Dword 8
#define SET_TX_DESC_EN_HWEXSEQ_8814A(__pTxDesc, __Value) 			SET_BITS_TO_LE_4BYTE(__pTxDesc+32, 14, 1, __Value)
#define SET_TX_DESC_HWSEQ_EN_8814A(__pTxDesc, __Value) 			SET_BITS_TO_LE_4BYTE(__pTxDesc+32, 15, 1, __Value)

// Dword 9
#define SET_TX_DESC_SEQ_8814A(__pTxDesc, __Value) 										SET_BITS_TO_LE_4BYTE(__pTxDesc+36, 12, 12, __Value)



#define SET_EARLYMODE_PKTNUM_8814A(__pAddr, __Value)					SET_BITS_TO_LE_4BYTE(__pAddr, 0, 4, __Value)
#define SET_EARLYMODE_LEN0_8814A(__pAddr, __Value) 					SET_BITS_TO_LE_4BYTE(__pAddr, 4, 15, __Value)
#define SET_EARLYMODE_LEN1_1_8814A(__pAddr, __Value) 					SET_BITS_TO_LE_4BYTE(__pAddr, 19, 13, __Value)
#define SET_EARLYMODE_LEN1_2_8814A(__pAddr, __Value) 					SET_BITS_TO_LE_4BYTE(__pAddr+4, 0, 2, __Value)
#define SET_EARLYMODE_LEN2_8814A(__pAddr, __Value) 					SET_BITS_TO_LE_4BYTE(__pAddr+4, 2, 15,  __Value)
#define SET_EARLYMODE_LEN3_8814A(__pAddr, __Value) 					SET_BITS_TO_LE_4BYTE(__pAddr+4, 17, 15, __Value)


void rtl8814a_cal_txdesc_chksum(u8 *ptxdesc);
void rtl8814a_fill_fake_txdesc(PADAPTER	padapter,u8*pDesc,u32 BufferLen,u8 IsPsPoll,u8	IsBTQosNull, u8 bDataFrame);
void rtl8814a_fill_txdesc_sectype(struct pkt_attrib *pattrib, u8 *ptxdesc);
void rtl8814a_fill_txdesc_vcs(PADAPTER padapter, struct pkt_attrib *pattrib, u8 *ptxdesc);
void rtl8814a_fill_txdesc_phy(PADAPTER padapter, struct pkt_attrib *pattrib, u8 *ptxdesc);

s32 rtl8814au_init_xmit_priv(PADAPTER padapter);
void rtl8814au_free_xmit_priv(PADAPTER padapter);
s32 rtl8814au_hal_xmit(PADAPTER padapter, struct xmit_frame *pxmitframe);
s32 rtl8814au_mgnt_xmit(PADAPTER padapter, struct xmit_frame *pmgntframe);
s32	 rtl8814au_hal_xmitframe_enqueue(_adapter *padapter, struct xmit_frame *pxmitframe);
s32 rtl8814au_xmit_buf_handler(PADAPTER padapter);
void rtl8814au_xmit_tasklet(void *priv);
s32 rtl8814au_xmitframe_complete(_adapter *padapter, struct xmit_priv *pxmitpriv, struct xmit_buf *pxmitbuf);


void _dbg_dump_tx_info(_adapter	*padapter,int frame_tag, u8 *ptxdesc);
u8
SCMapping_8814(
	IN	PADAPTER		Adapter,
	IN	struct pkt_attrib	*pattrib
);

u8
BWMapping_8814(
	IN	PADAPTER		Adapter,
	IN	struct pkt_attrib	*pattrib
);


#endif /* __RTL8814_XMIT_H__ */

