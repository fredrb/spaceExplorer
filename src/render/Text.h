//
// Created by VitorVRS on 9/28/16.
//

#ifndef STAR_EXPLORER_TEXT_H
#define STAR_EXPLORER_TEXT_H

#include <string>

namespace Render {
    class Text {
    private:
        std::string text;
        unsigned int posX;
        unsigned int posY;
    public:
        Text(std::string text, unsigned int x, unsigned int y) : text(text), posX(x), posY(y) {};
        void setText(std::string text);
        void print();
    };
}

#endif //STAR_EXPLORER_TEXT_H
