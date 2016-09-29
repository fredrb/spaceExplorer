
#include "Movement.h"

void moveUp(GameObject* object) {
    if (object->yspeed < 0) {
        object->yspeed = 0;
    } else {
        if (object->yspeed < object->speedCap)
            object->yspeed += 1;
    }
}

void moveDown(GameObject* object) {
    if (object->yspeed > 0) {
        object->yspeed = 0;
    } else {
        if (object->yspeed > (object->speedCap * -1))
            object->yspeed -= 1;
    }
}

void GameLogic::move(GameObject *object, MOVEMENT_DIRECTION direction) {
    switch (direction) {
        case Up:
            moveUp(object);
            break;
        case Down:
            moveDown(object);
            break;
        default:
            break;
    }
}

