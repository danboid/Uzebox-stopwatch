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

int frames, seconds, minutes, hours, btnprev, btnheld = 0;

bool active = false;

// DrawDigits is a function to easily draw a double digit number between 00 and 99 using the large numbers.
// xoffset represents the first column to use for the first (10s) number of the pair.

void DrawDigits(int number, int xoffset);

void DrawDigits(int number, int xoffset) {
    // First we draw the units (rightmost) digit. It gets drawn at xoffset + 5 tiles
    DrawMap2((xoffset + 5), 6, (numbers[number % 10]));
    // Draw the tens (leftmost) digit or a zero
    DrawMap2(xoffset, 6, (numbers[number / 10 % 10]));
}

int main()
{
    SetSpritesTileTable(tileset);
    SetTileTable(tileset);
    ClearVram();
    while (1)
    {
        Print(8,2,PSTR("UZEBOX STOPWATCH"));
        Print(8,4,PSTR("BY DAN MACDONALD"));

        Print(5,14,PSTR("PUSH START TO START/STOP"));
        Print(7,16,PSTR("PUSH SELECT TO RESET"));

        btnheld = ReadJoypad(0);

        if (btnheld != btnprev) {
            if (btnheld & BTN_START) {
                active = !active;
            }
            if (btnheld & BTN_SELECT) {
                if (active == false) {
                    frames = 0;
                    seconds = 0;
                    minutes = 0;
                    hours = 0;
                }
            }
            btnprev = btnheld;
        }


        if (active) {
            frames++;
            if (frames >= 60) {
                seconds++;
                frames=0;
            }
            if (seconds >= 60) {
                minutes++;
                seconds=0;
            }
            if (minutes >= 60) {
                hours++;
                minutes=0;
            }
        }

        // Print seconds
        DrawDigits(seconds,22);
        // Print minutes
        DrawDigits(minutes,12);
        // Print hours
        DrawDigits(hours,2);

        // Print jiffys/ticks/thirds/frames (1/60th seconds)
        PrintInt(30,12,frames,true);
    }
}
