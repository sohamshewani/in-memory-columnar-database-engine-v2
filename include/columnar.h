#ifndef COLUMNAR_H
#define COLUMNAR_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define data types
enum DataType { INT, FLOAT, STRING };

// Define column structure
typedef struct {
    enum DataType type;
    int32_t* intData;
    float* floatData;
    char** stringData;
} Column;

// Define table structure
typedef struct {
    int32_t numColumns;
    Column* columns;
} Table;

// Core functions
Table* createTable(int32_t numColumns);
void destroyTable(Table* table);
void addColumn(Table* table, enum DataType type);
int32_t* getColDataInt(Table* table, int32_t colIndex);
float* getColDataFloat(Table* table, int32_t colIndex);
char** getColDataString(Table* table, int32_t colIndex);

#endif
