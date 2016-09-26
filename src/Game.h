//
// Created by fredrb on 9/24/16.
//

#ifndef STAR_EXPLORER_GAME_H
#define STAR_EXPLORER_GAME_H

class Game {

public:
    Game() {};
    ~Game() {};
    void setSize(int width, int height);
    void setPosition(int x, int y);
    void setTitle(char* title);
    void init(int argc, char** argv);
private:
    char* title;
    int window_width;
    int window_height;
    int window_pos_x;
    int window_pos_y;
    void initGLDisplay();
};


#endif //STAR_EXPLORER_GAME_H
