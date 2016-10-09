//
// Created by VitorVRS on 9/28/16.
//

#include "Text.h"

void Render::Text::setText(std::string text) {
    this->text = text;
}

void Render::Text::print() {

    glRasterPos2f(this->posX, this->posY);
    for (char c : this->text) {
        glutBitmapCharacter(this->font, c);
    }
};

void Render::Text::setFont(void *font) {
    this->font = font;
};

void Render::Text::setX(unsigned int x) {
    this->posX = x;
};

void Render::Text::setY(unsigned int y) {
    this->posY = y;
};

int Render::Text::getWidth() {
    int width = 0;

    for (char c : this->text) {
        width += glutBitmapWidth(this->font, c);
    }

    return width;
};
