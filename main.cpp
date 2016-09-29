#include <iostream>
#include "src/Game.h"
#include "src/GameCallback.h"
#include "src/file/PTMFileReader.h"
#include "src/common/SpriteLoader.h"

Render::Image *gameImage, *starfield;
Render::Layer *parallax, *background;
Render::Animation *playerAnimation;

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

    starfield = loader.getImage();
    parallax = new Render::Layer(starfield->getWidth(), starfield->getHeight(), 3, 0);
    parallax->plot(starfield, nullptr);
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
    startExplorer.setSize(800, 600);
    startExplorer.setTitle((char *) "Star explorer");

    loadBackground();
    loadPlayer();
    loadStarField();

    startExplorer.init(argc, argv);
    return 0;
}