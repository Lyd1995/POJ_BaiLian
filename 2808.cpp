#include<stdio.h>
#include<cstring>

#define maxn 101
#define maxs 10001

int main(){
	int len,num;

	scanf("%d%d",&len,&num);

	int ben,end;
	int i,j,sum;
	sum=0;
	int acer[maxs];

	memset(acer,0,sizeof(acer));

	for(i=0;i<num;i++){
		scanf("%d%d",&ben,&end);
		for(j=ben;j<=end;j++)
			acer[j]=1;
	}

	for(i=0;i<=len;i++)
		if(acer[i])
			sum++;

	printf("%d",len-sum+1);


	int tree=len+1;


	return 0;
}
