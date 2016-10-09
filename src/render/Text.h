//
// Created by VitorVRS on 9/28/16.
//

#ifndef STAR_EXPLORER_TEXT_H
#define STAR_EXPLORER_TEXT_H

#include <string>
#include <GL/gl.h>
#include <GL/glut.h>

namespace Render {
    class Text {
    private:
        std::string text;
        void *font;
        unsigned int posX;
        unsigned int posY;
    public:
        Text(std::string text, unsigned int x, unsigned int y) : text(text), posX(x), posY(y), font(GLUT_BITMAP_HELVETICA_18) {};
        void setText(std::string text);
        void print();
        void setFont(void *font);
        void setX(unsigned int x);
        void setY(unsigned int y);
        int getWidth();
    };
}

#endif //STAR_EXPLORER_TEXT_H
