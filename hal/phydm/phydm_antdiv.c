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

//============================================================
// include files
//============================================================

#include "mp_precomp.h"
#include "phydm_precomp.h"

//======================================================
// when antenna test utility is on or some testing need to disable antenna diversity
// call this function to disable all ODM related mechanisms which will switch antenna.
//======================================================
VOID
ODM_StopAntennaSwitchDm(
	IN		PVOID			pDM_VOID
	)
{
	PDM_ODM_T		pDM_Odm = (PDM_ODM_T)pDM_VOID;
	// disable ODM antenna diversity
	pDM_Odm->SupportAbility &= ~ODM_BB_ANT_DIV;
	ODM_RT_TRACE(pDM_Odm,ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("STOP Antenna Diversity \n"));
}

VOID
ODM_SetAntConfig(
	IN	PVOID	pDM_VOID,
	IN	u1Byte		antSetting	// 0=A, 1=B, 2=C, ....
	)
{
	PDM_ODM_T		pDM_Odm = (PDM_ODM_T)pDM_VOID;
	if(pDM_Odm->SupportICType == ODM_RTL8723B)
	{
		if(antSetting == 0)		// ant A
			ODM_SetBBReg(pDM_Odm, 0x948, bMaskDWord, 0x00000000);
		else if(antSetting == 1)
			ODM_SetBBReg(pDM_Odm, 0x948, bMaskDWord, 0x00000280);
	}
}

//======================================================


VOID
ODM_SwAntDivRestAfterLink(
	IN		PVOID		pDM_VOID
	)
{
	PDM_ODM_T		pDM_Odm = (PDM_ODM_T)pDM_VOID;
	pSWAT_T		pDM_SWAT_Table = &pDM_Odm->DM_SWAT_Table;
	pFAT_T		pDM_FatTable = &pDM_Odm->DM_FatTable;
	u4Byte             i;

	if(pDM_Odm->SupportICType == ODM_RTL8723A)
	{
	    pDM_SWAT_Table->RSSI_cnt_A = 0;
	    pDM_SWAT_Table->RSSI_cnt_B = 0;
	    pDM_Odm->RSSI_test = FALSE;
	    pDM_SWAT_Table->try_flag = 0xff;
	    pDM_SWAT_Table->RSSI_Trying = 0;
	    pDM_SWAT_Table->SelectAntennaMap=0xAA;

	}
	else if(pDM_Odm->SupportICType & (ODM_RTL8723B|ODM_RTL8821))
	{
		pDM_Odm->RSSI_test = FALSE;
		pDM_SWAT_Table->try_flag = 0xff;
		pDM_SWAT_Table->RSSI_Trying = 0;
		pDM_SWAT_Table->Double_chk_flag= 0;

		pDM_FatTable->RxIdleAnt=MAIN_ANT;

		for (i=0; i<ODM_ASSOCIATE_ENTRY_NUM; i++)
		{
			pDM_FatTable->MainAnt_Sum[i] = 0;
			pDM_FatTable->AuxAnt_Sum[i] = 0;
			pDM_FatTable->MainAnt_Cnt[i] = 0;
			pDM_FatTable->AuxAnt_Cnt[i] = 0;
		}

	}
}



VOID
ODM_AntDivReset(
	IN		PVOID		pDM_VOID
	)
{
	PDM_ODM_T		pDM_Odm = (PDM_ODM_T)pDM_VOID;
	//2 [--8723B---]
#if (RTL8723B_SUPPORT == 1)
	if(pDM_Odm->SupportICType == ODM_RTL8723B)
	{
	}
#endif
}

VOID
odm_AntennaDiversityInit(
	IN		PVOID		pDM_VOID
	)
{
	PDM_ODM_T		pDM_Odm = (PDM_ODM_T)pDM_VOID;

	if(pDM_Odm->SupportICType & (ODM_OLD_IC_ANTDIV_SUPPORT))
	{
		#if (RTL8192C_SUPPORT==1)
		#if (!(DM_ODM_SUPPORT_TYPE & (ODM_AP)))
		ODM_OldIC_AntDiv_Init(pDM_Odm);
		#endif
		#endif
	}
	else
	{
	}
}

VOID
odm_AntennaDiversity(
	IN		PVOID		pDM_VOID
	)
{
	PDM_ODM_T		pDM_Odm = (PDM_ODM_T)pDM_VOID;

	if(pDM_Odm->SupportICType & (ODM_OLD_IC_ANTDIV_SUPPORT))
	{
		#if (RTL8192C_SUPPORT==1)
		#if (!(DM_ODM_SUPPORT_TYPE & (ODM_AP)))
		ODM_OldIC_AntDiv(pDM_Odm);
		#endif
		#endif
	}
	else
	{
	}
}


