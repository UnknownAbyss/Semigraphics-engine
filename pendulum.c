#include <stdio.h>
#include <stdlib.h>
#include "gstructs.h"
#include "gfuncs.h"

#define WIDTH 50
#define HEIGHT 30

// Global declarations
Window screen;
Layer ball;
Timer clk;

int main(int argc, char const *argv[])
{
    // Define screen
    screen = create_window(WIDTH, HEIGHT);

    // Create ball
    ball = create_layer(5, 5, false);

    // draw circle in ball layer
    fill(&ball, 'X');
    ball.grid[0][0] = ' ';
    ball.grid[0][4] = ' ';
    ball.grid[4][0] = ' ';
    ball.grid[4][4] = ' ';

    // Create Timer with fps
    clk = create_timer(10);

    while (true)
    {
        // Timer synchronization
        tick(&clk);


        fill(&screen, '.');
        border(&screen, 'O');
        blit(&screen, ball);
        render(screen);
    }
    return 0;
}
