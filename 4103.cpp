#include <iostream>
#include<string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int map[50][50];
int count;

void dfs(int r,int c,int steps)
{
	if(steps==0)
	{
		count++;
		return;
	}
	else
	{
		if(map[r][c]==0)
		{
			map[r][c]=1;
			if(map[r+1][c]==0) dfs(r+1,c,steps-1);
     		if(map[r][c+1]==0) dfs(r,c+1,steps-1);
	    	if(map[r][c-1]==0) dfs(r,c-1,steps-1);
	    	map[r][c]=0;
		}
		else
		{
			return;
		}
	}
}

int main(int argc, char** argv) 
{
	memset(map,0,sizeof(map));
	int n;
	scanf("%d",&n);
	count=0;
	dfs(0,50,n);
	printf("%d",count);
	return 0;
}
