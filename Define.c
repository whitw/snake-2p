#include "Define.h"

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int wherex(void)
{
	CONSOLE_SCREEN_BUFFER_INFO scb;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &scb);
	return (scb.dwCursorPosition.X);
}
int wherey(void)
{
	CONSOLE_SCREEN_BUFFER_INFO scb;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &scb);
	return (scb.dwCursorPosition.Y);
}
void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO Curinfo;

	switch (c)
	{
	case NOCURSOR:
		Curinfo.dwSize = 1;
		Curinfo.bVisible = FALSE;
		break;
	case NORMALCURSOR:
		Curinfo.dwSize = 20;
		Curinfo.bVisible = TRUE;
		break;
	case SOLIDCURSOR:
		Curinfo.dwSize = 100;
		Curinfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Curinfo);
}