//
// Created by fredrb on 9/29/16.
//

#include "GameObject.h"

void GameObject::nextFrame() {
    if (currentFrame == (frameCount - 1))
        currentFrame = 0;
    else
        currentFrame++;
}

void GameObject::setSprite(Render::Animation *animation) {
    this->animation = animation;
}

Render::Image *GameObject::getFrame() {
    return this->animation->getFrame(currentFrame);
}

bool GameObject::hasPositionChanged() {
    return (this->posX != this->layerPosX || this->posY != this->layerPoxY);
}

void GameObject::refresh() {
    posX += xspeed;
    posY += yspeed;
}
