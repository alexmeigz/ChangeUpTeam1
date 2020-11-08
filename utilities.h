#pragma once

#include <vector>

template <class T>
using Vector2D = std::vector<std::vector<T>>;

template <class T>
void init2D(Vector2D<T> &vec, int size) {
    vec.resize(size);
    
    for (int i = 0; i < size; ++i) {
        vec[i].resize(size);
    }
}

template <class T>
Vector2D<T> init2D(int size) {
    Vector2D<T> output;
    init2D(output, size);
    return output;
}