#ifndef GSTRUCTS
#define GSTRUCTS

#include <stdbool.h>

typedef struct Window
{
    int width;
    int height;
    char** grid;
} Window;

typedef struct Layer
{
    int width;
    int height;
    int posx;
    int posy;
    char** grid;
    bool alpha;
} Layer;

typedef struct Timer
{
    int fps;
    long long prev;
} Timer;

#endif