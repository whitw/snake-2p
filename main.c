#include "stdio.h"
#include "windows.h"
#include "conio.h"
#include "twoplayer.h"
#include "print1p.h"
#include "Define.h"
#define setColor(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , x)//콘솔 글씨 색상 조절
#define ColorInit() GetStdHandle(STD_OUTPUT_HANDLE)
//typedef enum color {
//	black, blue, green, sky, red, violet, yellow, ivory, gray, dblue, rime, aqua, bloody, \
//	lviolet, lyellow, white
//} color;

void cursorposition(int x, int y);//커서 위치 변경 함수

void main()
{
	int x, y, h, check = 1, select = 0;
	char ccheck;
	h = 5;
	cmdsize(108, 35);
	ColorInit();
	while(1)
	{
		while (1)
		{
			system("cls");
			select = 0;
			setColor(green);
			x = 44, y = h;
			cursorposition(x, y);
			printf("#####################");
			y = h + 1;
			cursorposition(x, y);
			printf("# S N A K E G A M E #");
			y = h + 2;
			cursorposition(x, y);
			printf("#####################");
			setColor(white);
			y = h + 12;
			cursorposition(x, y);
			printf("* 1P");
			y = h + 13;
			cursorposition(x, y);
			printf("* 2P");
			printf("\n");
			if (check == 1)
			{
				y = h + 12;
				cursorposition(x, y);
				printf("→");
			}
			if (check == 2)
			{
				y = h + 13;
				cursorposition(x, y);
				printf("→");
			}
			while (1)
			{
				if (_kbhit())
				{
				ccheck = _getch();
					if (_kbhit())
					{
						ccheck = _getch();
						if (ccheck == 72)
						{
							check = 1;
							break;
						}
						if (ccheck == 80)
						{
							check = 2;
							break;
						}
					}
					if (ccheck == 27)
						return;
				if (ccheck == 13)
				{
					if (check != 0)
						select = check;
				}
				break;
			}
			//up 72 left 75 right 77 down 80
		}
		if (select == 1)
		{
			system("cls");
			oneplayer();
			break;
		}
		if (select == 2)
		{
			system("cls");
			twoplayer();
			break;
		}
	}
}
	system("cls");
	system("pause");
}

void cursorposition(int x, int y)//커서 위치 변경 함수
{
	COORD a = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);

}