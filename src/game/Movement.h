#ifndef STAR_EXPLORER_MOVEMENT_H
#define STAR_EXPLORER_MOVEMENT_H

#include "../GameObject.h"

enum MOVEMENT_DIRECTION {
    Up,
    Down
};

namespace GameLogic {
    void move(GameObject* object, MOVEMENT_DIRECTION direction);
}


#endif //STAR_EXPLORER_MOVEMENT_H
