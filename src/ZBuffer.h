//
// Created by VitorVRS on 10/9/16.
//

#ifndef STAR_EXPLORER_ZBUFER_H
#define STAR_EXPLORER_ZBUFER_H

class ZBuffer {

public:
    int width;
    int height;
    ZBuffer(int width, int height) : width(width), height(height), keys(new int[width*height]) {};
    ~ZBuffer();
    int * keys;
    void reset();
};

#endif // STAR_EXPLORER_ZBUFER_H
