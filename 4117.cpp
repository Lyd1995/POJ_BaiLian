#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int f1(int n,int m)
{
	if(n==0) return 1;
	if(m==0) return 0;
	if(n-m>=0)
	{
		return f1(n-m,m)+f1(n,m-1);
	}
    else
    {
    	return f1(n,m-1);
	}
}

int main(int argc, char** argv) 
{
	int n,s;
	while(scanf("%d",&n)!=EOF)
	{
		s=f1(n,n);
		printf("%d\n",s);
	}
	
	return 0;
}
