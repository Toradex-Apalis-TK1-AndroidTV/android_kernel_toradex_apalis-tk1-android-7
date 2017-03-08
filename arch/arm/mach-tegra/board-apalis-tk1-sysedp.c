/*
 * Copyright (c) 2016 Toradex AG. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <linux/sysedp.h>
#include <linux/platform_device.h>
#include <linux/platform_data/tegra_edp.h>
#include <linux/power_supply.h>
#include <mach/edp.h>
#include <linux/interrupt.h>
#include <linux/tegra_soctherm.h>

#include "board-apalis-tk1.h"
#include "board.h"
#include "board-panel.h"
#include <linux/platform/tegra/common.h>

/* --- EDP consumers data --- */
/* TODO static unsigned int ov5693_states[] = { 0, 300 };*/
static unsigned int mt9m114_states[] = { 0, 150 };
static unsigned int sdhci_states[] = { 0, 966 };
static unsigned int speaker_states[] = { 0, 1080 };
static unsigned int wifi_states[] = { 0, 3070 };

/* 10 inch panel */
static unsigned int pwm_backlight_states[] = {
	0, 425, 851, 1276, 1702, 2127, 2553, 2978, 3404, 3829, 4255
};

/* TODO
static unsigned int as364x_states[] = {
	0, 350, 700, 1050, 1400, 1750, 2100, 2450, 2800, 3150, 3500
};
*/

static struct sysedp_consumer_data apalis_tk1_sysedp_consumer_data[] = {
	/* TODO SYSEDP_CONSUMER_DATA("ov5693", ov5693_states), */
	SYSEDP_CONSUMER_DATA("mt9m114", mt9m114_states),
	SYSEDP_CONSUMER_DATA("speaker", speaker_states),
	SYSEDP_CONSUMER_DATA("wifi", wifi_states),
	SYSEDP_CONSUMER_DATA("pwm-backlight", pwm_backlight_states),
	SYSEDP_CONSUMER_DATA("sdhci-tegra.2", sdhci_states),
	SYSEDP_CONSUMER_DATA("sdhci-tegra.3", sdhci_states),
	/* TODO SYSEDP_CONSUMER_DATA("as364x", as364x_states), */
};

static struct sysedp_platform_data apalis_tk1_sysedp_platform_data = {
	.consumer_data = apalis_tk1_sysedp_consumer_data,
	.consumer_data_size = ARRAY_SIZE(apalis_tk1_sysedp_consumer_data),
	.margin = 0,
};

static struct platform_device apalis_tk1_sysedp_device = {
	.name = "sysedp",
	.id = -1,
	.dev = {.platform_data = &apalis_tk1_sysedp_platform_data}
};

void __init apalis_tk1_new_sysedp_init(void)
{
	int r;

	r = platform_device_register(&apalis_tk1_sysedp_device);
	WARN_ON(r);
}

#if defined(CONFIG_ARCH_TEGRA_13x_SOC)
static struct tegra_sysedp_platform_data apalis_tk1_sysedp_dynamic_capping_platdata = {
	.core_gain = 100,
	.init_req_watts = 20000,
	.pthrot_ratio = 75,
	.cap_method = TEGRA_SYSEDP_CAP_METHOD_SIGNAL,
};
#else
static struct tegra_sysedp_platform_data apalis_tk1_sysedp_dynamic_capping_platdata = {
	.core_gain = 115,
	.init_req_watts = 20000,
	.pthrot_ratio = 75,
	.cap_method = TEGRA_SYSEDP_CAP_METHOD_SIGNAL,
};
#endif

static struct platform_device apalis_tk1_sysedp_dynamic_capping = {
	.name = "sysedp_dynamic_capping",
	.id = -1,
	.dev = {.platform_data = &apalis_tk1_sysedp_dynamic_capping_platdata}
};

void __init apalis_tk1_sysedp_dynamic_capping_init(void)
{
	int r;
	struct tegra_sysedp_corecap *corecap;
	unsigned int corecap_size;

	corecap = tegra_get_sysedp_corecap(&corecap_size);
	if (!corecap) {
		WARN_ON(1);
		return;
	}
	apalis_tk1_sysedp_dynamic_capping_platdata.corecap = corecap;
	apalis_tk1_sysedp_dynamic_capping_platdata.corecap_size = corecap_size;

	r = platform_device_register(&apalis_tk1_sysedp_dynamic_capping);
	WARN_ON(r);
}
