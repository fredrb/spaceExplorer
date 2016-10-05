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

bool GameObject::checkPointCollision(int x, int y) {

    if (x >= this->posX && x < (this->posX + this->getFrame()->getWidth())) {

        if (y >= this->posY && y < (this->posY + this->getFrame()->getHeight())) {
            return true;
        }

    }

    return false;
}
