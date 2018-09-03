#include<stdio.h>
#include<string.h>

#define max 202

int main(){
	int n[15],n2[max];
	int a,i,sum;
	sum=0;
	i=0;
	memset(n2,0,sizeof(n2));
	while(1){
		scanf("%d",&n[i]);
		if(n[i]==0)
			break;
		n2[n[i]]=1;
		i++;
	}

	a=i;

	for(i=0;i<a;i++){
		if(n2[2*n[i]]==1)
			sum++;
	}
	
	printf("%d",sum);
	return 0;
}
