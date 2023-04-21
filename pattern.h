#ifndef PATTERN_H
#define PATTERN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"

extern int cells[WIDTH][HEIGHT];

typedef enum
{
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
} StartPattern;

void init_cells(StartPattern pattern);

#endif // PATTERN_H