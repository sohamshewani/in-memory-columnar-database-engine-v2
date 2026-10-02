#include "columnar.h"
#include "compression.h"
#include "scan.h"
#include "types.h"

// Core functions implementation
Table* createTable(int32_t numColumns) {
    Table* table = (Table*)malloc(sizeof(Table));
    table->numColumns = numColumns;
    table->columns = (Column*)malloc(numColumns * sizeof(Column));
    for (int32_t i = 0; i < numColumns; i++) {
        table->columns[i].type = INT;
        table->columns[i].intData = (int32_t*)malloc(100 * sizeof(int32_t));
    }
    return table;
}

void destroyTable(Table* table) {
    for (int32_t i = 0; i < table->numColumns; i++) {
        free(table->columns[i].intData);
    }
    free(table->columns);
    free(table);
}

void addColumn(Table* table, enum DataType type) {
    if (table->numColumns >= 100) {
        fprintf(stderr, "Error: Column limit exceeded.");
        return;
    }
    table->columns[table->numColumns].type = type;
    if (type == INT) {
        table->columns[table->numColumns].intData = (int32_t*)malloc(100 * sizeof(int32_t));
    }
    table->numColumns++;
}

int32_t* getColDataInt(Table* table, int32_t colIndex) {
    if (colIndex >= table->numColumns || table->columns[colIndex].type != INT) {
        fprintf(stderr, "Error: Invalid column index or type.");
        return NULL;
    }
    return table->columns[colIndex].intData;
}

float* getColDataFloat(Table* table, int32_t colIndex) {
    if (colIndex >= table->numColumns || table->columns[colIndex].type != FLOAT) {
        fprintf(stderr, "Error: Invalid column index or type.");
        return NULL;
    }
    return table->columns[colIndex].floatData;
}

char** getColDataString(Table* table, int32_t colIndex) {
    if (colIndex >= table->numColumns || table->columns[colIndex].type != STRING) {
        fprintf(stderr, "Error: Invalid column index or type.");
        return NULL;
    }
    return table->columns[colIndex].stringData;
}

void compressTable(Table* table) {
    for (int32_t i = 0; i < table->numColumns; i++) {
        switch (table->columns[i].type) {
            case INT:
                // Implement compression logic for int
                break;
            case FLOAT:
                // Implement compression logic for float
                break;
            case STRING:
                // Implement compression logic for string
                break;
        }
    }
}

void decompressTable(Table* table) {
    for (int32_t i = 0; i < table->numColumns; i++) {
        switch (table->columns[i].type) {
            case INT:
                // Implement decompression logic for int
                break;
            case FLOAT:
                // Implement decompression logic for float
                break;
            case STRING:
                // Implement decompression logic for string
                break;
        }
    }
}

void scanTable(Table* table) {
    // Implement vectorized scan logic
}
