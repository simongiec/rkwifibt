/******************************************************************************
 *
 * Copyright(c) 2015 - 2017 Realtek Corporation.
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
#ifndef _RTL8822C_H_
#define _RTL8822C_H_

#include <drv_types.h>		/* PADAPTER */
#include <rtw_rf.h>		/* CHANNEL_WIDTH */
#include <rtw_xmit.h>		/* struct pkt_attrib, struct xmit_frame */
#include <rtw_recv.h>		/* struct recv_frame */
#include <hal_intf.h>		/* HAL_DEF_VARIABLE */
#include "hal8822c_fw.h"	/* FW array */

#define DRIVER_EARLY_INT_TIME_8822C	0x05
#define BCN_DMA_ATIME_INT_TIME_8822C	0x02

#define C2H_GET_CMD_ID_1BYTE(c2h_pkt) LE_BITS_TO_1BYTE(c2h_pkt + 0X00, 0, 8)

#define C2H_GET_SEQ_1BYTE(c2h_pkt) LE_BITS_TO_1BYTE(c2h_pkt + 0X01, 0, 8)

/* rtl8822c_ops.c */
struct hw_port_reg {
	u32 net_type;	/*reg_offset*/
	u8 net_type_shift;
	u32 macaddr;	/*reg_offset*/
	u32 bssid;	/*reg_offset*/
	u32 bcn_ctl;			/*reg_offset*/
	u32 tsf_rst;			/*reg_offset*/
	u8 tsf_rst_bit;
	u32 bcn_space;		/*reg_offset*/
	u8 bcn_space_shift;
	u16 bcn_space_mask;
	u32	ps_aid;			/*reg_offset*/
	u32	ta;			/*reg_offset*/
};

/* rtl8822c_halinit.c */
void rtl8822c_init_hal_spec(PADAPTER);
u32 rtl8822c_power_on(PADAPTER);
void rtl8822c_power_off(PADAPTER);
u8 rtl8822c_hal_init(PADAPTER);
u8 rtl8822c_mac_verify(PADAPTER);
void rtl8822c_init_misc(PADAPTER padapter);
u32 rtl8822c_init(PADAPTER);
u32 rtl8822c_deinit(PADAPTER);
void rtl8822c_init_default_value(PADAPTER);

/* rtl8822c_mac.c */
u8 rtl8822c_rcr_config(PADAPTER, u32 rcr);
u8 rtl8822c_rx_ba_ssn_appended(PADAPTER);
u8 rtl8822c_rx_fcs_append_switch(PADAPTER, u8 enable);
u8 rtl8822c_rx_fcs_appended(PADAPTER);
u8 rtl8822c_rx_tsf_addr_filter_config(PADAPTER, u8 config);
s32 rtl8822c_fw_dl(PADAPTER, u8 wowlan);
u8 rtl8822c_get_rx_drv_info_size(struct _ADAPTER *a);
u32 rtl8822c_get_tx_desc_size(struct _ADAPTER *a);
u32 rtl8822c_get_rx_desc_size(struct _ADAPTER *a);

/* rtl8822c_ops.c */
u8 rtl8822c_read_efuse(PADAPTER);
void rtl8822c_run_thread(PADAPTER);
void rtl8822c_cancel_thread(PADAPTER);
u8 rtl8822c_sethwreg(PADAPTER, u8 variable, u8 *pval);
void rtl8822c_gethwreg(PADAPTER, u8 variable, u8 *pval);
u8 rtl8822c_sethaldefvar(PADAPTER, HAL_DEF_VARIABLE, void *pval);
u8 rtl8822c_gethaldefvar(PADAPTER, HAL_DEF_VARIABLE, void *pval);
void rtl8822c_set_hal_ops(PADAPTER);

/* tx */
void rtl8822c_init_xmit_priv(_adapter *adapter);
void rtl8822c_fill_txdesc_sectype(struct pkt_attrib *, u8 *ptxdesc);
void rtl8822c_fill_txdesc_vcs(PADAPTER, struct pkt_attrib *, u8 *ptxdesc);
void rtl8822c_fill_txdesc_phy(PADAPTER, struct pkt_attrib *, u8 *ptxdesc);
void rtl8822c_fill_txdesc_force_bmc_camid(struct pkt_attrib *, u8 *ptxdesc);
void rtl8822c_fill_txdesc_bmc_tx_rate(struct pkt_attrib *pattrib, u8 *ptxdesc);
u8 rtl8822c_bw_mapping(PADAPTER, struct pkt_attrib *);
u8 rtl8822c_sc_mapping(PADAPTER, struct pkt_attrib *);
void rtl8822c_fill_txdesc_bf(struct xmit_frame *, u8 *desc);
void rtl8822c_fill_txdesc_mgnt_bf(struct xmit_frame *, u8 *desc);
void rtl8822c_cal_txdesc_chksum(PADAPTER, u8 *ptxdesc);
void rtl8822c_update_txdesc(struct xmit_frame *, u8 *pbuf);
void rtl8822c_dbg_dump_tx_desc(PADAPTER, int frame_tag, u8 *ptxdesc);

/* rx */
void rtl8822c_rxdesc2attribute(struct rx_pkt_attrib *a, u8 *desc);
void rtl8822c_query_rx_desc(union recv_frame *, u8 *pdesc);

/* rtl8822c_cmd.c */
s32 rtl8822c_fillh2ccmd(PADAPTER, u8 id, u32 buf_len, u8 *pbuf);
void _rtl8822c_set_FwPwrMode_cmd(PADAPTER adapter, u8 psmode, u8 rfon_ctrl);
void rtl8822c_set_FwPwrMode_cmd(PADAPTER adapter, u8 psmode);
void rtl8822c_set_FwPwrMode_rfon_ctrl_cmd(PADAPTER adapter, u8 rfon_ctrl);

void rtl8822c_set_FwPwrModeInIPS_cmd(PADAPTER adapter, u8 cmd_param);
void rtl8822c_req_txrpt_cmd(PADAPTER, u8 macid);
void rtl8822c_c2h_handler(PADAPTER, u8 *pbuf, u16 length);
#ifdef CONFIG_WOWLAN
void rtl8822c_set_fw_pwrmode_inips_cmd_wowlan(PADAPTER padapter, u8 ps_mode);
#endif
void rtl8822c_set_usb_suspend_mode(PADAPTER padapter);

void rtl8822c_c2h_handler_no_io(PADAPTER, u8 *pbuf, u16 length);

#ifdef CONFIG_BT_COEXIST
void rtl8822c_download_BTCoex_AP_mode_rsvd_page(PADAPTER);
#endif /* CONFIG_BT_COEXIST */

/* rtl8822c_phy.c */
u8 rtl8822c_phy_init_mac_register(PADAPTER);
u8 rtl8822c_phy_init(PADAPTER);
void rtl8822c_phy_init_dm_priv(PADAPTER);
void rtl8822c_phy_deinit_dm_priv(PADAPTER);
void rtl8822c_phy_init_haldm(PADAPTER);
void rtl8822c_phy_haldm_watchdog(PADAPTER);
u32 rtl8822c_read_bb_reg(PADAPTER, u32 addr, u32 mask);
void rtl8822c_write_bb_reg(PADAPTER, u32 addr, u32 mask, u32 val);
u32 rtl8822c_read_rf_reg(PADAPTER adapter, enum rf_path path, u32 addr, u32 mask);
void rtl8822c_write_rf_reg(PADAPTER adapter, enum rf_path path, u32 addr, u32 mask, u32 val);
void rtl8822c_set_channel_bw(PADAPTER adapter, u8 center_ch, enum channel_width, u8 offset40, u8 offset80);
void rtl8822c_set_tx_power_level(PADAPTER, u8 channel);
void rtl8822c_set_txpwr_done(_adapter *adapter);
void rtl8822c_set_tx_power_index(PADAPTER adapter, u32 powerindex, enum rf_path rfpath, u8 rate);

u8 rtl8822c_get_dis_dpd_by_rate_diff(PADAPTER adapter, u8 rate);

void rtl8822c_notch_filter_switch(PADAPTER, bool enable);
#ifdef CONFIG_BEAMFORMING
void rtl8822c_phy_bf_init(PADAPTER);
void rtl8822c_phy_bf_enter(PADAPTER, struct sta_info*);
void rtl8822c_phy_bf_leave(PADAPTER, u8 *addr);
void rtl8822c_phy_bf_set_gid_table(PADAPTER, struct beamformer_entry*);
void rtl8822c_phy_bf_sounding_status(PADAPTER, u8 status);
#endif /* CONFIG_BEAMFORMING */

#endif /* _RTL8822C_H_ */
