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

    enemySpeed = 3;
    enemyRatio = 75;
    maxEnemy = 3;

    enemies = std::vector<GameObject*>();
    std::srand((unsigned int) time(NULL));

}

void Play::display() {
    glRasterPos2f(0, 0);
    glDrawPixels(gameImage->getWidth(), gameImage->getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE, gameImage->getPixels());
    scoreboard->print();
    glutSwapBuffers();
}

void Play::update(int value) {
    removeOutOfRangeEnemies();
    raiseDifficulty();

    if (enemies.size() < this->maxEnemy && (value % enemyRatio == 0)) {
        this->spawnEnemy();
    }

    gameImage->plot(background->viewport, 0, 0);
    gameImage->plot(starfield->viewport, 0, 0);
    gameImage->plot(objectlayer->viewport, 0, 0);

    starfield->scrollRight();
    background->scrollRight();

    this->score += ((value - this->score) * 0.1);
    scoreboard->setText("Score:" + std::to_string(score));

    if (checkPlayerCollision()) {
        GameCallback::changeScreen(GameCallback::GameOver);
    }

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

void Play::removeOutOfRangeEnemies() {
    for (unsigned long i = 0; i < enemies.size(); i++) {
        if (enemies.at(i)->posX < 0) {
            objectlayer->removeObject(enemies.at(i));
            delete enemies.at(i);
            enemies.erase(enemies.begin() + i);
        }
    }
}

void Play::spawnEnemy() {
    GameObject* obj = new GameObject(6);
    obj->setSprite(enemyAnimation);
    obj->posX = objectlayer->viewport->getWidth();
    obj->posY = std::rand() % objectlayer->viewport->getHeight() - 10;
    obj->xspeed = - (this->enemySpeed);
    obj->yspeed = 0;
    enemies.push_back(obj);
    objectlayer->addObject(obj);
}

void Play::raiseDifficulty() {
    switch (this->score / 200) {
        case 1:
            enemySpeed = 3;
            enemyRatio = 75;
            maxEnemy = 3;
            break;
        case 2:
            enemySpeed = 4;
            enemyRatio = 60;
            maxEnemy = 4;
            break;
        case 3:
            enemySpeed = 6;
            enemyRatio = 30;
            maxEnemy = 5;
        case 4:
            enemySpeed = 9;
            enemyRatio = 25;
            maxEnemy = 6;
        case 5:
            enemySpeed = 9;
            enemyRatio = 15;
            maxEnemy = 9;
        default:break;
    }
}

bool Play::checkPlayerCollision() {
    for (unsigned long i = 0; i < enemies.size(); i++) {
        GameObject* enemy = enemies.at(i);
        if (player->checkPointCollision(enemy->posX, enemy->posY)) {
            return true;
        }
    }

    return false;
}
