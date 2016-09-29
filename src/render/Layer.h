//
// Created by frederico on 9/26/16.
//

#ifndef STAR_EXPLORER_LAYER_H
#define STAR_EXPLORER_LAYER_H


#include "Image.h"

namespace Render {
    class Layer {
    public:
        Layer(int w, int h, int rateX, int rateY);
        ~Layer();
        void scrollRight();
        void plot(Image* origin, char zbuffer[]);
        Image* viewport;
    private:
        Image* currentImage;
        int originalWidth;
        int originalHeight;
        int rateX;
        int rateY;
        int posX;
        int posY;
    };
}




#endif //STAR_EXPLORER_LAYER_H
