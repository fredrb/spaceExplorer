//
// Created by VitorVRS on 10/9/16.
//

#ifndef STAR_EXPLORER_SCREEN_GAMEOVER_H
#define STAR_EXPLORER_SCREEN_GAMEOVER_H

#include "../render/Image.h"
#include "../render/Layer.h"
#include "../render/Text.h"
#include "../IGlutCallback.h"
#include "../GameCallback.h"

#include <GL/gl.h>
#include <GL/glut.h>

extern Render::Image *gameImage;
extern Render::Layer *starfield, *background;

namespace Screen {

    class GameOver: public IGlutCallback {

    public:
        GameOver();
        ~GameOver();
        virtual void display();
        virtual void update(int value);
        virtual void mouse();
        virtual void specialKeys(int key, int x, int y);
        virtual void keyboard(unsigned char key, int x, int y);

    private:
        Render::Text * gameOverMessage;
        Render::Text * message;
    };

}

#endif // STAR_EXPLORER_SCREEN_GAMEOVER_H
