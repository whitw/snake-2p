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
//방향을 define합니다
#ifndef up
#define up 72
#define left 75
#define down 80
#define right 77
#endif
//맵에 담길 정보들 --실제 값이 뭐던지 상관 없이 head1,head2나 trap등으로 쓰면 됨.
#ifndef empty
#define empty 0 //빈 칸
#endif
#ifndef head1 //1p 2p의 머리위치
#define head1 -21
#endif
#ifndef head2
#define head2 -22
#endif
#ifndef wall
#define wall -24//벽
#endif
//맵의 크기를 정의합니다
#ifndef sizelr2p
#define sizelr2p 42 //맵의 좌우 길이
#endif
#ifndef sizeud2p
#define sizeud2p 20 //맵의 위아래 길이
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

//사용자가 볼 수 있게 출력할 모양,색

extern  char ch2Wall[]; //벽 모양
extern  char ch1HeadLeft[];
extern  char ch2HeadLeft[];
extern  char ch1HeadDown[];
extern  char ch2HeadDown[];
extern  char ch1HeadUp[];
extern  char ch2HeadUp[];
extern  char ch1HeadRight[];
extern  char ch2HeadRight[]; //머리모양
extern  char ch1Body[];
extern  char ch2Body[]; //몸 모양
extern  char ch2Empty[]; //빈칸의 모양
extern char ch2Trap[]; //함정의 모양
extern  color color2Wall; //벽의 색
extern  color color1Head; //머리의 색
extern  color color2Head;
extern  color color1Body; //몸의 색
extern  color color2Body;
extern  color color2Empty; //빈칸의 색. 혹시 디자인이 바뀔 경우를 대비해서 색을 지정함.
extern  color color2Trap;
extern int map2p[sizeud2p][sizelr2p]; //맵의 크기.

extern int direction1; //1p뱀이 현재 보고있는 방향.
extern int direction2; //2p뱀이 현재 보고있는 방향
extern int life2p; //뱀의 길이
extern int hit1p; //1p 충돌 전역변수
extern int hit2p;
//함수 지정
void twoplayer(); //2p게임에서의 메인함수격.
void init2p(); //2p게임을 초기화한다.

//--> 남열

void TPM(int,int);
void ST();
void gotoxy();
//--> 상현
void update2p(); //2p게임을 업데이트한다.
void checkCollision(int*, int*);//충돌처리를 한다.
void mapupdate();
void print2pmap();
//--> 지훈
int twoplayerending(int x, int y);//게임이 끝나고 누가 이겼는지 화면에 보여준다.
													 //파라미터로는 누가 충돌했는지가 주어진다.