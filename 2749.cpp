#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int div1(int n,int m)//n: num  m:factor
{
	
	if(n==1) return 1;
	if(m==1) return 0;

	if(n%m==0) //m is n's factor
	{
		return div1(n/m,m)+div1(n,m-1);
	}
	return div1(n,m-1);
}


int main(int argc, char** argv) 
{
	int ncases;
	scanf("%d",&ncases);
	int n,i;
	while(ncases--)
	{
		scanf("%d",&n);
		i=div1(n,n);
		printf("%d\n",i);
	}
	return 0;
}
