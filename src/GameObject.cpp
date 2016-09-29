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
