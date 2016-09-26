#include "GameCallback.h"
#include "file/PTMFileReader.h"
#include "common/SpriteLoader.h"

#include <GL/gl.h>
#include <GL/glut.h>

namespace GameCallback {

    void display() {
        if (gameImage != NULL) {
            glDrawPixels(gameImage->getWidth(), gameImage->getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE, gameImage->getPixels());
        }

        glutSwapBuffers();
    }

    void keyboard() {

    }

    void mouse() {

    }

    Render::Image* getCurrentPlayerFrame(int timerValue) {
        return playerAnimation->getFrame(timerValue % 4);
    }

    void plotStarfield(int value) {
        value = value % 600;

        Render::Image *chopped = new Render::Image(value, background->getHeight());
        starfield->subImage(chopped, 0, 0);

        Render::Image *newPosition = new Render::Image(starfield->getWidth() - value, starfield->getHeight());
        starfield->subImage(newPosition, value, 0);

        gameImage->plot(chopped, newPosition->getWidth(), 0);
        gameImage->plot(newPosition, 0, 0);

        delete(chopped);
        delete(newPosition);
    }

    void update(int value) {
        gameImage = new Render::Image(1782, 600);
        gameImage->plot(background, 0, 0);
        plotStarfield(value);
        gameImage->plot(getCurrentPlayerFrame(value), 100, 100);
        glutPostRedisplay();
        glutTimerFunc(10, update, value + 1);
    }


}

