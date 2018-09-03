#include<stdio.h>
#include<cstring>

#define maxn 200

int main(){
	int s;
	scanf("%d",&s);

	if((s%2)!=0)
		printf("%d %d",0,0);
	else{

	int i=s/4;

	if((s%4)==0){
		printf("%d ",i);
		printf("%d",(s/2));
	}
	else{
		printf("%d ",i+1);
		printf("%d",(s/2));
	}
	}
	return 0;
}

