/******************************************************************************
*
* Copyright(c) 2007 - 2016 Realtek Corporation. All rights reserved.
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

#ifdef CONFIG_RTL8814A

#include "drv_types.h"

#if 0
  from hal/phydm/phydm_types.h
 /*Define Different SW team support*/
#define	ODM_AP		0x01	/*BIT(0)*/
#define	ODM_CE		0x04	/*BIT(2)*/
#define	ODM_WIN		0x08	/*BIT(3)*/
#endif

#ifdef LOAD_FW_HEADER_FROM_DRIVER

#if (DM_ODM_SUPPORT_TYPE & (ODM_WIN)) || (DM_ODM_SUPPORT_TYPE & (ODM_CE))

#endif

#endif /* end of LOAD_FW_HEADER_FROM_DRIVER */

#endif
