//
// Created by VitorVRS on 10/7/16.
//

#include "Play.h"

using namespace Screen;

Play::Play() {
    this->score = 0;
    this->scoreboard = new Render::Text("Score: ", 5, 5);
    player->posX = 50;
    player->posY = 300;
    player->speedCap = 7;
    player->xspeed = 0;
    player->yspeed = 0;

}

void Play::display() {
    glRasterPos2f(0, 0);
    glDrawPixels(gameImage->getWidth(), gameImage->getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE, gameImage->getPixels());
    scoreboard->print();
    glutSwapBuffers();
}

void Play::update(int value) {

    gameImage->plot(background->viewport, 0, 0);
    gameImage->plot(starfield->viewport, 0, 0);
    gameImage->plot(objectlayer->viewport, 0, 0);

    starfield->scrollRight();
    background->scrollRight();

    this->score += (value * 0.1 );
    scoreboard->setText("Score:" + std::to_string(score));

    // if collides then GameCallback::changeScreen(GameCallback::GameOver);

    objectlayer->refresh();
}

void Play::mouse() {}
void Play::keyboard(unsigned char key, int x, int y) {

    switch (key) {
        case 27:
            GameCallback::changeScreen(GameCallback::Start);
        break;

        default:
        break;
    }
}


void Play::specialKeys(int key, int x, int y) {
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

bool Play::collide(GameObject *object1, GameObject *object2) {

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
