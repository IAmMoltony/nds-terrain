#include <draw.h>

void fillRect(int x, int y, int w, int h, int color)
{
    --w;
    --h;
    glBoxFilled(x, y, x + w, y + h, color);
}