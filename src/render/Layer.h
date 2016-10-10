//
// Created by frederico on 9/26/16.
//

#ifndef STAR_EXPLORER_LAYER_H
#define STAR_EXPLORER_LAYER_H


#include "Image.h"
#include "../GameObject.h"

namespace Render {
    class Layer {
    public:
        Layer(int w, int h, int rateX, int rateY);
        ~Layer();
        void scrollRight();
        void plot(Image* origin, char zbuffer[]);
        void addObject(GameObject* object);
        void removeObject(GameObject* object);
        void refresh();
        Image* viewport;
    private:
        std::vector<GameObject*> objects;
        GameObject* object;
        Image* currentImage;
        int originalWidth;
        int originalHeight;
        int rateX;
        int rateY;
        int posX;
        int posY;

        void refreshObject(GameObject *object);
    };
}

#endif //STAR_EXPLORER_LAYER_H
