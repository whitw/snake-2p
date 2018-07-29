#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <stdarg.h>
//#include "Screen.h"

#ifndef _DEFINE_H
#define _DEFINE_H
#define sec 1000
#define ColorInit() GetStdHandle(STD_OUTPUT_HANDLE)
#define setColor(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , x)
#ifndef cmdsize
#define cmdsize(x,y) system("mode con: cols="#x" lines="#y)
#endif

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void gotoxy(int, int);
int wherex();
int wherey();
void setcursortype(CURSOR_TYPE);
#ifndef colorCC
typedef enum color {
	black, blue, green, sky, red, violet, yellow, ivory, gray, dblue, rime, aqua, bloody, \
	lviolet, lyellow, white
} color;
#define colorCC
#endif
#endif