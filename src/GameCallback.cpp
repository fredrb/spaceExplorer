#include "GameCallback.h"
#include "game/Movement.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstring>

namespace GameCallback {

    void display() {
        glRasterPos2f(0, 0);
        glDrawPixels(gameImage->getWidth(), gameImage->getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE, gameImage->getPixels());
        scoreboard->print();
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

        timer->stop();
        score += (timer->getElapsedTime() * 0.1 );
        scoreboard->setText("Score:" + std::to_string(score));
        timer->start();

        objectlayer->refresh();

        glutPostRedisplay();
        glutTimerFunc(2, update, value + 1);
    }

    bool collide(GameObject *object1, GameObject *object2) {

        int x1 = object1->posX;
        int y1 = object1->posY;

        int x2 = object1->posX + object2->getFrame()->getWidth();
        int y2 = object1->posY;

        int x3 = object1->posX + object2->getFrame()->getWidth();
        int y3 = object1->posY + object2->getFrame()->getHeight();

        int x4 = object1->posX;
        int y4 = object1->posY + object2->getFrame()->getHeight();

        return checkPointCollision(object2, x1,y1) || checkPointCollision(object2, x2,y2) || checkPointCollision(object2, x3,y3) || checkPointCollision(object2, x4,y4);
    }

    bool checkPointCollision(GameObject *object, int x, int y) {

        if (x >= object->posX && x < (object->posX + object->getFrame()->getWidth())) {

            if (y >= object->posY && y < (object->posY + object->getFrame()->getHeight())) {
                return true;
            }

        }

        return false;
    }

}
