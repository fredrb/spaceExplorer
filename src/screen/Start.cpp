//
// Created by VitorVRS on 10/7/16.
//

#include "Start.h"

Screen::Start::Start() {
    this->start = new Render::Text("STAR EXPLORER", 0, 300);
    this->start->setX(400 - (this->start->getWidth()/2));
    this->message = new Render::Text("Press ENTER or SPACE to start", 0, 285);
    this->message->setFont(GLUT_BITMAP_HELVETICA_12);
    this->message->setX(400 - (this->message->getWidth()/2));
}

Screen::Start::~Start() {
    delete this->start;
    delete this->message;
}

void Screen::Start::display() {
    glRasterPos2f(0, 0);
    glDrawPixels(gameImage->getWidth(), gameImage->getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE, gameImage->getPixels());
    this->start->print();
    this->message->print();
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
        // enter
        case 13:
        // space
        case 32:
            GameCallback::changeScreen(GameCallback::Play);
            break;
        default:break;
    }

}
