#include "Define.h"
#include "print1p.h"
#define cmdsize(x,y) system("mode con: cols="#x" lines="#y)
#define head -1
#define longitem -2
#define trap -3
#define shortitem -4
#define lucky -5
#define empty 0
#define length 25
#define height 25
#define up 72
#define left 75
#define down 80
#define right 77
#define start 1
#define game 2
#define score 3
#define sizeup 25
#define sizelength 25
const char wall[] = "□";
const color colorWall = white;
const char Head1[] = "▲";
const color colorHead1 = green;
const char Head2[] = "▼";
const color colorHead2 = green;
const char Head3[] = "◀";
const color colorHead3 = green;
const char Head4[] = "▶";
const color colorHead4 = green;
const char Body[] = "□";
const color colorBody = green;
const char Item[] = "★";//뱀의 길이 늘리기
const color colorItem = rime;
const char Minus[] = "◎";//뱀의 길이 줄이기
const color colorMinus = dblue;
const char Up[] = "◈";//점수높여주기 + 20000
const color colorUp = gray;
const char Die[] = "◆";//즉사
const color colorDie = bloody;
const char Empty[] = "  ";
const color colorEmpty = ivory;

const color colorscore = ivory;
int life = 3;
unsigned char direction = up;
int gamestat = start;
unsigned int scores = 0;
unsigned int scoreboard[10] = { 0,0,0,0,0,0,0,0,0,0 };

int map[sizeup][sizelength] = { empty, };
int rank = 10;
time_t lastUpdate = 0;
int UpdateTime = 50;//ms
time_t lastTrap = 0;
int trapTime = 5000;
time_t lastMinusTrap = 0;
int minusTrapTime = 50000;
time_t lastMinusItem = 0;
int minusItemTime = 19990;
time_t lastItem = 0;
int itemTime = 2000;
int head_y = sizeup >> 1;
int head_x = sizelength >> 1;
#define absolute(x) (x)>0? (x) : (-1*x)
void printmap();
void Init();
void update();
int check_collision();
void switchGameStat(int);

int oneplayer()
{
	cmdsize(108, 35);
	char ch = 0;
	Init();
	while (1)
	{
		switch (gamestat)
		{
		case start:
			if (_getch())
				switchGameStat(game);
			break;
		case game:
			while (1)
			{
				if (_kbhit())
				{
					ch = _getch();
					if (_kbhit())
					{
						direction = _getch();
					}
					else switch (ch)
					{
					case 'w':
					case 'W':
						direction = up;
						break;
					case 'a':
					case 'A':
						direction = left;
						break;
					case 's':
					case 'S':
						direction = down;
						break;
					case 'd':
					case 'D':
						direction = right;
						break;

					}
				}
				if (clock() - lastUpdate >= UpdateTime)
				{
					if (check_collision())
						break;
					update();
					lastUpdate = clock();
					if (UpdateTime > 100)
						UpdateTime--;
					printmap();
				}
				while (1)
				{
					if (rank == 0)
					{
						scoreboard[0] = scores;
						break;
					}
					if (rank >= 1)
					{
						if (scoreboard[rank - 1] < scores)
						{
							if (rank < 10)
								scoreboard[rank] = scoreboard[rank - 1];
							scoreboard[rank - 1] = scores;
							if (rank > 0)
								rank--;
							else
								scoreboard[rank - 1] = scores;
						}
						else if (rank < 10)
						{
							scoreboard[rank] = scores;
							break;
						}
						else break;
					}				
				}
			}
			gotoxy(0, 30);
			printf("GAME OVER");
			for (int i = 0; i < 9; i++)
			{
				if (rank == i)
					setColor(rime);
				else setColor(colorWall);
				gotoxy(80, 5 + 2 * i);
				printf("%d", scoreboard[i]);
			}
			Sleep(3000);
			switchGameStat(score);
			break;
		case score:
			ch = _getch();
			if (ch == 'Y' || ch == 'y')
			{
				switchGameStat(game);
			}
			if (ch == 'N' || ch == 'n')
			{
				gotoxy(30, 15);
				printf("Thank you for Playing\n\n");
				Sleep(3000);
				goto end;
			}
			break;

		}

	}
end:
	return 0;
}

void printmap()
{
	int tempy = 2;
	char ch = 0;
	setColor(colorscore);
	gotoxy(75, 30);
	printf("%010d", scores);
	for (int i = 0; i < 9; i++)
	{
		if (rank == i)
			setColor(rime);
		else setColor(colorWall);
		gotoxy(80, 5 + 2 * i);
		printf("%d", scoreboard[i]);
	}
	gotoxy(3, 2);
	setColor(colorWall);
	for (int i = 0; i < sizeup; i++)
	{
		for (int j = 0; j < sizelength; j++)
		{
			switch (map[i][j])
			{
			case head:
				switch (direction)
				{
				case up:
					setColor(colorHead1);
					printf("%s", Head1);
					break;
				case left:
					setColor(colorHead1);
					printf("%s", Head3);
					break;
				case down:
					setColor(colorHead1);
					printf("%s", Head2);
					break;
				case right:
					setColor(colorHead1);
					printf("%s", Head4);
					break;
				}
				break;
			case longitem:
				setColor(colorItem);
				printf("%s", Item);
				break;
			case trap:
				setColor(colorDie);
				printf("%s", Die);
				break;
			case empty:
				setColor(colorEmpty);
				printf("%s", Empty);
				break;
			case shortitem:
				setColor(colorMinus);
				printf("%s", Minus);
				break;
			case lucky:
				setColor(colorUp);
				printf("%s", Up);
				break;

			default:
				if (map[i][j] >= 0)
				{
					setColor(colorBody);
					printf("%s", Body);
				}
				else
				{
					setColor(colorDie);
					printf("%s", Die);

				}
				break;
			}
			setColor(ivory);
		}
		tempy++;
		gotoxy(3, tempy);
	}
}

void Init()
{
	srand((unsigned int)time(NULL));
	setcursortype(NOCURSOR);
	switchGameStat(game);
	rank = 10;
}

void update()
{
	int x = 0, y = 0;
	for (int i = 0; i < sizeup; i++)
	{
		for (int j = 0; j < sizelength; j++)
		{
			if (map[i][j] > 0)
				map[i][j]--;
			else if (map[i][j] == head)
				map[i][j] = life;
			if (map[i][j] < -8000)
			{
				map[i][j]++;
			}
		}
		map[head_y][head_x] = head;

	}
	if (clock() - lastTrap >= trapTime)//함정
	{
		do {
			x = rand() % sizeup;
			y = rand() % sizelength;

		} while (map[y][x] != 0);
		map[y][x] = trap;
		lastTrap = clock();
		map[y][x] = -10000;
	}
	for (int i = 0; i < sizeup; i++)
	{
		for (int j = 0; j < sizelength; j++)
		{
			if (map[i][j] == -9930)
				map[i][j] = 0;
		}
	}
	if (clock() - lastItem >= itemTime)//아이템
	{
		for (int i = 0; i < sizeup; i++)
		{
			for (int j = 0; j < sizelength; j++)
			{
				if (map[i][j] == longitem)
					return;
			}
		}
		do
		{
			x = rand() % sizeup;
			y = rand() % sizelength;

		} while (map[y][x] != 0);
		map[y][x] = longitem;
		lastItem = clock();

	}
	if (clock() - lastMinusItem >= minusItemTime)
	{
		do
		{
			x = rand() % sizeup;
			y = rand() % sizelength;

		} while (map[y][x] != 0);
		map[y][x] = shortitem;
		lastMinusItem = clock();

	}
	if (clock() - lastMinusTrap >= minusTrapTime)
	{
		do
		{
			x = rand() % sizeup;
			y = rand() % sizelength;

		} while (map[y][x] != 0);
		map[y][x] = lucky;
		lastMinusTrap = clock();
		minusTrapTime += 2000;
	}
}

int check_collision()
{
	scores += (300 - UpdateTime);
	switch (direction)
	{
	case up:
		if (head_y > 0)
			head_y--;
		break;
	case left:
		if (head_x > 0)
			head_x--;
		break;
	case down:
		if (head_y < sizeup)
			head_y++;
		break;
	case right:
		if (head_x < sizelength)
			head_x++;
		break;

	}
	if (head_x >= sizelength || head_y >= sizeup || head_x < 0 || head_y < 0 || (map[head_y][head_x] != empty && map[head_y][head_x] != longitem &&map[head_y][head_x] != shortitem&&map[head_y][head_x] != lucky))
		return 1;
	else if (map[head_y][head_x] == longitem)
	{
		life++;
		scores += 1000;
		for (int i = 0; i<sizeup; i++)
		{
			for (int j = 0; j < sizelength; j++)
			{
				if (map[i][j] > 0)
					map[i][j]++;
			}

		}
		return 0;
	}
	else if (map[head_y][head_x] == shortitem)
	{
		life -= 5;
		if(scores > 5000)
			scores -= 5000;
		else scores = 0;
		if (life < 3)
			life = 3;
		for (int i = 0; i < sizeup; i++)
		{
			for (int j = 0; j < sizelength; j++)
			{
				if (map[i][j] > 0)
				{
					map[i][j] -= 5;
					if (map[i][j] < 0)
						map[i][j] = 0;
				}
			}
		}
		return 0;
	}
	else if (map[head_y][head_x] == lucky)
	{
		scores += 20000;
		return 0;
	}
	else //빈칸 
		return 0;
}

void switchGameStat(int stat)
{
	setColor(ivory);
	system("cls");
	switch (stat)
	{
	case start:
		gamestat = start;
		gotoxy(27, 4);
		printf("▒▒▒▒▒▒▒▒▒▒▒▒");
		gotoxy(27, 5);
		printf("▒     SNAKE GAME     ▒");
		gotoxy(27, 6);
		printf("▒▒▒▒▒▒▒▒▒▒▒▒");
		break;
	case game:
		gamestat = game;
		direction = up;
		rank = 10;
		life = 3;
		UpdateTime = 300;
		trapTime = 5000;
		minusTrapTime = 50000;
		itemTime = 2000;
		minusItemTime = 19990;
		lastUpdate = clock();
		lastTrap = clock();
		lastMinusTrap = clock();
		lastItem = clock();
		lastMinusItem = clock();
		scores = 0;
		for (int i = 0; i < sizeup; i++)
			for (int j = 0; j < sizelength; j++)
				map[i][j] = empty;
		map[sizeup >> 1][sizelength >> 1] = head; //머리 위치 설정
		head_y = sizeup >> 1;
		head_x = sizelength >> 1;
		gotoxy(0, 0); //맵 테두리 그리기
		for (int i = 0; i < sizeup + 2; i++)
			printf("□");
		printf("\n");
		for (int j = 0; j < sizelength; j++)
		{
			printf("□");
			for (int i = 0; i < sizeup; i++)
				printf("  ");
			printf("□\n");
		}
		for (int i = 0; i < sizeup + 2; i++)
			printf("□");//맵 테두리 그리기 끝
		print1p();
		break;
	case score:
		gamestat = score;
		gotoxy(23, 20);
		printf("Do you want to Play it again?(press Y/N)");
		break;
	}
}




