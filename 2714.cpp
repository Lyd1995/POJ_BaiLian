#include<stdio.h>

int main(){
	int n,i,k;
	float sum;
	sum=0.0;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&k);
		sum+=k;
	}
	printf("%0.2f",sum/n);
	return 0;
}
