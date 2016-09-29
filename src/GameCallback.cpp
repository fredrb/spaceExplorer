#include "GameCallback.h"
#include "file/PTMFileReader.h"
#include "common/SpriteLoader.h"

#include <iostream>

#include <GL/gl.h>
#include <GL/glut.h>

namespace GameCallback {

    void display() {
        glDrawPixels(gameImage->getWidth(), gameImage->getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE, gameImage->getPixels());
        glutSwapBuffers();
    }

    void keyboard() {

    }

    void mouse() {

    }

//    Render::Image* getCurrentPlayerFrame(int timerValue) {
//        return playerAnimation->getFrame(timerValue % 4);
//    }

    void update(int value) {
        gameImage->plot(background->viewport, 0, 0);
        gameImage->plot(starfield->viewport, 0, 0);
        gameImage->plot(player->getFrame(), 100, 100);

        starfield->scrollRight();
        background->scrollRight();
        player->nextFrame();

        glutPostRedisplay();
        glutTimerFunc(10, update, value + 1);
    }


}
