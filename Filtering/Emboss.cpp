#include "../QuickCG/quickcg.h"
using namespace QuickCG;
using namespace std;

#define filterWidth 5
#define filterHeight 5

double filter[filterHeight][filterWidth] =
{
  -1, -1, -1, -1,  0,
  -1, -1, -1,  0,  1,
  -1, -1,  0,  1,  1,
  -1,  0,  1,  1,  1,
   0,  1,  1,  1,  1
};

double factor = 1.0;
double bias = 128.0;

int main(int argc, char *argv[])
{
  //load the image into the buffer
  unsigned long w = 0, h = 0;
  std::vector<ColorRGB> image;
  loadImage(image, w, h, "photo3.png");
  std::vector<ColorRGB> result(image.size());

  //set up the screen
  screen(w, h, 0, "Filters");

  ColorRGB color; //the color for the pixels

  //apply the filter
  for(int x = 0; x < w; x++)
  for(int y = 0; y < h; y++)
  {
    double red = 0.0, green = 0.0, blue = 0.0;

    //multiply every value of the filter with corresponding image pixel
    for(int filterY = 0; filterY < filterHeight; filterY++)
    for(int filterX = 0; filterX < filterWidth; filterX++)
    {
      int imageX = (x - filterWidth / 2 + filterX + w) % w;
      int imageY = (y - filterHeight / 2 + filterY + h) % h;
      red += image[imageY * w + imageX].r * filter[filterY][filterX];
      green += image[imageY * w + imageX].g * filter[filterY][filterX];
      blue += image[imageY * w + imageX].b * filter[filterY][filterX];
    }

    //truncate values smaller than zero and larger than 255
    result[y * w + x].r = min(max(int(factor * red + bias), 0), 255);
    result[y * w + x].g = min(max(int(factor * green + bias), 0), 255);
    result[y * w + x].b = min(max(int(factor * blue + bias), 0), 255);
  }

  //draw the result buffer to the screen
  for(int y = 0; y < h; y++)
  for(int x = 0; x < w; x++)
  {
    pset(x, y, result[y * w + x]);
  }

  //redraw & sleep
  redraw();
  sleep();
}
