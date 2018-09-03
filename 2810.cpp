#include <iostream>
#include<stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct percu
{
	int tr[3];
    int cu;	
}percu;

percu p[100];
int t;

int find1(int k)
{
	int i,j,l;

	int s=k*k*k;
	for(i=2;i<k;i++)
	{
		for(j=i;j<k;j++)
		{
			for(l=j;l<k;l++)
			{
				if((s-i*i*i-j*j*j-l*l*l==0))
				{
					p[t].tr[0]=i;
					p[t].tr[1]=j;
					p[t].tr[2]=l;
					p[t].cu=k;
					t++;
				}			
			}
		}
	}
}


int main(int argc, char** argv) 
{
	int n,i,j,k;
	scanf("%d",&n);
	k=6;
	t=0;
	while(k<=n)
	{
		find1(k);
		k++;
	}
//	sort(p,p+t,cmp);
    for(i=0;i<t;i++)
    {
    	printf("Cube = %d, Triple = (%d,%d,%d)\n",p[i].cu,p[i].tr[0],p[i].tr[1],p[i].tr[2]);
	}
	
	return 0;
}
