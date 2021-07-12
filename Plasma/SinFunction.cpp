#include "../QuickCG/quickcg.h"
#include <cmath>
using namespace QuickCG;
using namespace std;

int main(int argc, char *argv[])
{
    screen(256, 256, 0, "Plasma");

    for(int y = 0; y < h; y++)
    for(int x = 0; x < w; x++)
    {
        int color = int(128.0 + (128.0 * sin(x / 8.0)));
        pset(x, y, ColorRGB(color, color, color));
    }
    redraw();
    sleep();
    return(0);
}
