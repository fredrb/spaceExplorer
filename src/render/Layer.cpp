//
// Created by frederico on 9/26/16.
//

#include <iostream>
#include "Layer.h"

void Render::Layer::scrollRight() {
    posX = (posX >= originalWidth) ? 0 : posX + rateX;
    currentImage->subImage(viewport, posX, 0);
}

void Render::Layer::plot(Render::Image *origin, char *zbuffer) {
    currentImage->plot(origin, 0, 0);
    currentImage->plot(origin, origin->getWidth(), 0);
    currentImage->subImage(viewport, 0, 0);
}

Render::Layer::Layer(int w, int h, int rateX, int rateY) {
    posX = 0;
    posY = 0;
    this->rateX = rateX;
    this->rateY = rateY;

    originalWidth = w;
    originalHeight = h;

    currentImage = new Image(w*2, h);
    viewport = new Image(w, h);
    objects = std::vector<GameObject*>();
}

Render::Layer::~Layer() {
    delete currentImage;
    delete viewport;
}

void Render::Layer::addObject(GameObject *object) {
    // objects.push_back(object);
    this->object = object;
    currentImage->subImage(viewport, posX, posY);
    viewport->plot(object->getFrame(), object->posX, object->posY);
}

void Render::Layer::refresh() {
    object->nextFrame();
    object->refresh();
    if (object->hasPositionChanged()) {
        currentImage->subImage(viewport, posX, posY);
        viewport->plot(object->getFrame(), object->posX, object->posY);
    }
}


