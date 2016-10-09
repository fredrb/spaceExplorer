#include <iostream>
#include "src/Game.h"
#include "src/GameCallback.h"
#include "src/file/PTMFileReader.h"
#include "src/common/SpriteLoader.h"
#include "src/IGlutCallback.h"

IGlutCallback *currentScreen;

Render::Image *gameImage;
Render::Animation *enemyAnimation;
Render::Layer *starfield, *background, *objectlayer;
Timer *timer;
GameObject *player;

void loadBackground() {
    File::PTMFileReader filereader = File::PTMFileReader();
    File::t_image img = filereader.loadImage((char *) "../resource/background.ptm");
    SpriteLoader loader = SpriteLoader(img);

    Render::Image* bg = loader.getImage();
    background = new Render::Layer(800, 600, 1, 0);
    background->plot(bg, nullptr);
}

void loadStarField() {
    File::PTMFileReader filereader = File::PTMFileReader();
    File::t_image img = filereader.loadImage((char *) "../resource/starfield.ptm");
    SpriteLoader loader = SpriteLoader(img);

    Render::Image* starfieldImg = loader.getImage();
    starfield = new Render::Layer(starfieldImg->getWidth(), starfieldImg->getHeight(), 2, 0);
    starfield->plot(starfieldImg, nullptr);
}

void loadPlayer() {
    File::PTMFileReader filereader = File::PTMFileReader();
    File::t_image img = filereader.loadImage((char *) "../resource/rocket.ptm");
    SpriteLoader loader = SpriteLoader(img);

    Render::Animation* playerAnimation = loader.getAnimation(1, 4);

    player = new GameObject(4);
    player->setSprite(playerAnimation);

    objectlayer = new Render::Layer(800, 600, 0, 0);
    objectlayer->addObject(player);
}

void loadEnemyimage() {
    File::PTMFileReader filereader = File::PTMFileReader();
    File::t_image img = filereader.loadImage((char *) "../resource/enemy.ptm");
    SpriteLoader loader = SpriteLoader(img);
    enemyAnimation = loader.getAnimation(1, 6);
}

int main(int argc,  char** argv) {
    Game startExplorer = Game();

    startExplorer.setPosition(300, 200);
    startExplorer.setSize(800, 600);
    startExplorer.setTitle((char *) "Star explorer");

    loadBackground();
    loadPlayer();
    loadStarField();
    loadEnemyimage();

    startExplorer.init(argc, argv);
    return 0;
}
