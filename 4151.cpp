// t4151.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;


struct movies
{
	int sta, end;
	int dis;
};

movies mo[105];
int used[1005];

bool cmp(movies a, movies b)
{
	if (a.end < b.end) return true;
	else return false;
}

bool judge_m(int n)
{
	int i,flag;
	flag = 1;
	if (mo[n].dis > 1)
	{
		for (i = mo[n].sta + 1; i < mo[n].end; i++)
		{
			if (used[i] != 0)
			{
				flag = 0;
				break;
			}
		}
	}
	else
	{
		if (used[mo[n].sta] != 0 && used[mo[n].end] != 0)
			flag = 0;
	}
	if (flag)
	{
		for (i = mo[n].sta; i <= mo[n].end; i++)
		{
			used[i] = 1;
		}
		return true;
	}
	else
		return false;
}

int main()
{
	int n,i,k;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;

		k = 0;
		memset(used, 0, sizeof(used));

		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &mo[i].sta, &mo[i].end);
			mo[i].dis = mo[i].end - mo[i].sta;
		}
		sort(mo, mo + n, cmp);
		for (i = 0; i < n; i++)
		{
			if (judge_m(i))
				k++;
		}
		printf("%d\n", k);
	}
	
    return 0;
}
