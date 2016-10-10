//
// Created by VitorVRS on 10/7/16.
//

#ifndef STAR_EXPLORER_SCREEN_PLAY_H
#define STAR_EXPLORER_SCREEN_PLAY_H

#include "../render/Image.h"
#include "../game/Movement.h"
#include "../render/Layer.h"
#include "../render/Text.h"
#include "../IGlutCallback.h"
#include "../GameCallback.h"

#include <GL/gl.h>
#include <GL/glut.h>

extern Render::Image *gameImage;
extern Render::Layer *starfield, *background, *objectlayer;
extern GameObject *player;

namespace Screen {

    class Play: public IGlutCallback {

    public:
        Play();
        ~Play();
        virtual void display();
        virtual void update(int value);
        virtual void mouse();
        virtual void specialKeys(int key, int x, int y);
        virtual void keyboard(unsigned char key, int x, int y);
        virtual bool collide(GameObject *object1, GameObject *object2);

    private:
        int score;
        Render::Text * scoreboard;
        std::vector<GameObject*> enemies;
        bool checkPlayerCollision();
        void removeOutOfRangeEnemies();
        void spawnEnemy();
        void raiseDifficulty();

        int maxEnemy;
        int enemyRatio;
        int enemySpeed;

    };

}

#endif // STAR_EXPLORER_SCREEN_PLAY_H
