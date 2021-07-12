#include "../QuickCG/quickcg.h"
#include <cmath>
using namespace QuickCG;
using namespace std;

//Declaration of the drawSierpinski function. The coordinates are the 3 outer corners of the Sierpinski Triangle.
void drawSierpinski(float x1, float y1, float x2, float y2, float x3, float y3);
//Declaration of the subTriangle function, the coordinates are the 3 corners, and n is the number of recursions.
void subTriangle(int n, float x1, float y1, float x2, float y2, float x3, float y3);

//depth is the number of recursive steps
int depth = 7;

//The main function sets up the screen and then calls the drawSierpinski function
int main(int argc, char *argv[])
{
  screen(640, 480, 0, "Sierpinski Triangle");
  cls(RGB_White); //Make the background white
  drawSierpinski(10, h - 10, w - 10, h - 10, w / 2, 10); //Call the sierpinski function (works with any corners inside the screen)
  //After drawing the whole thing, redraw the screen and wait until the any key is pressed
  redraw();
  sleep();
  return(0);
}

//This function will draw only one triangle, the outer triangle (the only not upside down one), and then start the recursive function
void drawSierpinski(float x1, float y1, float x2, float y2, float x3, float y3)
{
    //Draw the 3 sides of the triangle as black lines
    drawLine(int(x1), int(y1), int(x2), int(y2), RGB_Black);
    drawLine(int(x1), int(y1), int(x3), int(y3), RGB_Black);
    drawLine(int(x2), int(y2), int(x3), int(y3), RGB_Black);

    //Call the recursive function that'll draw all the rest. The 3 corners of it are always the centers of sides, so they're averages
    subTriangle
    (
      1, //This represents the first recursion
      (x1 + x2) / 2, //x coordinate of first corner
      (y1 + y2) / 2, //y coordinate of first corner
      (x1 + x3) / 2, //x coordinate of second corner
      (y1 + y3) / 2, //y coordinate of second corner
      (x2 + x3) / 2, //x coordinate of third corner
      (y2 + y3) / 2  //y coordinate of third corner
    );
}

//The recursive function that'll draw all the upside down triangles
void subTriangle(int n, float x1, float y1, float x2, float y2, float x3, float y3)
{
  //Draw the 3 sides as black lines
  drawLine(int(x1), int(y1), int(x2), int(y2), RGB_Black);
  drawLine(int(x1), int(y1), int(x3), int(y3), RGB_Black);
  drawLine(int(x2), int(y2), int(x3), int(y3), RGB_Black);

  //Calls itself 3 times with new corners, but only if the current number of recursions is smaller than the maximum depth
  if(n < depth)
  {
    //Smaller triangle 1
    subTriangle
    (
      n+1, //Number of recursions for the next call increased with 1
      (x1 + x2) / 2 + (x2 - x3) / 2, //x coordinate of first corner
      (y1 + y2) / 2 + (y2 - y3) / 2, //y coordinate of first corner
      (x1 + x2) / 2 + (x1 - x3) / 2, //x coordinate of second corner
      (y1 + y2) / 2 + (y1 - y3) / 2, //y coordinate of second corner
      (x1 + x2) / 2, //x coordinate of third corner
      (y1 + y2) / 2  //y coordinate of third corner
    );
    //Smaller triangle 2
    subTriangle
    (
      n+1, //Number of recursions for the next call increased with 1
      (x3 + x2) / 2 + (x2 - x1) / 2, //x coordinate of first corner
      (y3 + y2) / 2 + (y2 - y1) / 2, //y coordinate of first corner
      (x3 + x2) / 2 + (x3 - x1) / 2, //x coordinate of second corner
      (y3 + y2) / 2 + (y3 - y1) / 2, //y coordinate of second corner
      (x3 + x2) / 2, //x coordinate of third corner
      (y3 + y2) / 2  //y coordinate of third corner
    );
    //Smaller triangle 3
    subTriangle
    (
      n+1, //Number of recursions for the next call increased with 1
      (x1 + x3) / 2 + (x3 - x2) / 2, //x coordinate of first corner
      (y1 + y3) / 2 + (y3 - y2) / 2, //y coordinate of first corner
      (x1 + x3) / 2 + (x1 - x2) / 2, //x coordinate of second corner
      (y1 + y3) / 2 + (y1 - y2) / 2, //y coordinate of second corner
      (x1 + x3) / 2, //x coordinate of third corner
      (y1 + y3) / 2  //y coordinate of third corner
    );
  }
}


