#ifndef IMAGE_MANIPULATION_IMAGE_H
#define IMAGE_MANIPULATION_IMAGE_H

namespace Render {
    typedef struct {
        int alpha;
        int r;
        int g;
        int b;
    } t_image_pixel;

    class Image {
    public:
        Image(int w, int h);
        void setPixel(int a, int r, int g, int b, int x, int y);
        int getPixel(int x, int y);
        int getWidth(){ return width; };
        int getHeight(){ return height; }
        int* getPixels() { return pixels; };
        void plot(Image *image, int sx, int sy);
        void subImage(Image* dest, int sx, int sy);
    private:
        int *pixels;
        int width, height;
        t_image_pixel unpackagePixel(int pixel);
    };
}

#endif //IMAGE_MANIPULATION_IMAGE_H
