// Uzebox stopwatch
// Currently re-using the tileset from IKD

#include <avr/io.h>
#include <avr/pgmspace.h>
//#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <uzebox.h>

#include "data/tileset.inc"

const char *numbers[10] = {n0, n1, n2, n3, n4, n5, n6, n7, n8, n9};

int main()
{
    SetSpritesTileTable(tileset);
    SetTileTable(tileset);
    ClearVram();
    while (1)
    {
        Print(8,2,PSTR("UZEBOX STOPWATCH"));

        // 1/10ths second column
        Print(31,9,PSTR("0"));
        // Right seconds column
        DrawMap2(26, 5, (numbers[0]));
        // Left seconds column
        DrawMap2(21, 5, (numbers[0]));
        // Right minutes column
        DrawMap2(16, 5, (numbers[0]));
        // Left minutes column
        DrawMap2(11, 5, (numbers[0]));
        // Right hours column
        DrawMap2(6, 5, (numbers[0]));
        // Left hours column
        DrawMap2(1, 5, (numbers[0]));

    }
}
