#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Compression functions
void compressTable(Table* table);
void decompressTable(Table* table);

#endif
