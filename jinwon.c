#include "define.h"
#include "print1p.h"


void print1p()
{
	int i = 0;
	//Scoreboard 그리기


	gotoxy(70, 1);
	printf("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩");
	gotoxy(70, 2);
	printf("▒  ∥∥∥∥∥SCOREBORD∥∥∥∥∥ ▒");
	for (i = 3; i < 25; i++)
	{
		gotoxy(70, i);
		printf("▒                                ▒");
		gotoxy(70, i + 1);
		printf("▥                                ▥");
		i++;
	}

	//현재 Score 창 그리기

	gotoxy(70, i);
	printf("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n");
	gotoxy(70, i + 2);
	printf("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n");
	for (i = 28; i < 33; i++)
	{
		gotoxy(70, i);
		printf("╋                                ╋");
	}
	gotoxy(70, i);
	printf("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩");



	//점수 출력
	gotoxy(75, 30);
	printf("SCORE:");



	//게임 규칙 사항
	gotoxy(4, 28);
	printf("☞게임 규칙사항☜");
	gotoxy(4, 29);
	setColor(rime);
	printf("★을 먹으면 길이가 늘어납니다,+1000점");
	gotoxy(4, 30);
	setColor(dblue);
	printf("◎을 먹으면 길이가 줄어듭니다,-5000점");
	gotoxy(4, 31);
	setColor(bloody);
	printf("◆을 먹으면 죽어~^^");
	gotoxy(4, 32);
	setColor(gray);
	printf("◈을 먹으면 +20000점 입니다");
	gotoxy(4, 33);
	setColor(white);
	printf("최대한 오래 버티세요!!");

	//Scoreboard 순위

	gotoxy(73, 5);
	printf("1등: ");
	gotoxy(73, 7);
	printf("2등: ");
	gotoxy(73, 9);
	printf("3등: ");
	gotoxy(73, 11);
	printf("4등: ");
	gotoxy(73, 13);
	printf("5등: ");
	gotoxy(73, 15);
	printf("6등: ");
	gotoxy(73, 17);
	printf("7등: ");
	gotoxy(73, 19);
	printf("8등: ");
	gotoxy(73, 21);
	printf("9등: ");
	gotoxy(73, 24);
	printf("9등 이하는 분발하세요");
}