//
// Created by VitorVRS on 10/7/16.
//

#include "Start.h"

Screen::Start::Start() {
    this->start = new Render::Text("Start Game", 300, 300);
}

void Screen::Start::display() {
    glRasterPos2f(0, 0);
    glDrawPixels(gameImage->getWidth(), gameImage->getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE, gameImage->getPixels());
    this->start->print();
    glutSwapBuffers();
}

void Screen::Start::update(int value) {
    gameImage->plot(background->viewport, 0, 0);
    gameImage->plot(starfield->viewport, 0, 0);
    starfield->scrollRight();
    background->scrollRight();
}

void Screen::Start::mouse() {}
void Screen::Start::specialKeys(int key, int x, int y) {}

void Screen::Start::keyboard(unsigned char key, int x, int y) {

    switch (key) {
        case 'a':
            GameCallback::changeScreen(GameCallback::Play);
            break;
        default:break;
    }

}
