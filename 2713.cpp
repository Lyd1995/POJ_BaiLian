#include<stdio.h>
#include<string.h>

#define max 1001
//int matrix[max][max];

int main(){
	int i,j,n,x,y;
	int a,sum,flag1;
	x=y=sum=0;
	flag1=0;

	scanf("%d",&n);
	
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a);
			if(a==0&&flag1==0)
				x+=1;
			if(a==0)
				sum+=1;
		}
		if(x!=0)
		flag1=1;
	}

	y=(sum-2*x)/2;

	printf("%d",(x-2)*y);

	return 0;
}
