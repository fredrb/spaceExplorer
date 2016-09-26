//
// Created by fredrb on 9/24/16.
//

#ifndef STAR_EXPLORER_GAMECALLBACK_H
#define STAR_EXPLORER_GAMECALLBACK_H

#include "render/Image.h"
#include "render/Animation.h"

extern Render::Image *gameImage, *background, *starfield;
extern Render::Animation *playerAnimation;

namespace GameCallback {
    void display();
    void keyboard();
    void mouse();
    void update(int value);
}

#endif //STAR_EXPLORER_GAMECALLBACK_H
