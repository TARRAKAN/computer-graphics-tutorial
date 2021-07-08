#include "../QuickCG/quickcg.h"
using namespace QuickCG;
using namespace std;

int main(int argc, char *argv[])
{
    ColorRGB colorRGB;
    ColorHSL colorHSL;

    unsigned long w, h;
    std::vector<ColorRGB> image;
    loadImage(image, w, h, "flower.png");
    screen(w, h, 0, "RGB Color");

    for(int y = 0; y < h; y++)
    for(int x = 0; x < w; x++)
    {
        //store the color of the image in variables R, G and B
        colorRGB = image[y * w + x];
        //calculate H, S and L out of R, G and B
        colorHSL = RGBtoHSL(colorRGB);
        //change Hue
        colorHSL.h += int(42.5 * 1);
        colorHSL.h %= 255;
        //convert back to RGB
        colorRGB = HSLtoRGB(colorHSL);
        //plot the pixel
        pset(x, y, colorRGB);
    }
    redraw();
    sleep();
    return 0;
}

