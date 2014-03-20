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
 ******************************************************************************/


#ifndef	__HALHWOUTSRC_H__
#define __HALHWOUTSRC_H__

#include <Hal8723APhyCfg.h>

/*  */
/*  Definition */
/*  */
/*  */
/*  */
/*  CCK Rates, TxHT = 0 */
#define DESC92C_RATE1M					0x00
#define DESC92C_RATE2M					0x01
#define DESC92C_RATE5_5M				0x02
#define DESC92C_RATE11M				0x03

/*  OFDM Rates, TxHT = 0 */
#define DESC92C_RATE6M					0x04
#define DESC92C_RATE9M					0x05
#define DESC92C_RATE12M				0x06
#define DESC92C_RATE18M				0x07
#define DESC92C_RATE24M				0x08
#define DESC92C_RATE36M				0x09
#define DESC92C_RATE48M				0x0a
#define DESC92C_RATE54M				0x0b

/*  MCS Rates, TxHT = 1 */
#define DESC92C_RATEMCS0				0x0c
#define DESC92C_RATEMCS1				0x0d
#define DESC92C_RATEMCS2				0x0e
#define DESC92C_RATEMCS3				0x0f
#define DESC92C_RATEMCS4				0x10
#define DESC92C_RATEMCS5				0x11
#define DESC92C_RATEMCS6				0x12
#define DESC92C_RATEMCS7				0x13
#define DESC92C_RATEMCS8				0x14
#define DESC92C_RATEMCS9				0x15
#define DESC92C_RATEMCS10				0x16
#define DESC92C_RATEMCS11				0x17
#define DESC92C_RATEMCS12				0x18
#define DESC92C_RATEMCS13				0x19
#define DESC92C_RATEMCS14				0x1a
#define DESC92C_RATEMCS15				0x1b
#define DESC92C_RATEMCS15_SG			0x1c
#define DESC92C_RATEMCS32				0x20


/*  */
/*  structure and define */
/*  */

typedef struct _Phy_Rx_AGC_Info
{
	#ifdef __LITTLE_ENDIAN
		u8	gain:7,trsw:1;
	#else
		u8	trsw:1,gain:7;
	#endif
} PHY_RX_AGC_INFO_T,*pPHY_RX_AGC_INFO_T;

typedef struct _Phy_Status_Rpt_8192cd
{
	PHY_RX_AGC_INFO_T path_agc[2];
	u8	ch_corr[2];
	u8	cck_sig_qual_ofdm_pwdb_all;
	u8	cck_agc_rpt_ofdm_cfosho_a;
	u8	cck_rpt_b_ofdm_cfosho_b;
	u8	rsvd_1;/* ch_corr_msb; */
	u8	noise_power_db_msb;
	u8	path_cfotail[2];
	u8	pcts_mask[2];
	s8	stream_rxevm[2];
	u8	path_rxsnr[2];
	u8	noise_power_db_lsb;
	u8	rsvd_2[3];
	u8	stream_csi[2];
	u8	stream_target_csi[2];
	s8	sig_evm;
	u8	rsvd_3;

#ifdef __LITTLE_ENDIAN
	u8	antsel_rx_keep_2:1;	/* ex_intf_flg:1; */
	u8	sgi_en:1;
	u8	rxsc:2;
	u8	idle_long:1;
	u8	r_ant_train_en:1;
	u8	ant_sel_b:1;
	u8	ant_sel:1;
#else	/*  _BIG_ENDIAN_ */
	u8	ant_sel:1;
	u8	ant_sel_b:1;
	u8	r_ant_train_en:1;
	u8	idle_long:1;
	u8	rxsc:2;
	u8	sgi_en:1;
	u8	antsel_rx_keep_2:1;	/* ex_intf_flg:1; */
#endif
} PHY_STATUS_RPT_8192CD_T,*PPHY_STATUS_RPT_8192CD_T;


typedef struct _Phy_Status_Rpt_8195
{
	PHY_RX_AGC_INFO_T path_agc[2];
	u8	ch_num[2];
	u8	cck_sig_qual_ofdm_pwdb_all;
	u8	cck_agc_rpt_ofdm_cfosho_a;
	u8	cck_bb_pwr_ofdm_cfosho_b;
	u8    cck_rx_path;	/* CCK_RX_PATH [3:0] (with regA07[3:0] definition) */
	u8	rsvd_1;
	u8	path_cfotail[2];
	u8	pcts_mask[2];
	s8	stream_rxevm[2];
	u8	path_rxsnr[2];
	u8	rsvd_2[2];
	u8	stream_snr[2];
	u8	stream_csi[2];
	u8	rsvd_3[2];
	s8	sig_evm;
	u8	rsvd_4;
#ifdef __LITTLE_ENDIAN
	u8	antidx_anta:3;
	u8	antidx_antb:3;
	u8	rsvd_5:2;
#else	/*  _BIG_ENDIAN_ */
	u8	rsvd_5:2;
	u8	antidx_antb:3;
	u8	antidx_anta:3;
#endif
} PHY_STATUS_RPT_8195_T,*pPHY_STATUS_RPT_8195_T;


void
odm_Init_RSSIForDM(
	PDM_ODM_T	pDM_Odm
	);

void
ODM_PhyStatusQuery(
	DM_ODM_T *pDM_Odm,
	struct odm_phy_info *pPhyInfo,
	u8 *						pPhyStatus,
	ODM_PACKET_INFO_T *pPktinfo
	);

void ODM_MacStatusQuery(DM_ODM_T *pDM_Odm,
	u8 *pMacStatus,
	u8 MacID,
	bool bPacketMatchBSSID,
	bool bPacketToSelf,
	bool bPacketBeacon
);

HAL_STATUS
ODM_ConfigRFWithHeaderFile(
	PDM_ODM_T	      pDM_Odm,
	enum RF_RADIO_PATH	Content,
	enum RF_RADIO_PATH	eRFPath
);

HAL_STATUS
ODM_ConfigBBWithHeaderFile(
	PDM_ODM_T				pDM_Odm,
	ODM_BB_Config_Type		ConfigType
);

HAL_STATUS
ODM_ConfigMACWithHeaderFile(
	PDM_ODM_T	pDM_Odm
    );

#endif
