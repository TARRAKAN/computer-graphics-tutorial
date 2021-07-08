#include "../QuickCG/quickcg.h"
using namespace QuickCG;
using namespace std;

int main(int argc, char *argv[])
{
  unsigned long w = 0, h = 0;
  std::vector<ColorRGB> image;
  loadImage(image, w, h, "flower.png");
  screen(w, h, 0, "RGB Color");

  ColorRGB color; //the color for the pixels

  for(int y = 0; y < h; y++)
  for(int x = 0; x < w; x++)
  {
    //here the negative color is calculated!
    color.r = int(image[y * w + x].r / 1.5);
    color.g = int(image[y * w + x].g / 1.5);
    color.b = int(image[y * w + x].b / 1.5);
    pset(x, y, color);
  }

  redraw();
  sleep();
  return 0;
}
