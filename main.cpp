#include <iostream>
#include "src/Game.h"
#include "src/GameCallback.h"
#include "src/file/PTMFileReader.h"
#include "src/common/SpriteLoader.h"

Render::Image *gameImage, *background, *starfield;
Render::Animation *playerAnimation;

void loadBackground() {
    File::PTMFileReader filereader = File::PTMFileReader();
    File::t_image img = filereader.loadImage((char *) "../resource/background.ptm");
    SpriteLoader loader = SpriteLoader(img);

    background = loader.getImage();
}

void loadStarField() {
    File::PTMFileReader filereader = File::PTMFileReader();
    File::t_image img = filereader.loadImage((char *) "../resource/starfield.ptm");
    SpriteLoader loader = SpriteLoader(img);

    starfield = loader.getImage();
}

void loadPlayer() {
    File::PTMFileReader filereader = File::PTMFileReader();
    File::t_image img = filereader.loadImage((char *) "../resource/rocket.ptm");
    SpriteLoader loader = SpriteLoader(img);

    playerAnimation = loader.getAnimation(1, 4);
}

int main(int argc,  char** argv) {
    Game startExplorer = Game();

    startExplorer.setPosition(300, 200);
    startExplorer.setSize(1782, 600);
    startExplorer.setTitle((char *) "Star explorer");

    loadBackground();
    loadPlayer();
    loadStarField();

    startExplorer.init(argc, argv);
    return 0;
}