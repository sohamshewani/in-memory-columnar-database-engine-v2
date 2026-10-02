#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Data types
enum DataType { INT, FLOAT, STRING };

// Column structure
typedef struct {
    enum DataType type;
    int32_t* intData;
    float* floatData;
    char** stringData;
} Column;

// Table structure
typedef struct {
    int32_t numColumns;
    Column* columns;
} Table;

#endif
