#include <stdio.h>
#include "include/columnar.h"
#include "include/types.h"

int main(int argc, char *argv[]) {
    // Example main function to demonstrate usage
    ColumnarEngine *engine = create_columnar_engine();
    // Further code to interact with the engine
    destroy_columnar_engine(engine);
    return 0;
}