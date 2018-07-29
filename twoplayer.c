#include "twoplayer.h"
char ch2Wall[3] = "��";
char ch1HeadLeft[3] = "��"; //1p�� ������ �� ���� �󱼸��
char ch2HeadLeft[3] = "��"; //2p�� ������ �� ���� �󱼸��
char ch1HeadDown[3] = "��";
char ch2HeadDown[3] = "��";
char ch1HeadUp[3] = "��";
 char ch2HeadUp[3] = "��";
 char ch1HeadRight[3] = "��";
 char ch2HeadRight[3] = "��"; //�Ӹ����
 char ch1Body[3] = "��"; 
 char ch2Body[3] = "��"; //�� ���
 char ch2Empty[3] = "��"; //��ĭ�� ���
 char ch2Trap[3] = "��"; //������ ���
 color color2Wall = white; //���� ��
 color color1Head = green; //�Ӹ��� ��
 color color2Head = red;
 color color1Body = green; //���� ��
 color color2Body = red;
 color color2Empty = ivory; //��ĭ�� ��. Ȥ�� �������� �ٲ� ��츦 ����ؼ� ���� ������.
 color color2Trap = bloody;

time_t last2Update = 0;//���������� ���� �̵��� �ð�
int time2Update = 200; //������Ʈ�� �ֱ�(ms)

time_t last2Sizeup = 0;//���������� ũ�Ⱑ Ŀ�� �ð�
int time2Sizeup = 800;//ũ�Ⱑ Ŀ���� �ֱ�(ms)

time_t last2Trap = 0;//���������� Ʈ���� ���� �ð�
int time2Trap = 10000; //Ʈ���� ����� �ֱ�(ms)


int map2p[sizeud2p][sizelr2p] = { empty, }; //���� ũ��.
int direction1 = up; //�÷� ���� ������ ��Ÿ����.
int direction2 = down;
int life2p = 10; //���� ����

int hit1p = 0; //1p �浹 ��������
int hit2p = 0;

/**************************************************************************/

void twoplayer()
{
	char ch; //Ű���� �Է��� �ޱ� ���� ��������
	srand((unsigned)time(NULL));
	init2p();														//2p������ �ʱ�ȭ�Ѵ�. ��ġ�� ��� �� �ʹ� ���̸� ���ϴ� ���� ���� ��.
	while (1)
	{
		//Ű�� �޴´�.
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
					printf("�Ͻ� ����");
					if (_getch())
					{
						TPM(sizelr2p,sizeud2p);
						break;
					}
				}
			}
		}
		//�浹ó��-�̵�
		if (clock() - last2Update > time2Update)
		{
			checkCollision(&hit1p, &hit2p);
			if (hit1p != 0 || hit2p != 0) //���� �ϳ��� �¾Ҵٸ�
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

void init2p()//�����ʱ�ȭ�� �մϴ�.
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
