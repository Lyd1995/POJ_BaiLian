#include<stdio.h>

int main(){
	int a;
	scanf("%d",&a);
	if(a==0){
		printf("%d",0);
		return 0;
	}
	int f=1;
	int i=0;
	char e[20];
	
	while(a!=0){
		e[i]=(a%8)+'0';
		a=a/8;
		i++;
	}

	for(i=i-1;i>=0;i--)
		printf("%c",e[i]);

	return 0;
}
