#include "twoplayer.h"

int twoplayerending(int x , int y)
{//x�� 1p�� �¾Ҵ��� ���� , y�� 2p�� �¾Ҵ��� ����
	//�տ��� ���������� �̰�ٰ� �Ѵ�. �� �����ް�
	char ch;
	system("cls");//ȭ���� Ŭ�����Ű��
	setColor(color2Wall);
	if (x == 0 && y == 1)
	{
		gotoxy(49, 17);
		printf("�ƢƢƢƢƢƢƢƢ�");
		gotoxy(49, 18);
		printf("��1player win!! ��");
		gotoxy(49, 19);
		printf("�ƢƢƢƢƢƢƢƢ�");
	}
	if (x == 1 && y == 1)
	{
		gotoxy(47, 17);
		printf("�ƢƢƢƢƢƢƢƢƢƢ�");
		gotoxy(47, 18);
		printf("�� draw!! good game ��");
		gotoxy(47, 19);
		printf("�ƢƢƢƢƢƢƢƢƢƢ�");
	}
	if (x == 1 && y == 0)
	{
		gotoxy(49, 17);
		printf("�ƢƢƢƢƢƢƢƢ�");
		gotoxy(49, 18);
		printf("��2player win!! ��");
		gotoxy(49, 19);
		printf("�ƢƢƢƢƢƢƢƢ�");
	}
	//�� ������ ȭ�鿡 ũ�� ǥ���Ѵ�.
	gotoxy(48, 20);
	printf("������ ��� �Ͻðڽ��ϱ�?(Y/N):");	
	while (1)
	{
		ch = _getch();
		if (ch == 'y' || ch == 'Y')
		{
			return 0;//���⸦ �Ѵ�.
		}
		if (ch == 'n' || ch == 'N')
		{
			return 1;//���� ȭ������ ���ư���
		}
	}
}