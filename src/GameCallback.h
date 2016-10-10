//
// Created by fredrb on 9/24/16.
//

#ifndef STAR_EXPLORER_GAMECALLBACK_H
#define STAR_EXPLORER_GAMECALLBACK_H

#define FPS 30

#include "game/Timer.h"
#include "IGlutCallback.h"
#include "screen/Play.h"
#include "screen/Start.h"
#include "screen/GameOver.h"

#include <iostream>

extern Render::Image *gameImage;
extern Render::Animation *enemyAnimation;
extern Render::Layer *starfield, *background, *objectlayer;
extern GameObject *player;
extern Timer *timer;
extern IGlutCallback *currentScreen;
extern bool gameReset;

namespace GameCallback {

    enum AVAL_SCREENS {Start, Play, GameOver};

    void display();
    void specialKeys(int key, int x, int y);
    void specialUpKeys(int key, int x, int y);
    void keyboard(unsigned char key, int x, int y);
    void mouse();
    void update(int value);
    void changeScreen(AVAL_SCREENS screen);
}

#endif //STAR_EXPLORER_GAMECALLBACK_H
