#include "Image.h"

using namespace Render;


Image::Image(int w, int h) {
    width = w; height = h;
    pixels = new int[w*h];
}

int Image::getPixel(int x, int y) {
    return pixels[x+y*width];
}

int packageBit(int a, int r, int g, int b) {
    return (a << 24) | (r << 16) | (g << 8) | b;
}

void Image::setPixel(int alpha, int r, int g, int b, int x, int y) {
    pixels[x+y*width] = packageBit(alpha, r, g, b);
}

void Image::plot(Image *image, int sx, int sy) {
    for (int y = 0; y < image->getHeight(); y++) {
        for (int x = 0; x < image->getWidth(); x++) {
            t_image_pixel imagePixel = this->unpackagePixel(image->getPixel(x, y));
            if (imagePixel.alpha == 255)
                this->setPixel(imagePixel.alpha, imagePixel.r, imagePixel.g, imagePixel.b, sx + x, sy + y);
        }
    }
}

t_image_pixel Image::unpackagePixel(int pixel) {
    t_image_pixel unpackaged;
    unpackaged.alpha = (pixel >> 24) & 0xff;
    unpackaged.r     = (pixel >> 16) & 0xff;
    unpackaged.g     = (pixel >> 8)  & 0xff;
    unpackaged.b     = (pixel)       & 0xff;

    return unpackaged;
}

void Image::subImage(Image *dest, int sx, int sy) {
    for (int y = 0; y < dest->getHeight(); y++) {
        for (int x = 0; x < dest->getWidth(); x++) {
            int pixel = this->getPixel(sx + x, sy + y);
            t_image_pixel imagePixel = this->unpackagePixel(pixel);
            dest->setPixel(imagePixel.alpha, imagePixel.r, imagePixel.g, imagePixel.b, x, y);
        }
    }
}
