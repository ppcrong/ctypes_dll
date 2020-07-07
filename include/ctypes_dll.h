#pragma once

#include <stdint.h>

#ifdef _WIN64
#define WINDOWS_DLL_DEFINE __declspec(dllexport)
#else
#define WINDOWS_DLL_DEFINE
#endif

typedef unsigned char byte;

struct bounding_box_s
{
    float x1;          // top-left corner: x
    float y1;          // top-left corner: y
    float x2;          // bottom-right corner: x
    float y2;          // bottom-right corner: y
    float score;       // probability score
    int32_t class_num; // class # (of many) with highest probability
};

struct test_result_s
{
    uint32_t class_count;           // total class count
    uint32_t box_count;             // boxes of all classes
    struct bounding_box_s boxes[1]; // box_count
};

/**
 * reference: https://chrisheydrick.com/2016/02/06/passing-a-ctypes-array-of-struct-from-python-to-dll/
 */
struct structtest
{
    char x;
    uint32_t y;
    long z;
};

/**
 * reference: https://stackoverflow.com/questions/8392203/dynamic-arrays-and-structures-in-structures-in-python
 */
struct _rows
{
    int cols_count;
    char **cols;
};

struct _unit
{
    int rows_count;
    struct _rows *rows;
};

WINDOWS_DLL_DEFINE int test_value(int *pValue);
WINDOWS_DLL_DEFINE void test_buf(void *buf);
WINDOWS_DLL_DEFINE size_t test_struct_array(struct bounding_box_s **ppBoxes, size_t boxes_len);
WINDOWS_DLL_DEFINE size_t test_struct_array2(struct test_result_s **ppResults, size_t results_len);
WINDOWS_DLL_DEFINE void fillonestruct(struct structtest *t);
WINDOWS_DLL_DEFINE void fillmultiplestruct(struct structtest *t, size_t n);
WINDOWS_DLL_DEFINE int my_func(struct _unit *param);
