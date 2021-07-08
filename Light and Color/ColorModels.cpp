#include "../QuickCG/quickcg.h"
using namespace QuickCG;
using namespace std;

ColorHSL RGBtoHSL(ColorRGB colorRGB)
{
    float r, g, b, h, s, l; //this function works with floats between 0 and 1
    r = colorRGB.r / 256.0;
    g = colorRGB.g / 256.0;
    b = colorRGB.b / 256.0;
    float maxColor = max(r, max(g, b));
    float minColor = min(r, min(g, b));
    if(maxColor == minColor)
    {
        h = 0.0; //it doesn't matter what value it has
        s = 0.0;
        l = r; //doesn't matter if you pick r, g, or b
    }
    else
    {
        l = (minColor + maxColor) / 2;

        if(l < 0.5) s = (maxColor - minColor) / (maxColor + minColor);
        else s = (maxColor - minColor) / (2.0 - maxColor - minColor);

        if(r == maxColor) h = (g - b) / (maxColor - minColor);
        else if(g == maxColor) h = 2.0 + (b - r) / (maxColor - minColor);
        else h = 4.0 + (r - g) / (maxColor - minColor);

        h /= 6; //to bring it to a number between 0 and 1
        if(h < 0) h ++;
    }
    
    ColorHSL colorHSL;
    colorHSL.h = int(h * 255.0);
    colorHSL.s = int(s * 255.0);
    colorHSL.l = int(l * 255.0);
    return colorHSL;
}

ColorRGB HSLtoRGB(ColorHSL colorHSL)
{
    float r, g, b, h, s, l; //this function works with floats between 0 and 1
    float temp1, temp2, tempr, tempg, tempb;
    h = colorHSL.h / 256.0;
    s = colorHSL.s / 256.0;
    l = colorHSL.l / 256.0;
    
    if(s == 0)
    {
        r = g = b = l;
    }
    else
    {
        if(l < 0.5) temp2 = l * (1 + s);
        else temp2 = (l + s) - (l * s);
        temp1 = 2 * l - temp2;
        tempr = h + 1.0 / 3.0;
        if(tempr > 1) tempr--;
        tempg = h;
        tempb = h - 1.0 / 3.0;
        if(tempb < 0) tempb++;

        //Red
        if(tempr < 1.0 / 6.0) r = temp1 + (temp2 - temp1) * 6.0 * tempr;
        else if(tempr < 0.5) r = temp2;
        else if(tempr < 2.0 / 3.0) r = temp1 + (temp2 - temp1) * ((2.0 / 3.0) - tempr) * 6.0;
        else r = temp1;

        //Green
        if(tempg < 1.0 / 6.0) g = temp1 + (temp2 - temp1) * 6.0 * tempg;
        else if(tempg < 0.5) g = temp2;
        else if(tempg < 2.0 / 3.0) g = temp1 + (temp2 - temp1) * ((2.0 / 3.0) - tempg) * 6.0;
        else g = temp1;

        //Blue
        if(tempb < 1.0 / 6.0) b = temp1 + (temp2 - temp1) * 6.0 * tempb;
        else if(tempb < 0.5) b = temp2;
        else if(tempb < 2.0 / 3.0) b = temp1 + (temp2 - temp1) * ((2.0 / 3.0) - tempb) * 6.0;
        else b = temp1;
    }
    ColorRGB colorRGB;
    colorRGB.r = int(r * 255.0);
    colorRGB.g = int(g * 255.0);
    colorRGB.b = int(b * 255.0);
    return colorRGB;
}

ColorHSV RGBtoHSV(ColorRGB colorRGB)
{
    float r, g, b, h, s, v;
    r = colorRGB.r / 256.0;
    g = colorRGB.g / 256.0;
    b = colorRGB.b / 256.0;
    float maxColor = max(r, max(g, b));
    float minColor = min(r, min(g, b));
    v = maxColor;
    
    if(maxColor == 0)
    {
        s = 0;
    }
    else
    {
        s = (maxColor - minColor) / maxColor;
    }
    
    if(s == 0)
    {
        h = 0; //it doesn't matter what value it has
    }
    else
    {
        if(r == maxColor) h = (g - b) / (maxColor-minColor);
        else if(g == maxColor) h = 2.0 + (b - r) / (maxColor - minColor);
        else h = 4.0 + (r - g) / (maxColor - minColor);
        h /= 6.0; //to bring it to a number between 0 and 1
        if (h < 0) h++;
    }
    ColorHSV colorHSV;
    colorHSV.h = int(h * 255.0);
    colorHSV.s = int(s * 255.0);
    colorHSV.v = int(v * 255.0);
    return colorHSV;
}

ColorRGB HSVtoRGB(ColorHSV colorHSV)
{
    float r, g, b, h, s, v; //this function works with floats between 0 and 1
    h = colorHSV.h / 256.0;
    s = colorHSV.s / 256.0;
    v = colorHSV.v / 256.0;
    if(s == 0)
    {
        r = g = b = v;
    }
    else
    {
        float f, p, q, t;
        int i;
        h *= 6;
        i = int(floor(h));
        f = h - i;
        p = v * (1 - s);
        q = v * (1 - (s * f));
        t = v * (1 - (s * (1 - f)));
        switch(i)
        {
            case 0: r = v; g = t; b = p; break;
            case 1: r = q; g = v; b = p; break;
            case 2: r = p; g = v; b = t; break;
            case 3: r = p; g = q; b = v; break;
            case 4: r = t; g = p; b = v; break;
            case 5: r = v; g = p; b = q; break;
        }
    }
    ColorRGB colorRGB;
    colorRGB.r = int(r * 255.0);
    colorRGB.g = int(g * 255.0);
    colorRGB.b = int(b * 255.0);
    return colorRGB;
}
