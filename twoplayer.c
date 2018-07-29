#include "twoplayer.h"
char ch2Wall[3] = "♠";
char ch1HeadLeft[3] = "◀"; //1p가 왼쪽을 볼 때의 얼굴모양
char ch2HeadLeft[3] = "◀"; //2p가 왼쪽을 볼 때의 얼굴모양
char ch1HeadDown[3] = "▼";
char ch2HeadDown[3] = "▼";
char ch1HeadUp[3] = "▲";
 char ch2HeadUp[3] = "▲";
 char ch1HeadRight[3] = "▶";
 char ch2HeadRight[3] = "▶"; //머리모양
 char ch1Body[3] = "■"; 
 char ch2Body[3] = "■"; //몸 모양
 char ch2Empty[3] = "▒"; //빈칸의 모양
 char ch2Trap[3] = "※"; //함정의 모양
 color color2Wall = white; //벽의 색
 color color1Head = green; //머리의 색
 color color2Head = red;
 color color1Body = green; //몸의 색
 color color2Body = red;
 color color2Empty = ivory; //빈칸의 색. 혹시 디자인이 바뀔 경우를 대비해서 색을 지정함.
 color color2Trap = bloody;

time_t last2Update = 0;//마지막으로 뱀이 이동한 시간
int time2Update = 200; //업데이트할 주기(ms)

time_t last2Sizeup = 0;//마지막으로 크기가 커진 시간
int time2Sizeup = 800;//크기가 커지는 주기(ms)

time_t last2Trap = 0;//마지막으로 트랩이 생긴 시간
int time2Trap = 10000; //트랩이 생기는 주기(ms)


int map2p[sizeud2p][sizelr2p] = { empty, }; //맵의 크기.
int direction1 = up; //꼴로 쓰면 방향을 나타낸다.
int direction2 = down;
int life2p = 10; //뱀의 길이

int hit1p = 0; //1p 충돌 전역변수
int hit2p = 0;

/**************************************************************************/

void twoplayer()
{
	char ch; //키보드 입력을 받기 위한 지역변수
	srand((unsigned)time(NULL));
	init2p();														//2p게임을 초기화한다. 위치를 잡고 뱀 초반 길이를 정하는 등의 일을 함.
	while (1)
	{
		//키를 받는다.
		if (_kbhit())
		{
			ch = _getch();
			if (_kbhit())
			{
				ch = _getch();
				if((direction2 == up && ch == down) || (direction2 == left && ch == right) || (direction2 == right && ch == left) || (direction2 == down && ch ==up))
				{ }
				else if (ch == up || ch == down || ch == left || ch == right)
					direction2 = ch;
			}
			else
			{
				switch (ch)
				{
				case 'w':
				case 'W':
					if(direction1 != down)
					direction1 = up;
					break;
				case 'a':
				case 'A':
					if(direction1 != right)
					direction1 = left;
					break;
				case 's':
				case 'S':
					if(direction1 != up)
					direction1 = down;
					break;
				case 'd':
				case 'D':
					if(direction1 != left)
					direction1 = right;
					break;
				case esc:
					system("cls");
					gotoxy(54, 15);
					setColor(ivory);
					printf("일시 정지");
					if (_getch())
					{
						TPM(sizelr2p,sizeud2p);
						break;
					}
				}
			}
		}
		//충돌처리-이동
		if (clock() - last2Update > time2Update)
		{
			checkCollision(&hit1p, &hit2p);
			if (hit1p != 0 || hit2p != 0) //둘중 하나라도 맞았다면
			{
				print2pmap();
				Sleep(3000);
				if (twoplayerending(hit1p, hit2p) == 0)
				{
					init2p();
					continue;
				}
				else return;
			}
			mapupdate();
			print2pmap();
			last2Update = clock();
			if (time2Update > 70)
				time2Update--;
		}

		if (clock() - last2Trap > time2Trap)
		{
			int rand_x;
			int rand_y;
			do
			{
				rand_x = rand() % sizelr2p;
				rand_y = rand() % sizeud2p;
			} while (map2p[rand_y][rand_x] != empty);
			map2p[rand_y][rand_x] = trap;
			last2Trap = clock();
		}

		if (clock() - last2Sizeup > time2Sizeup)
		{
			life2p++;
			last2Sizeup = clock();
		}
	}
}

/*****************************************************************/

void init2p()//게임초기화를 합니다.
{
	for (int i = 0; i < sizeud2p; i++)
	{
		for (int j = 0; j < sizelr2p; j++)
		{
			map2p[i][j] = empty;
		}
	}
	map2p[sizeud2p >> 1][sizelr2p / 3] = head1;
	map2p[sizeud2p >> 1][sizelr2p * 2 / 3] = head2;
	direction1 = up;
	direction2 = down;
	ST();
	TPM(sizelr2p , sizeud2p);
	print2pmap();
	last2Update = clock();
	last2Sizeup = clock();
	last2Trap = clock();
	life2p = 10;
	hit1p = 0;
	hit2p = 0;
	time2Update = 200;
	return;
}
