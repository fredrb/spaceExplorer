//
// Created by fredrb on 9/29/16.
//

#ifndef STAR_EXPLORER_GAMEOBJECT_H
#define STAR_EXPLORER_GAMEOBJECT_H


#include "render/Animation.h"

class GameObject {
public:
    GameObject(int frameCount) : frameCount(frameCount), posY(0), posX(0), layerPosX(0), layerPoxY(0) {};
    ~GameObject() {};
    void nextFrame();
    void setSprite(Render::Animation* animation);
    Render::Image* getFrame();
    int posX;
    int posY;
    int layerPosX;
    int layerPoxY;
private:
    Render::Animation* animation;
    int currentFrame = 0;
    int frameCount;
};


#endif //STAR_EXPLORER_GAMEOBJECT_H
