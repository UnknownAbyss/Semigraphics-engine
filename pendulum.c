#include <stdio.h>
#include <stdlib.h>
#include "gstructs.h"
#include "gfuncs.h"

#define WIDTH 50
#define HEIGHT 30

Window screen;
Layer ball;
Timer clk;

int main(int argc, char const *argv[])
{
    screen = create_window(WIDTH, HEIGHT);
    ball = create_layer(5, 5, false);
    ball.posx = 10;
    ball.posy = 10;
    fill(&ball, 'X');
    clk = create_timer(5);

    while (true)
    {
        tick(&clk);
        border(&screen, 'O');
        blit(&screen, ball);
        render(screen);
    }
    return 0;
}
