#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "pattern.h"
#include "config.h"

int cells[WIDTH][HEIGHT];
int speed = 1;
int generation = 0;

void draw_cells()
{
    char canvas[WIDTH*17+2][HEIGHT];
    for (int y = 0; y < WIDTH; y++)
    {
        char row[WIDTH*17+2];
        for (int x = 0; x < HEIGHT; x++)
        {
            if (cells[x][y] == 1)
            {
                strcpy(row + x*17, ALIVE);
            } else if (cells[x][y] == 0)
            {
                strcpy(row + x*17, DEAD);
            }
        }
        printf("%s\n", row);
    }
}

int *get_neighbor_cells(int x, int y)
{
    int *neighbor_cells = malloc(8 * sizeof(int));

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT)
        {
            neighbor_cells[i] = cells[nx][ny];
        }
        else
        {
            neighbor_cells[i] = 0;
        }
    }

    return neighbor_cells;
}

void update_cells()
{
    int new_cells[WIDTH][HEIGHT];

    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            int *neighbor_cells = get_neighbor_cells(x, y);
            int alive_count = 0;

            // Use a constant or a variable to store the number of neighbors
            const int num_neighbors = 8;

            for (int i = 0; i < num_neighbors; i++)
            {
                alive_count += neighbor_cells[i];
            }

            free(neighbor_cells);

            if (cells[x][y] == 1) // cell is alive
            {
                if (alive_count == 2 || alive_count == 3)
                {
                    new_cells[x][y] = 1;
                }
                else
                {
                    new_cells[x][y] = 0;
                }
            }
            else // cell is dead
            {
                if (alive_count == 3)
                {
                    new_cells[x][y] = 1;
                }
                else
                {
                    new_cells[x][y] = 0;
                }
            }
        }
    }

    memcpy(cells, new_cells, sizeof(cells));
}


int main()
{

    clear();
    printf("\033[?25l"); // hide cursor

    /*
    Random,
    Glider,
    LightweightSpaceship,
    Pulsar,
    GosperGliderGun,
    Blinker,
    Toad,
    Beacon,
    Pentadecathlon,
    Diamond 
    */
    init_cells(Beacon);

    while (1)
    {
        printf("\033[H"); // move cursor to the top-left corner

        if (_kbhit())
        {
            char key = _getch();
            if (key == 'q')
            {
                break;
            }
            if (key == 'l')
            {
                speed -= 10;
                if (speed <= 0)
                {
                    speed = 1;
                }
            }
            if (key == 'k') speed += 10;
        }
        
        draw_cells();
        update_cells();

        printf("\033[1;31mFASTER\033[0m - l\n");
        printf("\033[1;32mSLOWER\033[0m - k\n");
        printf("\033[1;34mWAIT TIME:\033[0m %d\n", speed);
        printf("\033[1;35mGENERATION:\033[0m %d\n", generation);

        generation ++;

        Sleep(speed);
    }

    clear();
    printf("\033[?25h"); // show cursor
    return 0;
}
