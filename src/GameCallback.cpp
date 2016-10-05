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

        timer->start();

        gameImage->plot(background->viewport, 0, 0);
        gameImage->plot(starfield->viewport, 0, 0);
        gameImage->plot(objectlayer->viewport, 0, 0);

        starfield->scrollRight();
        background->scrollRight();

        score += (value * 0.1 );
        scoreboard->setText("Score:" + std::to_string(score));

        objectlayer->refresh();

        timer->stop();

        int waitingTime = (1000 / FPS) - timer->getElapsedTime();
        value = waitingTime;

        std::cout << "ET: " << timer->getElapsedTime() << " TIME: " << waitingTime << std::endl;

        if (waitingTime < 0) {
            waitingTime = 0;
            value = 10;
        }

        glutPostRedisplay();
        glutTimerFunc(waitingTime, update, value);
    }

    bool collide(GameObject *object1, GameObject *object2) {

        int x1 = object2->posX;
        int y1 = object2->posY;

        int x2 = object2->posX + object2->getFrame()->getWidth();
        int y2 = object2->posY;

        int x3 = object2->posX + object2->getFrame()->getWidth();
        int y3 = object2->posY + object2->getFrame()->getHeight();

        int x4 = object2->posX;
        int y4 = object2->posY + object2->getFrame()->getHeight();

        return
            object1->checkPointCollision(x1,y1)
         || object1->checkPointCollision(x2,y2)
         || object1->checkPointCollision(x3,y3)
         || object1->checkPointCollision(x4,y4);
    }

}
