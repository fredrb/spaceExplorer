//
// Created by frederico on 9/12/16.
//

#include "Animation.h"

using namespace Render;

Image *Animation::getFrame(int index) {
    // Image* img = frames.at(index);
    Image* img = this->frames[index];
    return img;
}

Animation::Animation() {
    // frames = std::vector<Image*>(20);
    frames = new Image*[20];
    frameCount = 0;
}

void Animation::addFrame(Image *image) {
    frames[frameCount] = image;
    // frames.push_back(image);
    frameCount++;
}

