#include "define.h"
#include "print1p.h"


void print1p()
{
	int i = 0;
	//Scoreboard �׸���


	gotoxy(70, 1);
	printf("�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�");
	gotoxy(70, 2);
	printf("��  ����������SCOREBORD���������� ��");
	for (i = 3; i < 25; i++)
	{
		gotoxy(70, i);
		printf("��                                ��");
		gotoxy(70, i + 1);
		printf("��                                ��");
		i++;
	}

	//���� Score â �׸���

	gotoxy(70, i);
	printf("�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�\n");
	gotoxy(70, i + 2);
	printf("�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�\n");
	for (i = 28; i < 33; i++)
	{
		gotoxy(70, i);
		printf("��                                ��");
	}
	gotoxy(70, i);
	printf("�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�");



	//���� ���
	gotoxy(75, 30);
	printf("SCORE:");



	//���� ��Ģ ����
	gotoxy(4, 28);
	printf("�Ѱ��� ��Ģ���ע�");
	gotoxy(4, 29);
	setColor(rime);
	printf("���� ������ ���̰� �þ�ϴ�,+1000��");
	gotoxy(4, 30);
	setColor(dblue);
	printf("���� ������ ���̰� �پ��ϴ�,-5000��");
	gotoxy(4, 31);
	setColor(bloody);
	printf("���� ������ �׾�~^^");
	gotoxy(4, 32);
	setColor(gray);
	printf("���� ������ +20000�� �Դϴ�");
	gotoxy(4, 33);
	setColor(white);
	printf("�ִ��� ���� ��Ƽ����!!");

	//Scoreboard ����

	gotoxy(73, 5);
	printf("1��: ");
	gotoxy(73, 7);
	printf("2��: ");
	gotoxy(73, 9);
	printf("3��: ");
	gotoxy(73, 11);
	printf("4��: ");
	gotoxy(73, 13);
	printf("5��: ");
	gotoxy(73, 15);
	printf("6��: ");
	gotoxy(73, 17);
	printf("7��: ");
	gotoxy(73, 19);
	printf("8��: ");
	gotoxy(73, 21);
	printf("9��: ");
	gotoxy(73, 24);
	printf("9�� ���ϴ� �й��ϼ���");
}