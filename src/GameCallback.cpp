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

    Render::Image* getCurrentPlayerFrame(int timerValue) {
        return playerAnimation->getFrame(timerValue % 4);
    }

    void plotStarfield(int value) {
        value = value % 600;
        Render::Image* star_one = new Render::Image(starfield->getWidth() - value, starfield->getHeight());
        Render::Image* star_two = new Render::Image(value, starfield->getHeight());

        starfield->subImage(star_one, value, 0);
        starfield->subImage(star_two, value, 0);

        gameImage->plot(star_one, 0, 0);
        gameImage->plot(star_two, starfield->getWidth() - value, 0);

        delete(star_one);
        delete(star_two);
    }

    void update(int value) {

        gameImage->plot(background, 0, 0);
        plotStarfield(value);
        gameImage->plot(getCurrentPlayerFrame(value), 100, 100);

        glutPostRedisplay();
        glutTimerFunc(10, update, value + 1);
    }


}
