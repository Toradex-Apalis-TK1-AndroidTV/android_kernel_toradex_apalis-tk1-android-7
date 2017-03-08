/**
<<<<<<< HEAD
 * Copyright (c) 2016, NVIDIA CORPORATION.  All rights reserved.
=======
 * Copyright (c) 2014-2015, NVIDIA Corporation.  All rights reserved.
>>>>>>> 61cf29c... Edit Apalis TK1 board files
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __IMX185_H__
#define __IMX185_H__

<<<<<<< HEAD
#include <linux/ioctl.h>
#include <media/nvc.h>
#include <media/nvc_image.h>

#define IMX185_EEPROM_STR_SIZE	80
#define IMX185_OTP_STR_SIZE	60
#define IMX185_FUSE_ID_ADDR	0x3382
#define IMX185_FUSE_ID_SIZE	6
#define IMX185_FUSE_ID_STR_SIZE	(IMX185_FUSE_ID_SIZE * 2)

#define IMX185_FRAME_LENGTH_ADDR_MSB	0x301A
#define IMX185_FRAME_LENGTH_ADDR_MID	0x3019
#define IMX185_FRAME_LENGTH_ADDR_LSB	0x3018
#define IMX185_COARSE_TIME_SHS1_ADDR_MSB	0x3022
#define IMX185_COARSE_TIME_SHS1_ADDR_MID	0x3021
#define IMX185_COARSE_TIME_SHS1_ADDR_LSB	0x3020
#define IMX185_COARSE_TIME_SHS2_ADDR_MSB	0x3025
#define IMX185_COARSE_TIME_SHS2_ADDR_MID	0x3024
#define IMX185_COARSE_TIME_SHS2_ADDR_LSB	0x3023
#define IMX185_GAIN_ADDR	0x3014
#define IMX185_GROUP_HOLD_ADDR	0x3001

struct imx185_mode {
	__u32 xres;
	__u32 yres;
	__u32 frame_length;
	__u32 coarse_time;
	__u32 coarse_time_short;
	__u16 gain;
	__u8 hdr_en;
};

struct imx185_hdr {
	__u32 coarse_time_long;
	__u32 coarse_time_short;
=======
#include <linux/ioctl.h>  /* For IOCTL macros */
#include <media/nvc.h>
#include <media/nvc_image.h>

#define IMX185_IOCTL_SET_MODE		_IOW('o', 1, struct imx185_mode)
#define IMX185_IOCTL_GET_STATUS		_IOR('o', 2, __u8)
#define IMX185_IOCTL_SET_FRAME_LENGTH	_IOW('o', 3, __u32)
#define IMX185_IOCTL_SET_COARSE_TIME	_IOW('o', 4, __u32)
#define IMX185_IOCTL_SET_GAIN		_IOW('o', 5, __u16)
#define IMX185_IOCTL_GET_SENSORDATA	_IOR('o', 6, struct imx185_sensordata)
#define IMX185_IOCTL_SET_GROUP_HOLD	_IOW('o', 7, struct imx185_ae)
#define IMX185_IOCTL_SET_POWER		_IOW('o', 20, __u32)
#define IMX185_IOCTL_GET_FLASH_CAP	_IOR('o', 30, __u32)
#define IMX185_IOCTL_SET_FLASH_MODE	_IOW('o', 31, \
						struct imx185_flash_control)

struct imx185_mode {
	int xres;
	int yres;
	__u32 frame_length;
	__u32 coarse_time;
	__u16 gain;
>>>>>>> 61cf29c... Edit Apalis TK1 board files
};

struct imx185_ae {
	__u32 frame_length;
	__u8  frame_length_enable;
	__u32 coarse_time;
<<<<<<< HEAD
	__u32 coarse_time_short;
=======
>>>>>>> 61cf29c... Edit Apalis TK1 board files
	__u8  coarse_time_enable;
	__s32 gain;
	__u8  gain_enable;
};

struct imx185_sensordata {
	__u32 fuse_id_size;
<<<<<<< HEAD
	__u8  fuse_id[IMX185_FUSE_ID_SIZE];
};

=======
	__u8  fuse_id[16];
};

struct imx185_flash_control {
	u8 enable;
	u8 edge_trig_en;
	u8 start_edge;
	u8 repeat;
	u16 delay_frm;
};


>>>>>>> 61cf29c... Edit Apalis TK1 board files
#ifdef __KERNEL__
struct imx185_power_rail {
	struct regulator *dvdd;
	struct regulator *avdd;
	struct regulator *iovdd;
	struct regulator *ext_reg1;
	struct regulator *ext_reg2;
<<<<<<< HEAD
	struct clk *mclk;
	unsigned int pwdn_gpio;
	unsigned int cam1_gpio;
	unsigned int reset_gpio;
	unsigned int af_gpio;
};

struct imx185_platform_data {
=======
};

struct imx185_platform_data {
	struct imx185_flash_control flash_cap;
>>>>>>> 61cf29c... Edit Apalis TK1 board files
	const char *mclk_name; /* NULL for default default_mclk */
	unsigned int cam1_gpio;
	unsigned int reset_gpio;
	unsigned int af_gpio;
	bool ext_reg;
	int (*power_on)(struct imx185_power_rail *pw);
	int (*power_off)(struct imx185_power_rail *pw);
};
#endif /* __KERNEL__ */
<<<<<<< HEAD
=======

>>>>>>> 61cf29c... Edit Apalis TK1 board files
#endif  /* __IMX185_H__ */
