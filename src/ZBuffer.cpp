#include "ZBuffer.h"

void ZBuffer::reset() {
    int size = width*height;
    for (int i = 0; i < size; i++) {
        this->keys[i] = -1;
    }
}
