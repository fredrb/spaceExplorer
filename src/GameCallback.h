//
// Created by fredrb on 9/24/16.
//

#ifndef STAR_EXPLORER_GAMECALLBACK_H
#define STAR_EXPLORER_GAMECALLBACK_H

#include "render/Image.h"
#include "render/Animation.h"
#include "render/Layer.h"
#include "GameObject.h"

extern Render::Image *gameImage;
extern Render::Layer *starfield, *background, *objectlayer;
extern GameObject *player;

namespace GameCallback {
    void display();
    void specialKeys(int key, int x, int y);
    void specialUpKeys(int key, int x, int y);
    void mouse();
    void update(int value);
}

#endif //STAR_EXPLORER_GAMECALLBACK_H
