#ifndef GFUNCS
#define GFUNCS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include "./gstructs.h"

Window create_window(int width, int height)
{
    Window win = {width, height};
    win.grid = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++)
    {
        win.grid[i] = (char *)malloc(width * sizeof(char));
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            win.grid[i][j] = ' ';
        }
    }
    return win;
}

Layer create_layer(int width, int height, bool alpha)
{
    Layer layer = {width, height, 0, 0};
    layer.grid = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++)
    {
        layer.grid[i] = (char *)malloc(width * sizeof(char));
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            layer.grid[i][j] = ' ';
        }
    }

    return layer;
}

Timer create_timer(int fps)
{
    Timer t;
    t.fps = fps;
    t.prev = 0;

    return t;
}

void blit(Window* win, Layer layer)
{
    for (int i = layer.posy; i < layer.posy + layer.height; i++)
    {
        for (int j = layer.posx; j < layer.posx + layer.width; j++)
        {
            char c = layer.grid[i-layer.posy][j-layer.posx];
            win->grid[i][j] = (layer.alpha && c==' ')?win->grid[i][j]:c;
        }
    }
}

void render(Window win)
{
    system("clear");
    for (int i = 0; i < win.height; i++)
    {
        for (int j = 0; j < win.width; j++)
        {
            printf("%c", win.grid[i][j]);
        }
        printf("\n");
    }
}

long long millis_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (((long long)tv.tv_sec) * 1000) + (tv.tv_usec / 1000);
}

void tick(Timer *t)
{
    long long p = t->prev;
    while ((millis_time() - p) < (1000 / t->fps))
    {
    }
    t->prev = millis_time();
}

void fill(Window *win, char c)
{
    for (int i = 0; i < win->height; i++)
    {
        for (int j = 0; j < win->width; j++)
        {
            win->grid[i][j] = c;
        }
    }
}

void fill(Layer *layer, char c)
{
    for (int i = 0; i < layer->height; i++)
    {
        for (int j = 0; j < layer->width; j++)
        {
            layer->grid[i][j] = c;
        }
    }
}

void border(Window *win, char c)
{
    for (int i = 0; i < win->height; i++)
    {
        for (int j = 0; j < win->width; j++)
        {
            win->grid[i][j] = (i == 0 || i == win->height - 1 || j == 0 || j == win->width - 1) ? c : ' ';
        }
    }
}

#endif