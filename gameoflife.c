#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define clear() printf("\e[1;1H\e[2J")
#define GREY "\x1b[48;5;248m  \x1b[0m"
#define GREEN "\x1b[48;5;154m  \x1b[0m"
#define WIDTH 40
#define HEIGHT 40

int cells[WIDTH][HEIGHT];
int speed = 1;
int generation = 0;

typedef enum
{
    Random,
    Glider,
    LightweightSpaceship,
    Pulsar,
    GosperGliderGun
} StartPattern;

void init_cells(StartPattern pattern)
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            cells[x][y] = 0;
        }
    }
    // thanks gpt 4 //
    switch (pattern)
    {
        case Random:
            srand(time(NULL));
            for (int x = 0; x < WIDTH; x++)
            {
                for (int y = 0; y < HEIGHT; y++)
                {
                    cells[x][y] = rand() % 2;
                }
            }
            break;
        case Glider:
            cells[1][0] = 1;
            cells[2][1] = 1;
            cells[0][2] = 1;
            cells[1][2] = 1;
            cells[2][2] = 1;
            break;
        case LightweightSpaceship:
            cells[1][0] = 1;
            cells[4][0] = 1;
            cells[0][1] = 1;
            cells[0][2] = 1;
            cells[4][2] = 1;
            cells[0][3] = 1;
            cells[1][4] = 1;
            cells[2][4] = 1;
            cells[3][4] = 1;
            cells[4][4] = 1;
            break;
        case Pulsar:
            for (int i = 4; i < 7; i++)
            {
                cells[i][2] = 1;
                cells[i + 6][2] = 1;
                cells[i][7] = 1;
                cells[i + 6][7] = 1;
                cells[i][9] = 1;
                cells[i + 6][9] = 1;
                cells[i][14] = 1;
                cells[i + 6][14] = 1;

                cells[2][i] = 1;
                cells[2][i + 6] = 1;
                cells[7][i] = 1;
                cells[7][i + 6] = 1;
                cells[9][i] = 1;
                cells[9][i + 6] = 1;
                cells[14][i] = 1;
                cells[14][i + 6] = 1;
            }
            break;
        case GosperGliderGun:
            cells[1][5] = 1;
            cells[1][6] = 1;
            cells[2][5] = 1;
            cells[2][6] = 1;
            cells[11][5] = 1;
            cells[11][6] = 1;
            cells[11][7] = 1;
            cells[12][4] = 1;
            cells[12][8] = 1;
            cells[13][3] = 1;
            cells[13][9] = 1;
            cells[14][3] = 1;
            cells[14][9] = 1;
            cells[15][6] = 1;
            cells[16][4] = 1;
            cells[16][8] = 1;
            cells[17][5] = 1;
            cells[17][6] = 1;
            cells[17][7] = 1;
            cells[18][6] = 1;
            cells[21][3] = 1;
            cells[21][4] = 1;
            cells[21][5] = 1;
            cells[22][3] = 1;
            cells[22][4] = 1;
            cells[22][5] = 1;
            cells[23][2] = 1;
            cells[23][6] = 1;
            cells[25][1] = 1;
            cells[25][2] = 1;
            cells[25][6] = 1;
            cells[25][7] = 1;
            cells[35][3] = 1;
            cells[35][4] = 1;
            cells[36][3] = 1;
            cells[36][4] = 1;
            break;
    }
    // thanks gpt 4 //
}

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
                strcpy(row + x*17, GREEN);
            } else if (cells[x][y] == 0)
            {
                strcpy(row + x*17, GREY);
            }
        }
        printf("%s\n", row);
        //row[WIDTH*17+2] = '\n';
        //strcpy(canvas + y*(WIDTH*17+2), row);
    }
    //printf("%s", canvas);
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

    /*
    Random,
    Glider,
    LightweightSpaceship,
    Pulsar,
    GosperGliderGun
    */

    init_cells(GosperGliderGun);

    while (1)
    {
        printf("\033[H");

        if (_kbhit())
        {
            char key = _getch();
            if (key == 'q') break;
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

        printf("FASTER - l\nSLOWER - k");
        printf("\nSPEED: %d", speed);
        printf("\nGENERATION: %d", generation);

        generation ++;

        Sleep(speed);
    }

    return 0;
}
