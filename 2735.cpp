#include<stdio.h>


int main(){
	int a;
	scanf("%d",&a);
	if(a==0){
		printf("%d",0);
		return 0;
	}

	int f=1;
	int n=0;
	while(a!=0){
		n+=(a%10)*f;
		f*=8;
		a/=10;
	}
	printf("%d",n);
	return 0;
}
