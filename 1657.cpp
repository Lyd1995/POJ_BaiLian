#include<stdio.h>
#include<cstring>
#include<cmath>
#include<stdlib.h>


int main(){
	int n,i,x[20],y[20];
	char current[5],next[5];

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s%s",&current,&next);
		//scanf("%s",&next);
		x[i]=abs(current[0]-next[0]);
    	y[i]=abs(current[1]-next[1]);
			//	printf("%d",x[i]);

	}
	for(i=0;i<n;i++){
		if(x[i]==0&&y[i]==0){
			printf("%d %d %d %d",0,0,0,0);
			printf("\n");
			continue;
		}

		if(x[i]>y[i]) 
			printf("%d ",x[i]);
		else 
			printf("%d ",y[i]);

		if(x[i]==y[i]||x[i]==0||y[i]==0)
			printf("%d ",1);
		else
			printf("%d ",2);

		if(x[i]==0||y[i]==0)
			printf("%d ",1);
		else
			printf("%d ",2);

		if(x[i]==y[i])
			printf("%d",1);
		else{
			if(((x[i]+y[i])%2)==0)
				printf("%d",2);
			else
				printf("%s","Inf");
		}
		printf("\n");

	
	}

	return 0;
