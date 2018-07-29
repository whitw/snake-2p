#include "twoplayer.h"

void checkCollision(int* hit1p, int* hit2p)
{
//충돌하는지 체크한다.
	for (int i = 0; i < sizeud2p;i++)
	{
		for (int j = 0; j < sizelr2p; j++)
		{
			if(map2p[i][j] ==  head1)
			switch (direction1)
			{
			case up:
				if (i == 0 || map2p[i - 1][j] > 0 ||map2p[i - 1][j] == head2 || map2p[i - 1][j] == trap)//맵 위끝에 있거나 1p위에 장애물이 있으면. 머리끼리 박을 경우도 포함.
					*hit1p = 1;
				break;
			case left:
				if (j == 0 || map2p[i][j - 1] > 0 || map2p[i][j - 1] == head2 || map2p[i][j - 1] == trap)
					*hit1p = 1;
				break;
			case down:
				if (i == sizeud2p - 1 || map2p[i + 1][j] > 0 || map2p[i + 1][j] == head2 || map2p[i + 1][j] == trap)
					*hit1p = 1;
				break;
			case right:
				if (j == sizelr2p - 1 || map2p[i][j + 1] > 0 || map2p[i][j + 1] == head2 || map2p[i + 1][j] == trap)
					*hit1p = 1;
				break;
			}//switch
			if (map2p[i][j] == head2)
			{
				switch (direction2)
				{
				case up:
					if (i == 0 || map2p[i - 1][j] > 0 || map2p[i - 1][j] ==head1 || map2p[i - 1][j] == trap)//맵 위끝에 있거나 2p위에 장애물이 있으면
						*hit2p = 1;
					break;
				case left:
					if (j == 0 || map2p[i][j - 1] > 0 || map2p[i][j - 1] == head1 || map2p[i][j - 1] == head1)
						*hit2p = 1;
					break;
				case down:
					if (i == sizeud2p - 1 || map2p[i + 1][j] > 0 || map2p[i + 1][j] == head1 || map2p[i + 1][j] == trap)
						*hit2p = 1;
					break;
				case right:
					if (j == sizelr2p - 1 || map2p[i][j + 1] > 0 || map2p[i][j + 1] == head1 || map2p[i][j + 1] == trap)
						*hit2p = 1;
					break;
				}//switch
			}
		}
	}
}

void print2pmap()
{
	int h = 6;
	gotoxy(57 - sizelr2p, h);
	for (int i = 0; i < sizeud2p; i++)
	{
		for (int j = 0; j < sizelr2p; j++)
		{
			if (map2p[i][j] == empty)
			{
				if (rand() % 1000 == 0)
				{
					setColor(color2Empty);
					printf("%s", ch2Empty);
				}
				else
				{
					printf("  ");
				}
			}
			else switch (map2p[i][j])
			{
			case head1:
				setColor(color1Head);
				switch (direction1)
				{
				case up:
					printf("%s",ch1HeadUp);
					break;
				case left:
					printf("%s",ch1HeadLeft);
					break;
				case down:
					printf("%s",ch1HeadDown);
					break;
				case right:
					printf("%s",ch1HeadRight);
					break;
				}
				break;
			case head2:
				setColor(color2Head);
				switch (direction2)
				{
				case up:
					printf("%s",ch2HeadUp);
					break;
				case left:
					printf("%s",ch2HeadLeft);
					break;
				case down:
					printf("%s",ch2HeadDown);
					break;
				case right:
					printf("%s",ch2HeadRight);
					break;
				}
				break;
			case trap:
				setColor(color2Trap);
				printf("%s", ch2Trap);
				break;
			default:
				if (map2p[i][j] > 100000)
				{
					setColor(color2Body);
					printf("%s", ch2Body);
				}
				else
				{
					setColor(color1Body);
					printf("%s", ch1Body);
				}
				break;
			}
		}
		h++;
		gotoxy(57-sizelr2p, h);
	}
	return;
}

void mapupdate()
{
	for (int i = 0; i < sizeud2p; i++)
	{
		for (int j = 0; j < sizelr2p; j++)
		{
			if (map2p[i][j] > 0) //몸통처리
			{
				map2p[i][j]--;
				if (map2p[i][j] == 100000) //2p의 몸통은 100000부터 시작한다.
					map2p[i][j] = empty;
			}//if 몸통
		}//for 내부
	}//for외부
	struct pos
	{
		int x;
		int y;
	}pos1,pos2;
	for (int i = 0; i < sizeud2p; i++)
	{
		for (int j = 0; j < sizelr2p; j++)
		{
			if (map2p[i][j] == head1)
			{
				pos1.y = i;
				pos1.x = j;
				map2p[i][j] = life2p;
			}
			if (map2p[i][j] == head2)
			{
				pos2.y = i;
				pos2.x = j;
				map2p[i][j] = life2p + 100000;
			}
		}
	}
	switch (direction1)
	{
	case up:
		map2p[pos1.y - 1][pos1.x] = head1;
		break;
	case left:
		map2p[pos1.y][pos1.x-1] = head1;
		break;
	case right:
		map2p[pos1.y][pos1.x+1] = head1;
		break;
	case down:
		map2p[pos1.y + 1][pos1.x] = head1;
		break;
	}
	switch (direction2)
	{
		map2p[pos2.y][pos2.x] = life2p+100000;
	case up:
		if (map2p[pos2.y - 1][pos2.x] == head1)
		{
			hit1p = 1;
			hit2p = 1;
			return;
		}
		map2p[pos2.y - 1][pos2.x] = head2;
		break;
	case left:
		if (map2p[pos2.y][pos2.x - 1] == head1)
	{
		hit1p = 1;
		hit2p = 1;
		return;
	}
		map2p[pos2.y][pos2.x - 1] = head2;
		break;
	case right:
		if (map2p[pos2.y][pos2.x + 1] == head1)
		{
			hit1p = 1;
			hit2p = 1;
			return;
		}
		map2p[pos2.y][pos2.x + 1] = head2;
		break;
	case down:
		if (map2p[pos2.y + 1][pos2.x] == head1)
		{
			hit1p = 1;
			hit2p = 1;
			return;
		}
		map2p[pos2.y + 1][pos2.x] = head2;
		break;
	}
}//업데이트 끝