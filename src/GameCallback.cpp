#include "GameCallback.h"
#include "file/PTMFileReader.h"
#include "common/SpriteLoader.h"
#include "game/Movement.h"

#include <iostream>

#include <GL/gl.h>
#include <GL/glut.h>

namespace GameCallback {

    void display() {
        glRasterPos2f(0, 0);
        glDrawPixels(gameImage->getWidth(), gameImage->getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE, gameImage->getPixels());
        glutSwapBuffers();
    }

    void specialKeys(int key, int x, int y) {
        switch (key) {
            case GLUT_KEY_UP:
                GameLogic::move(player, Up);
                break;
            case GLUT_KEY_DOWN:
                GameLogic::move(player, Down);
                break;
            default:break;
        }
    }

    void mouse() {

    }

    void update(int value) {

        gameImage->plot(background->viewport, 0, 0);
        gameImage->plot(starfield->viewport, 0, 0);
        gameImage->plot(objectlayer->viewport, 0, 0);

        starfield->scrollRight();
        background->scrollRight();
        // player->nextFrame();

        objectlayer->refresh();

        glutPostRedisplay();
        glutTimerFunc(2, update, value + 1);
    }

}
