#include "../QuickCG/quickcg.h"
#include <cmath>
using namespace QuickCG;
using namespace std;

int main(int argc, char *argv[])
{
  screen(256, 256, 0, "AND");
  for(int y = 0; y < h; y++)
  for(int x = 0; x < w; x++)
  {
    if(x & y) pset(x, y, RGB_White);
  }
  redraw();
  sleep();
  return 0;
}
