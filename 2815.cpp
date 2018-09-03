#include<stdio.h>
#include<string.h>

int color[50][50];
int room[50][50];
int roomnum;
int maxarea;
int curarea;

void dfs(int i,int j);

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}


int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	memset(color,0,sizeof(color));
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&room[i][j]);
		}
	}
	maxarea=0;
	for(i=0;i<n;i++)
	{
		
		for(j=0;j<m;j++)
		{
			
			if(color[i][j]==0){
				roomnum++;
				curarea=0;
				dfs(i,j);
				maxarea=max(maxarea,curarea);
			}
		}
	}
	printf("%d\n%d",roomnum,maxarea);

	return 0;
}



void dfs(int i,int j)
{
	if(color[i][j]!=0)
		return;
	else
	{
    	color[i][j]=roomnum;
    	curarea++;
		if((room[i][j]&1)==0) dfs(i,j-1);
		if((room[i][j]&2)==0) dfs(i-1,j);
		if((room[i][j]&4)==0) dfs(i,j+1);
		if((room[i][j]&8)==0) dfs(i+1,j);
	}
}
