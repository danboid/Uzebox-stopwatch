// Uzebox stopwatch

// By Dan MacDonald
//       2023

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdbool.h>
#include <stdlib.h>
#include <uzebox.h>

#include "data/tileset.inc"

const char *numbers[10] = {n0, n1, n2, n3, n4, n5, n6, n7, n8, n9};

// DrawDigits is a function to easily draw a double digit number between 00 and 99 using the large numbers.
// xoffset represents the first column to use for the first (10s) number of the pair.

void DrawDigits(int number, int xoffset);

void DrawDigits(int number, int xoffset) {
    // First we draw the units (rightmost) digit. It gets drawn at xoffset + 5 tiles
    DrawMap2((xoffset + 5), 5, (numbers[number % 10]));
    // Draw the tens (leftmost) digit or a zero
    DrawMap2(xoffset, 5, (numbers[number / 10 % 10]));
}

int main()
{
    SetSpritesTileTable(tileset);
    SetTileTable(tileset);
    ClearVram();
    while (1)
    {
        Print(8,2,PSTR("UZEBOX STOPWATCH"));

        // Print seconds
        DrawDigits(56,20);
        // Print minutes
        DrawDigits(34,10);
        // Print hours
        DrawDigits(12,0);

        // Print jiffys/ticks/thirds/frames (1/60th seconds)
        Print(30,9,PSTR("78"));
    }
}
