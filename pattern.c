#include "pattern.h"

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
        case Blinker:
            cells[9][8] = 1;
            cells[10][8] = 1;
            cells[11][8] = 1;
            break;
        case Toad:
            cells[8][8] = 1;
            cells[9][8] = 1;
            cells[10][8] = 1;
            cells[9][9] = 1;
            cells[10][9] = 1;
            cells[11][9] = 1;
            break;
        case Beacon:
            cells[8][8] = 1;
            cells[9][8] = 1;
            cells[8][9] = 1;
            cells[11][10] = 1;
            cells[10][11] = 1;
            cells[11][11] = 1;
            break;
        case Pentadecathlon:
            cells[9][7] = 1;
            cells[10][7] = 1;
            cells[9][8] = 1;
            cells[10][8] = 1;
            cells[8][9] = 1;
            cells[11][9] = 1;
            cells[9][10] = 1;
            cells[10][10] = 1;
            cells[9][11] = 1;
            cells[10][11] = 1;
            cells[8][12] = 1;
            cells[11][12] = 1;
            cells[9][13] = 1;
            cells[10][13] = 1;
            break;
    case Diamond:
        cells[9][8] = 1;
        cells[8][9] = 1;
        cells[10][9] = 1;
        cells[7][10] = 1;
        cells[11][10] = 1;
        cells[8][11] = 1;
        cells[10][11] = 1;
        cells[9][12] = 1;
        break;
    }
    // thanks gpt 4 //
}