/******************************************************************************
 *
 * Copyright(c) 2007 - 2017  Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * The full GNU General Public License is included in this distribution in the
 * file called LICENSE.
 *
 * Contact Information:
 * wlanfae <wlanfae@realtek.com>
 * Realtek Corporation, No. 2, Innovation Road II, Hsinchu Science Park,
 * Hsinchu 300, Taiwan.
 *
 * Larry Finger <Larry.Finger@lwfinger.net>
 *
 *****************************************************************************/

#ifndef __HALRF_DPK_8822C_H__
#define __HALRF_DPK_8822C_H__

#if (RTL8822C_SUPPORT == 1)
/*--------------------------Define Parameters-------------------------------*/
#define DPK_RF_PATH_NUM_8822C 2
#define DPK_GROUP_NUM_8822C 1
#define DPK_MAC_REG_NUM_8822C 2
#define DPK_BB_REG_NUM_8822C 18
#define DPK_RF_REG_NUM_8822C 7
#define DPK_PAS_CHK_DBG_8822C 0
#define DPK_COEF_DBG_8822C 0
#define DPK_PAS_DBG_8822C 0
#define DPK_SRAM_IQ_DBG_8822C 0
#define DPK_SRAM_read_DBG_8822C 0
#define DPK_SRAM_write_DBG_8822C 0
#define DPK_PATH_A_8822C 1
#define DPK_PATH_B_8822C 1
#define DPK_THRESHOLD_8822C 6
#define DPK_INFO_RSVD_LEN_8822C 179
#define DPK_C2H_REPORT_LEN_8822C 19

/*---------------------------End Define Parameters----------------------------*/

void btc_set_gnt_wl_bt_8822c(
	void *dm_void,
	boolean is_before_k);

void dpk_coef_read_8822c(
	void *dm_void);

void dpk_enable_disable_8822c(
	void *dm_void);

u8 dpk_reload_8822c(
	void *dm_void);

void do_dpk_8822c(
	void *dm_void);

void dpk_track_8822c(
	void *dm_void);

void dpk_info_by_8822c(
	void *dm_void,
	u32 *_used,
	char *output,
	u32 *_out_len);

void dpk_info_rsvd_page_8822c(
	void *dm_void,
	u8 *buf,
	u32 *buf_size);

void dpk_c2h_report_transfer_8822c(
	void	*dm_void,
	boolean	is_ok,
	u8	*buf,
	u8	buf_size);

#endif /* RTL8822C_SUPPORT */

#endif /*#ifndef __HALRF_DPK_8822C_H__*/
