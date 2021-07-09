#include "../QuickCG/quickcg.h"
#include <cmath>
using namespace QuickCG;
using namespace std;

int main(int argc, char *argv[])
{
  unsigned long w = 0, h = 0;

  std::vector<ColorRGB> image1, image2, image3, result;

  loadImage(image1, w, h, "photo1.png");
  loadImage(image2, w, h, "photo2.png");
  loadImage(image3, w, h, "photo3.png");
  result.resize(w * h);

  screen(w,h,0, "Image Arithmetic");

  for(int y = 0; y < h; y++)
  for(int x = 0; x < w; x++)
  {
    //Average
    //result[y * w + x].r = (image1[y * w + x].r + image2[y * w + x].r) / 2;
    //result[y * w + x].g = (image1[y * w + x].g + image2[y * w + x].g) / 2;
    //result[y * w + x].b = (image1[y * w + x].b + image2[y * w + x].b) / 2;
    
    //Add
    //result[y * w + x].r = min(image1[y * w + x].r + image2[y * w + x].r, 255);
    //result[y * w + x].g = min(image1[y * w + x].g + image2[y * w + x].g, 255);
    //result[y * w + x].b = min(image1[y * w + x].b + image2[y * w + x].b, 255);
    
    //Substaract
    //result[y * w + x].r = max(image2[y * w + x].r - image1[y * w + x].r, 0);
    //result[y * w + x].g = max(image2[y * w + x].g - image1[y * w + x].g, 0);
    //result[y * w + x].b = max(image2[y * w + x].b - image1[y * w + x].b, 0);
    
    //Difference
    //result[y * w + x].r = abs(image1[y * w + x].r - image2[y * w + x].r);
    //result[y * w + x].g = abs(image1[y * w + x].g - image2[y * w + x].g);
    //result[y * w + x].b = abs(image1[y * w + x].b - image2[y * w + x].b);
    
    //Multiply
    //result[y * w + x].r = int(255 * (image2[y * w + x].r / 255.0 * image1[y * w + x].r / 255.0));
    //result[y * w + x].g = int(255 * (image2[y * w + x].g / 255.0 * image1[y * w + x].g / 255.0));
    //result[y * w + x].b = int(255 * (image2[y * w + x].b / 255.0 * image1[y * w + x].b / 255.0));
    
    //Cross Fading
    //result[y * w + x].r = int(image1[y * w + x].r * 0.75 + image2[y * w + x].r * 0.25);
    //result[y * w + x].g = int(image1[y * w + x].g * 0.75 + image2[y * w + x].g * 0.25);
    //result[y * w + x].b = int(image1[y * w + x].b * 0.75 + image2[y * w + x].b * 0.25);
    
    //MinMax
    result[y * w + x].r = min(image1[y * w + x].r, image3[y * w + x].r);
    result[y * w + x].g = min(image1[y * w + x].g, image3[y * w + x].g);
    result[y * w + x].b = min(image1[y * w + x].b, image3[y * w + x].b);
    
    
    
  }

  for(int y = 0; y < h; y++)
  for(int x = 0; x < w; x++)
  {
    pset(x, y, result[y * w + x]);
  }

  redraw();
  sleep();
}


