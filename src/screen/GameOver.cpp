//
// Created by VitorVRS on 10/9/16.
//

#include "GameOver.h"

Screen::GameOver::GameOver() {
    this->gameOverMessage = new Render::Text("GAME OVER", 0, 300);
    this->gameOverMessage->setX(400 - (this->gameOverMessage->getWidth()/2));

    this->message = new Render::Text("Press ENTER or SPACE to continue", 0, 285);
    this->message->setFont(GLUT_BITMAP_HELVETICA_12);
    this->message->setX(400 - (this->message->getWidth()/2));
}

Screen::GameOver::~GameOver() {
    delete this->gameOverMessage;
    delete this->message;
}

void Screen::GameOver::display() {
    glRasterPos2f(0, 0);
    glDrawPixels(gameImage->getWidth(), gameImage->getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE, gameImage->getPixels());
    this->gameOverMessage->print();
    this->message->print();
    glutSwapBuffers();
}

void Screen::GameOver::update(int value) {
    gameImage->plot(background->viewport, 0, 0);
    gameImage->plot(starfield->viewport, 0, 0);
    background->scrollRight();
    starfield->scrollRight();
}

void Screen::GameOver::mouse() {}
void Screen::GameOver::specialKeys(int key, int x, int y) {}

void Screen::GameOver::keyboard(unsigned char key, int x, int y) {

    switch (key) {
        // enter
        case 13:
        // space
        case 32:
            GameCallback::changeScreen(GameCallback::Start);
            break;
        default:break;
    }

}
