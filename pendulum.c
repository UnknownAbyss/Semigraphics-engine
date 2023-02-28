#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gstructs.h"
#include "gfuncs.h"

#define WIDTH 51
#define HEIGHT 35
#define ROD1 14
#define ROD2 15

// Global declarations
Window screen;
Layer box;
Timer clk;

int main(int argc, char const *argv[])
{
    // Define screen
    screen = create_window(WIDTH, HEIGHT);

    // Create box
    box = create_layer(5, 5, false);
    box.posx = 23;
    box.posy = 23;

    // draw circle in box layer
    border(&box, 'X');

    // Create Timer with fps
    clk = create_timer(20);

    // Physics declarations
    int x = WIDTH / 2;
    float g = 1;

    int y1 = 3;
    double alpha1 = 0.1;
    double angv1 = 0;
    int y2 = 15;
    double alpha2 = 0.1;
    double angv2 = 0;

    while (true)
    {
        // Timer synchronization
        tick(&clk);

        // Physics updates for pendulum
        double anga = g * cosf(alpha1) * ROD1;
        angv1 += anga * delta;
        alpha1 += angv1 * delta;

        anga = g * cosf(alpha2) * ROD2;
        angv2 += anga * delta;
        alpha2 += angv2 * delta;

        // Screen clear
        fill(&screen, ' ');
        border(&screen, 'O');

        // Put box on screen
        blit(&screen, box);

        // Draw rod
        for (int i = 1; i < ROD1 + 1; i++)
        {
            screen.grid[y1 + (int)(i * sinf(alpha1))][x + (int)(i * cosf(alpha1))] = '*';
        }

        for (int i = 1; i < ROD2 + 1; i++)
        {
            screen.grid[y2 + (int)(i * sinf(alpha2))][x + (int)(i * cosf(alpha2))] = '*';
        }

        // Display the screen
        render(screen);
    }
    return 0;
}
