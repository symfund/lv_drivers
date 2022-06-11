/**
 * @file tslib.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "tslib_drv.h"

#if USE_TSLIB

#include <stddef.h>
#include LV_DRV_INDEV_INCLUDE

/*********************
 *      DEFINES
 *********************/


/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/


/**********************
 *  STATIC VARIABLES
 **********************/
static struct tsdev *ts_dev = NULL;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Initialize the tslib
 */
void tslib_init(void)
{
    ts_dev = ts_setup(NULL, 1);
    if (!ts_dev) {
        LV_LOG_ERROR("Failed to open ts_open()\n");
        return;
    }
}

/**
 * Get the current position and state of the touchpad
 * @param data store the read data here
 * @return false: because no ore data to be read
 */
bool tslib_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    struct ts_sample sample;
    int ret;
    
    ret = ts_read(ts_dev, &sample, 1);
    if (ret < 0) {
        LV_LOG_ERROR("ts_read error\n");
        ts_close(ts_dev);
        exit(1);
    }
    
    if (ret != 1) {
        return true;
    }
    
    if (sample.pressure > 0) {
        data->state = LV_INDEV_STATE_PR;
    } else {
        data->state = LV_INDEV_STATE_REL;
    }

    data->point.x = sample.x;
    data->point.y = sample.y;

    return false;
}

#endif
