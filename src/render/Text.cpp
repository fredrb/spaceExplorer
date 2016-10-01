//
// Created by VitorVRS on 9/28/16.
//

#include "Text.h"

#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>


void Render::Text::setText(std::string text) {
    this->text = text;
}

void Render::Text::print() {

    glRasterPos2f(this->posX, this->posY);
    for (char c : this->text) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
};
