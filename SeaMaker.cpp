// SeaMaker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include "SeaMaker.h"


int _tmain(int argc, _TCHAR* argv[])
{
	initSea();								// создадим пустое поле
	initShip(4, 1);		printf("3\n");		// ставим 4-х палубник
	initShip(3, 2);		printf("2\n");		// 3-х палубники
	initShip(2, 3);		printf("1\n");		// 2-х
	initShip(1, 4);		print();			// остальные палубники и рисуем
	
	system("pause");
	return 0;
}

void print()
{
	printBorder();
	printBody();	
	printBorder();
};
void printBody()
{
	for(int i=0; i<10; i++)
	{
		printf("|");
		for(int j=0; j<10; j++)
		{			
			if(SeaMap[i][j]) printf("x");
			else			printf(".");
		}
		printf("|");
		printf("\n");		
	}
}
void printBorder()
{
	for(int j=0; j<12; j++)
		{
			printf("-");
		}
		printf("\n");
}

void initSea()
{
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			SeaMap[i][j] = false;
		}
	}
}
ship randShip(int col)
{
	srand(time(0));
	ship ret;
	ret.x = rand() % 10;
	ret.y = rand() % 10;
	ret = shipSetRotate(ret, (rand() % 4));
	ret.col = col;
	return ret;
}
	
void SetShip(ship X)
{
	for(int i=0; i<X.col; i++)
	{	SeaMap[X.x][X.y] = true;
		X.x += X.xd;
		X.y += X.yd;
	}
}

void initShip(int col, int num)
{
	bool check = false;
	ship temp;
	
	for(int i=0; i<num; i++)
	{	check = false;
			while(check == false)
			{	temp = randShip(col);
				check = CheckVector(temp);
			}
		SetShip(temp);
	}
}

ship shipSetRotate(ship X, int gradus)
{
	switch (gradus)
	{	case 0 : 
		{	X.xd = -1;
			X.yd = 0;
			break;
		}
		case 1 :
		{	X.xd = 0;
			X.yd = -1;
			break;
		}
		case 2 :
		{	X.xd = 1;
			X.yd = 0;
			break;
		}
		case 3 :
		{	X.xd = 0;
			X.yd = 1;
			break;
		}
	}
	return X;
}

//	[o][o][o]
//	[o][x][o]
//	[o][o][o]
bool CheckSea(ship S)
{
	// Проверяем клетки вокруг предполагаемой палубы
	bool ret = true;
	if((S.x > -1) && (S.y > -1) && (S.x < 10) && (S.y < 10))
	{	int OreolX[9];
		int OreolY[9];
	
		OreolX[0] = S.x-1;	OreolX[1] = S.x;	OreolX[2] = S.x+1;
		OreolY[0] = S.y-1;	OreolY[1] = S.y-1;	OreolY[2] = S.y-1;
	
		OreolX[3] = S.x-1;	OreolX[4] = S.x;	OreolX[5] = S.x+1;
		OreolY[3] = S.y;	OreolY[4] = S.y;	OreolY[5] = S.y;
	
		OreolX[6] = S.x-1;	OreolX[7] = S.x;	OreolX[8] = S.x+1;
		OreolY[6] = S.y+1;	OreolY[7] = S.y+1;	OreolY[8] = S.y+1;
	
		for (int i=0;i<9;i++)
		{
			if((OreolX[i] > -1) && (OreolY[i] > -1) && (OreolX[i] < 10) && (OreolY[i] < 10))
			{
				if(SeaMap[OreolX[i]][OreolY[i]]) ret = false;
			}
		}
	}
	else ret = false;
	return ret;
}
bool CheckVector(ship S)
{
	bool ret = true;
	
	for(int i=0; i<S.col; i++)
	{	ret &= CheckSea(S);
		S.x += S.xd;
		S.y += S.yd;
	}
	return ret;
}