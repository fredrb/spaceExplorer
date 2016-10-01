//
// Created by fredrb on 9/24/16.
//

#include <GL/gl.h>
#include <GL/glut.h>
#include "Game.h"
#include "GameCallback.h"

void Game::setSize(int width, int height) {
    this->window_height = height;
    this->window_width = width;
}

void Game::setPosition(int x, int y) {
    this->window_pos_x = x;
    this->window_pos_y = y;

}

void Game::setTitle(char *title) {
    this->title = title;
}

void Game::init(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(this->window_width, this->window_height);
    glutInitWindowPosition(this->window_pos_x, this->window_pos_y);
    glutCreateWindow(this->title);

    this->initGLDisplay();

    gameImage = new Render::Image(this->window_width, this->window_height);

    glutTimerFunc(100, GameCallback::update, 1);
    glutDisplayFunc(GameCallback::display);
    glutSpecialFunc(GameCallback::specialKeys);

    glutMainLoop();
}

void Game::initGLDisplay() {
    glClearColor (0.0, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // @todo temos que remover o GL_BLEND, o calculo de alpha dever ser feito "na mao"
    // confirmar antes.
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    gluOrtho2D(0, this->window_width, 0, this->window_height);
}
