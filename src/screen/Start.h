//
// Created by VitorVRS on 10/7/16.
//

#ifndef STAR_EXPLORER_SCREEN_START_H
#define STAR_EXPLORER_SCREEN_START_H

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

    class Start: public IGlutCallback {

    public:
        Start();
        ~Start();
        virtual void display();
        virtual void update(int value);
        virtual void mouse();
        virtual void specialKeys(int key, int x, int y);
        virtual void keyboard(unsigned char key, int x, int y);

    private:
        Render::Text * start;
        Render::Text * message;
    };

}

#endif // STAR_EXPLORER_SCREEN_START_H
