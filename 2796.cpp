#include<stdio.h>

int main(){
	int n[5];
	int a,i,sum;
	sum=0;
	scanf("%d",&a);

	for(i=0;i<5;i++){
		scanf("%d",&n[i]);
		if(n[i]<a)
			sum+=n[i];
	}
	
	printf("%d",sum);
	return 0;
}
