#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct arrary_sort
{
	int num;
	int n;
}arrary_sort;

arrary_sort mon[3000];
int matrix[60][60];

int cmp(arrary_sort &a,arrary_sort &b)
{
	return a.num>b.num; 
}

int computerTime(int x1,int y1,int x2,int y2,int time);

int main()
{
	int T,M,N,K;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&M,&N,&K);
		int k=1;
		//输入模块
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				scanf("%d",&matrix[i][j]);
				mon[k].num=matrix[i][j];
				mon[k].n=k;
				k++;
			}
		}
		//排序
		sort(mon,mon+M*N,cmp);
		//计算到最大值的行坐标与列坐标 
		int row=(mon[0].n-1)/N,column=(mon[0].n-1)%N; 
	//	printf("第%d棵花生，坐标：%d,%d    %d\n\n",1,row,column,mon[0].n);
		int count=0;
		//剩余时间
		K=computerTime(column,-1,column,row,K); 
		if(K<0)
		{
			printf("0\n\n\n");
		}
		else
		{
			int i=1;
			int x=column,y=row;
			count+=mon[0].num;
			while(K>=0)
			{
				row=(mon[i].n-1)/N;
				column=(mon[i].n-1)%N;
				
				K=computerTime(x,y,column,row,K);
			//	printf("第%d棵花生，坐标：%d,%d    %d  剩余时间：%d\n\n",i+1,row,column,mon[i].n,K);
				
				if(K>=0)
				{
					count+=mon[i].num;
					x=column;
					y=row;
		//			printf("已经采摘了第%d棵花生，坐标：%d,%d   这棵有%d个花生   现在一共有%d个花生    剩余时间为：%d  \n\n",i,row,column,mon[i].num,count,K);
				}
				else
				{
					printf("%d",count);
				}
				i++;
			}
		}
		//
	}
	return 0;
}
int computerTime(int x1,int y1,int x2,int y2,int time)
{
	int t1=abs(x1-x2)+abs(y1-y2)+1; // 前往下一个目标的时间+采摘花生的时间
	int t2=y2+1;                    //回到路边所需的时间
	
	if(time>=t1+t2) 
	{
		return (time-t1);      //时间还够 
	}
	else
	{
		return -1;              //时间不够了 
	}
}
