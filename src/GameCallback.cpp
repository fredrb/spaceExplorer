#include "GameCallback.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstring>

namespace GameCallback {

    void display() {
        currentScreen->display();
    }

    void specialKeys(int key, int x, int y) {
        currentScreen->specialKeys(key, x, y);
    }

    void keyboard(unsigned char key, int x, int y) {
        currentScreen->keyboard(key, x, y);
    }

    void mouse() {
        currentScreen->mouse();
    }

    void update(int value) {
        timer->start();
        currentScreen->update(value);
        timer->stop();

        int waitingTime = (int) ((1000 / FPS) - timer->getElapsedTime());

        std::cout << "ET: " << timer->getElapsedTime() << " TIME: " << waitingTime << std::endl;

        if (waitingTime < 0) {
            waitingTime = 0;
        }

        glutPostRedisplay();
        value += 1;
        glutTimerFunc((unsigned int) waitingTime, update, value);
    }

    void changeScreen(AVAL_SCREENS screen) {

        delete currentScreen;

        switch (screen) {
            case Start:
                currentScreen = new Screen::Start();
            break;
            case Play :
                currentScreen = new Screen::Play();
            break;

            case GameOver:
                currentScreen = new Screen::GameOver();
            break;

            default:
            break;
        }

    }

}
