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

#if (BT_SUPPORT == 1 && COEX_SUPPORT == 1)

/* *******************************************
 * The following is interface which will notify coex module.
 * ********************************************/
void rtw_btc_ex_power_on_setting(struct btc_coexist *btc);
void rtw_btc_ex_pre_load_firmware(struct btc_coexist *btc);
void rtw_btc_ex_init_hw_config(struct btc_coexist *btc, boolean wifi_only);
void rtw_btc_ex_init_coex_dm(struct btc_coexist *btc);
void rtw_btc_ex_ips_notify(struct btc_coexist *btc, u8 type);
void rtw_btc_ex_lps_notify(struct btc_coexist *btc, u8 type);
void rtw_btc_ex_scan_notify(struct btc_coexist *btc, u8 type);
void rtw_btc_ex_scan_notify_without_bt(struct btc_coexist *btc, u8 type);
void rtw_btc_ex_switchband_notify(struct btc_coexist *btc, u8 type);
void rtw_btc_ex_switchband_notify_without_bt(struct btc_coexist *btc, u8 type);
void rtw_btc_ex_connect_notify(struct btc_coexist *btc, u8 type);
void rtw_btc_ex_media_status_notify(struct btc_coexist *btc, u8 type);
void rtw_btc_ex_specific_packet_notify(struct btc_coexist *btc, u8 type);
void rtw_btc_ex_bt_info_notify(struct btc_coexist *btc, u8 *tmp_buf, u8 length);
void rtw_btc_ex_bt_le_audio_info_notify(struct btc_coexist *btc, u8 *tmp_buf, u8 length);
void rtw_btc_ex_wl_fwdbginfo_notify(struct btc_coexist *btc, u8 *tmp_buf,
				    u8 length);
void rtw_btc_ex_rx_rate_change_notify(struct btc_coexist *btc,
				      BOOLEAN is_data_frame,
				      u8 btc_rate_id);
void rtw_btc_ex_tx_rate_change_notify(struct btc_coexist *btc, u8 tx_rate,
				      u8 tx_retry_ratio, u8 macid);
void rtw_btc_ex_rf_status_notify(struct btc_coexist *btc, u8 type);
void rtw_btc_ex_halt_notify(struct btc_coexist *btc);
void rtw_btc_ex_pnp_notify(struct btc_coexist *btc, u8 pnp_state);
void rtw_btc_ex_coex_dm_reset(struct btc_coexist *btc);
void rtw_btc_ex_periodical(struct btc_coexist *btc);
void rtw_btc_ex_timerup_notify(struct btc_coexist *btc, u32 type);
void rtw_btc_ex_wl_status_change_notify(struct btc_coexist *btc, u32 type);
void rtw_btc_ex_display_simple_coex_info(struct btc_coexist *btc);
void rtw_btc_ex_display_coex_info(struct btc_coexist *btc);
void rtw_btc_ex_dbg_control(struct btc_coexist *btc, u8 op_code, u8 op_len,
			    u8 *pdata);
void rtw_btc_ex_wl_rfk_notify(struct btc_coexist *btc, u8 path,
							u8 type, u8 state);

#else
#define rtw_btc_ex_power_on_setting(btc)
#define rtw_btc_ex_pre_load_firmware(btc)
#define rtw_btc_ex_init_hw_config(btc, wifi_only)
#define rtw_btc_ex_init_coex_dm(btc)
#define rtw_btc_ex_ips_notify(btc, type)
#define rtw_btc_ex_lps_notify(btc, type)
#define rtw_btc_ex_scan_notify(btc, type)
#define rtw_btc_ex_scan_notify_without_bt(btc, type)
#define rtw_btc_ex_switchband_notify(btc, type)
#define rtw_btc_ex_switchband_notify_without_bt(btc, type)
#define rtw_btc_ex_connect_notify(btc, type)
#define rtw_btc_ex_media_status_notify(btc, type)
#define rtw_btc_ex_specific_packet_notify(btc, type)
#define rtw_btc_ex_bt_info_notify(btc, tmp_buf, length)
#define rtw_btc_ex_bt_le_audio_info_notify(btc, tmp_buf, length)
#define rtw_btc_ex_wl_fwdbginfo_notify(btc, tmp_buf, length)
#define rtw_btc_ex_rx_rate_change_notify(btc, is_data_frame, btc_rate_id)
#define rtw_btc_ex_tx_rate_change_notify(btcoexist, tx_rate, tx_retry_ratio, \
				       macid)
#define rtw_btc_ex_rf_status_notify(btc, type)
#define rtw_btc_ex_halt_notify(btc)
#define rtw_btc_ex_pnp_notify(btc, pnp_state)
#define rtw_btc_ex_coex_dm_reset(btc)
#define rtw_btc_ex_periodical(btc)
#define rtw_btc_ex_timerup_notify(btc, type)
#define rtw_btc_ex_wl_status_change_notify(btc, type)
#define rtw_btc_ex_display_coex_info(btc)
#define rtw_btc_ex_dbg_control(btc, op_code, op_len, pdata)
#define rtw_btc_ex_wl_rfk_notify(btc, path, type, state)
#endif
