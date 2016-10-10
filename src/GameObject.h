#ifndef STAR_EXPLORER_GAMEOBJECT_H
#define STAR_EXPLORER_GAMEOBJECT_H

#include "render/Animation.h"

class GameObject {
public:
    GameObject(int frameCount) : frameCount(frameCount), posY(0), posX(0), layerPosX(0), layerPoxY(0), xspeed(0), yspeed(0), speedCap(3) {};
    ~GameObject() {};
    void nextFrame();
    void setSprite(Render::Animation* animation);
    virtual void refresh();
    bool hasPositionChanged();
    bool checkPointCollision(int x, int y);
    Render::Image* getFrame();
    int posX;
    int posY;
    int xspeed;
    int yspeed;
    int speedCap;
private:
    int layerPosX;
    int layerPoxY;
    Render::Animation* animation;
    int currentFrame = 0;
    int frameCount;
};


#endif //STAR_EXPLORER_GAMEOBJECT_H
