#include <stdlib.h>
#include "twoplayer.h"



void TPM(int x, int y)
{
	int i;
	setColor(color2Wall);
	gotoxy((108 - 2 * x) / 2 + 1, 5);//À­º¯
	for (i = 0; i <= x + 1; i++)
	{
		printf("%s",ch2Wall);
	}

	for (i = 0; i <= y - 1; i++)//ÁÂº¯
	{
		gotoxy((108 - 2 * x) / 2 + 1, 6 + i);
		printf("%s", ch2Wall);
	}

	for (i = 0; i <= y - 1; i++)// ¿ìº¯
	{
		gotoxy((108 - 2 * x) / 2 + 3 + 2 * x, 6 + i);
		printf("%s", ch2Wall);
	}

	gotoxy((108 - 2 * x) / 2 + 1, 6 + y);//¾Æ·§º¯
	for (i = 0; i <= x+1; i++)
	{
		printf("%s", ch2Wall);
	}
	
}