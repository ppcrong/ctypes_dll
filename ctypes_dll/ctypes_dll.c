#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ctypes_dll.h"

#define USBD_ENDPOINT_DATA_OUT 0x01
#define USBD_ENDPOINT_DATA_IN 0x82
#define USBD_ENDPOINT_DBG_OUT 0x03
#define USBD_ENDPOINT_DBG_IN 0x84

int test_value(int* pValue)
{
    *pValue = 999;
    return *pValue;
}

void test_buf(void* buf)
{
    byte* buffer = (byte*)buf;
    *buffer = 11;
    *(buffer + 1) = 22;
}

size_t test_struct_array(struct bounding_box_s** ppBoxes, size_t boxes_len)
{
    struct bounding_box_s box1 = {
        .x1 = 10.1f,
        .y1 = 10.1f,
        .x2 = 20.1f,
        .y2 = 20.1f,
        .score = 20.0f,
        .class_num = 1
    };
    struct bounding_box_s box2 = {
        .x1 = 30.2f,
        .y1 = 30.2f,
        .x2 = 100.1f,
        .y2 = 100.1f,
        .score = 60.0f,
        .class_num = 2
    };
    (*ppBoxes)[0] = box1;
    (*ppBoxes)[1] = box2;
    return boxes_len;
}