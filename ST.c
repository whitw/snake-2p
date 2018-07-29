#include <stdlib.h>
#include "twoplayer.h"

void ST()
{
	system("cls");
	gotoxy(42, 7);
	printf("1player            2player");

	gotoxy(42, 18);
	printf("Control            Control");

	gotoxy(46, 21);
	printf("W");
	gotoxy(44, 23);
	printf("A S D");

	gotoxy(64, 21);
	printf("↑");
	gotoxy(61, 23);
	printf("← ↓ →");

	setColor(color1Head);
	gotoxy(38, 9);
	printf("■■■■■");
	gotoxy(38, 10);
	printf("        ■");
	gotoxy(38, 11);
	printf("■■■  ■");
	gotoxy(38, 12);
	printf("■  ▼  ■");
	gotoxy(38, 13);
	printf("■      ■");
	gotoxy(38, 14);
	printf("■■■■■");

	setColor(color2Head);
	gotoxy(61, 9);
	printf("■■■■■");
	gotoxy(61, 10);
	printf("        ■");
	gotoxy(61, 11);
	printf("■■■  ■");
	gotoxy(61, 12);
	printf("■  ▼  ■");
	gotoxy(61, 13);
	printf("■      ■");
	gotoxy(61, 14);
	printf("■■■■■");

	setColor(color2Wall);
	gotoxy(50, 26);
	printf("Game  Rule");
	gotoxy(27, 27);
	printf("1. 배의 머리가 벽이나 다른 뱀의 몸통에 닿으면 패배합니다.");
	gotoxy(27, 28);
	printf("2. 뱀의 머리가 ※에 닿으면 패배합니다.");


	gotoxy(48, 31);
	printf("Are You Ready?");
	gotoxy(44, 33);
	printf("아무 키나 눌러주세요");

	_getch();
	system("cls");
}