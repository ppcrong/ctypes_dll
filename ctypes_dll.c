#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ctypes_dll.h"

#define USBD_ENDPOINT_DATA_OUT 0x01
#define USBD_ENDPOINT_DATA_IN 0x82
#define USBD_ENDPOINT_DBG_OUT 0x03
#define USBD_ENDPOINT_DBG_IN 0x84

int test_value(int *pValue)
{
    *pValue = 999;
    return *pValue;
}

void test_buf(void *buf)
{
    byte *buffer = (byte *)buf;
    *buffer = 11;
    *(buffer + 1) = 22;
}

size_t test_struct_array(struct bounding_box_s **ppBoxes, size_t boxes_len)
{
    struct bounding_box_s box1 = {
        .x1 = 10.1f,
        .y1 = 10.1f,
        .x2 = 20.1f,
        .y2 = 20.1f,
        .score = 20.0f,
        .class_num = 1};
    struct bounding_box_s box2 = {
        .x1 = 30.2f,
        .y1 = 30.2f,
        .x2 = 100.1f,
        .y2 = 100.1f,
        .score = 60.0f,
        .class_num = 2};
    (*ppBoxes)[0] = box1;
    (*ppBoxes)[1] = box2;
    return boxes_len;
}

size_t test_struct_array2(struct test_result_s **ppResults, size_t results_len)
{
    // struct bounding_box_s box1 = {
    //     .x1 = 10,
    //     .y1 = 10,
    //     .x2 = 10,
    //     .y2 = 10,
    //     .score = 10,
    //     .class_num = 10
    // };
    // struct bounding_box_s box2 = {
    //     .x1 = 20,
    //     .y1 = 20,
    //     .x2 = 20,
    //     .y2 = 20,
    //     .score = 20,
    //     .class_num = 20
    // };
    // struct bounding_box_s box3 = {
    //     .x1 = 30,
    //     .y1 = 30,
    //     .x2 = 30,
    //     .y2 = 30,
    //     .score = 30,
    //     .class_num = 30
    // };

    // struct bounding_box_s boxes1[3] = {box1, box2, box3};
    struct test_result_s res1 = {
        .class_count = 10,
        .box_count = 10,
    };
    // struct bounding_box_s boxes2[3] = {box1, box2, box3};
    struct test_result_s res2 = {
        .class_count = 20,
        .box_count = 20,
    };
    // struct bounding_box_s boxes3[3] = {box1, box2, box3};
    struct test_result_s res3 = {
        .class_count = 30,
        .box_count = 30,
    };
    (*ppResults)[0] = res1;
    (*ppResults)[1] = res2;
    (*ppResults)[2] = res3;
    return results_len;
}

/**
 * reference: https://chrisheydrick.com/2016/02/06/passing-a-ctypes-array-of-struct-from-python-to-dll/
 */
void fillonestruct(struct structtest *t)
{
    t->x = 'A';
    t->y = 1234;
    t->z = 5678;
}

void fillmultiplestruct(struct structtest *t, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        t->x = (char)((int)'A' + i);
        t->y = i;
        t->z = i;
        t++;
    }
}

/**
 * reference: https://stackoverflow.com/questions/8392203/dynamic-arrays-and-structures-in-structures-in-python
 */
int my_func(struct _unit *param)
{
    int i, j;
    for (i = 0; i < param->rows_count; i++)
        for (j = 0; j < param->rows[i].cols_count; j++)
            printf("%d,%d = %s\n", i, j, param->rows[i].cols[j]);
    return 0;
}
