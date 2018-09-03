// T2000.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<string.h>

int money;//第n天可以拿多少钱
//void initialize1(void);
int rest_day(int n);

int main()
{
	int days;
	int j,k;
	//memset(money, 0, sizeof(money));
	//initialize1();
	while (1)
	{
		scanf("%d", &days);
		if (days == 0)
			break;
		j = rest_day(days);
		money = (j*(j + 1)*(2 * j + 1)) / 6;
		k = days - (j*(j + 1) / 2);
		money += k * (j + 1);
		printf("%d %d\n",days, money);
	}
    return 0;
}

/*void initialize1(void)
{
	int i,j,k;

	for (i = 1; i < 10001; i++)
	{
		j = rest_day(i);
		money[i] = (j*(j + 1)*(2 * j + 1)) / 6;
		k = i - (j*(j + 1) / 2);
		money[i] += k * (j+1);
	}
}*/
int rest_day(int n)
{
	//int i = 1;
	for (int i = 1; i <= 200; i++)
	{
		if (((i*(i + 1)) / 2) > n)
		{
			return i - 1;
		}
	}
}
