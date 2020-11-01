#include "utilities.h"

int ** create2D (int size) {
    int ** output = new int * [size];
    for (int i = 0; i < size; ++i) {
        output[i] = new int [size];
    }    
    return output;
}

void delete2D (int ** arr, int size) {
    for (int i = 0; i < size; ++i) {
        delete arr[i];
    }
    delete arr;
}