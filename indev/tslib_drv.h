/**
 * @file tslib_drv.h
 *
 */

#ifndef TSLIB_DRV_H
#define TSLIB_DRV_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#ifndef LV_DRV_NO_CONF
#ifdef LV_CONF_INCLUDE_SIMPLE
#include "lv_drv_conf.h"
#else
#include "../../lv_drv_conf.h"
#endif
#endif

#if USE_TSLIB

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#include <tslib.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void tslib_init(void);
bool tslib_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

/**********************
 *      MACROS
 **********************/

#endif /* USE_TSLIB */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* TSLIB_DRV_H */
