#include "twoplayer.h"

int twoplayerending(int x , int y)
{//x는 1p가 맞았는지 여부 , y는 2p가 맞았는지 여부
	//앞에서 누구누구가 이겼다고 한다. 그 값을받고
	char ch;
	system("cls");//화면을 클리어시키고
	setColor(color2Wall);
	if (x == 0 && y == 1)
	{
		gotoxy(49, 17);
		printf("▒▒▒▒▒▒▒▒▒");
		gotoxy(49, 18);
		printf("▒1player win!! ▒");
		gotoxy(49, 19);
		printf("▒▒▒▒▒▒▒▒▒");
	}
	if (x == 1 && y == 1)
	{
		gotoxy(47, 17);
		printf("▒▒▒▒▒▒▒▒▒▒▒");
		gotoxy(47, 18);
		printf("▒ draw!! good game ▒");
		gotoxy(47, 19);
		printf("▒▒▒▒▒▒▒▒▒▒▒");
	}
	if (x == 1 && y == 0)
	{
		gotoxy(49, 17);
		printf("▒▒▒▒▒▒▒▒▒");
		gotoxy(49, 18);
		printf("▒2player win!! ▒");
		gotoxy(49, 19);
		printf("▒▒▒▒▒▒▒▒▒");
	}
	//그 누구를 화면에 크게 표시한다.
	gotoxy(48, 20);
	printf("게임을 계속 하시겠습니까?(Y/N):");	
	while (1)
	{
		ch = _getch();
		if (ch == 'y' || ch == 'Y')
		{
			return 0;//재경기를 한다.
		}
		if (ch == 'n' || ch == 'N')
		{
			return 1;//메인 화면으로 돌아간다
		}
	}
}