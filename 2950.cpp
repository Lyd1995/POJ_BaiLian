#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

typedef struct node
{
	int num, i, j;
}node;

struct cmp
{
	bool operator()(node a, node b)
	{
		return a.num<b.num;
	}
};
priority_queue<node, vector<node>, cmp> p;
int totalPeanut(int K);

int main()
{
	int T, M, N, K;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d", &M, &N, &K);
		// 输入模块
		for (int i = 1; i<=M; i++)
		{
			for (int j = 1; j<=N; j++)
			{
				int temp;
				scanf("%d", &temp);
				if (temp > 0)
				{
					node a;
					a.i = i;
					a.j = j;
					a.num = temp;
					p.push(a);
				}
			}
		}
		//  计算采摘总量
		printf("%d\n", totalPeanut(K));
		while (p.empty() != 1)
			p.pop();
	}
}
int totalPeanut(int K)
{
	int x = 0, y = 0, t = 0, sum = 0;
	if(p.empty() == 1)
		return 0;	 	
	while (1)
	{
		node q;
		if(p.empty() == 1)
			return sum;
			
		q = p.top();
		if (x == 0)
			x = q.j;
			
		t += abs(q.j - x) + abs(q.i - y) + 1;			
	//	printf("个数：%d   （%d,%d）   时间：%d\n",q.num,q.i,q.j,t);

		if ((t + q.i) > K)//超时
		{
		//	printf("t=%d   t+q.j=%d\n\n",t,(t + q.j)) ;
			return sum;
		}
		else
		{
			sum += q.num;
			x = q.j;
			y = q.i;
		//	printf("x=%d，y=%d  sum=%d\n\n\n\n",x,y,sum);
			p.pop();
		}	
	}
}
