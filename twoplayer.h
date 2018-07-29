#pragma once
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <conio.h>

#define cmdsize(x,y) system("mode con: cols="#x" lines="#y);
#define ColorInit() GetStdHandle(STD_OUTPUT_HANDLE)
#define setColor(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , x)
#define clrscr() system("cls")
//������ define�մϴ�
#ifndef up
#define up 72
#define left 75
#define down 80
#define right 77
#endif
//�ʿ� ��� ������ --���� ���� ������ ��� ���� head1,head2�� trap������ ���� ��.
#ifndef empty
#define empty 0 //�� ĭ
#endif
#ifndef head1 //1p 2p�� �Ӹ���ġ
#define head1 -21
#endif
#ifndef head2
#define head2 -22
#endif
#ifndef wall
#define wall -24//��
#endif
//���� ũ�⸦ �����մϴ�
#ifndef sizelr2p
#define sizelr2p 42 //���� �¿� ����
#endif
#ifndef sizeud2p
#define sizeud2p 20 //���� ���Ʒ� ����
#endif
#ifndef trap
#define trap -25
#endif
#define absolute(x) (x)>0?(x):(-1) * (x)
#define esc 27
#ifndef colorCC
typedef enum color {
	black, blue, green, sky, red, violet, yellow, ivory, gray, dblue, rime, aqua, bloody, \
	lviolet, lyellow, white
} color;
#define colorCC
#endif

//����ڰ� �� �� �ְ� ����� ���,��

extern  char ch2Wall[]; //�� ���
extern  char ch1HeadLeft[];
extern  char ch2HeadLeft[];
extern  char ch1HeadDown[];
extern  char ch2HeadDown[];
extern  char ch1HeadUp[];
extern  char ch2HeadUp[];
extern  char ch1HeadRight[];
extern  char ch2HeadRight[]; //�Ӹ����
extern  char ch1Body[];
extern  char ch2Body[]; //�� ���
extern  char ch2Empty[]; //��ĭ�� ���
extern char ch2Trap[]; //������ ���
extern  color color2Wall; //���� ��
extern  color color1Head; //�Ӹ��� ��
extern  color color2Head;
extern  color color1Body; //���� ��
extern  color color2Body;
extern  color color2Empty; //��ĭ�� ��. Ȥ�� �������� �ٲ� ��츦 ����ؼ� ���� ������.
extern  color color2Trap;
extern int map2p[sizeud2p][sizelr2p]; //���� ũ��.

extern int direction1; //1p���� ���� �����ִ� ����.
extern int direction2; //2p���� ���� �����ִ� ����
extern int life2p; //���� ����
extern int hit1p; //1p �浹 ��������
extern int hit2p;
//�Լ� ����
void twoplayer(); //2p���ӿ����� �����Լ���.
void init2p(); //2p������ �ʱ�ȭ�Ѵ�.

//--> ����

void TPM(int,int);
void ST();
void gotoxy();
//--> ����
void update2p(); //2p������ ������Ʈ�Ѵ�.
void checkCollision(int*, int*);//�浹ó���� �Ѵ�.
void mapupdate();
void print2pmap();
//--> ����
int twoplayerending(int x, int y);//������ ������ ���� �̰���� ȭ�鿡 �����ش�.
													 //�Ķ���ͷδ� ���� �浹�ߴ����� �־�����.