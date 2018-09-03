#include<stdio.h>
#include<string.h>

#define max 1000

long b2ten(char a[],int len){
	int i;
	long j=2;
	long k;
	long sum=0;

	if(len==31&&a[0]>=1)
		return 2147483647;
	if(len>31)
		return 2147483647;

	for(i=len-1;i>=0;i--){
		k=j-1;
		sum+=(a[i]-'0')*k;
		j*=2;
	}
	return sum;
}

int main(){
	char x[40];
	long n;
	int len,i,j;


	long y[max];

	int flag=0;
	i=0;
	while(scanf("%s",&x)!=EOF){
		len=strlen(x);
		if(len==1&&x[0]=='0')
			break;

		if(x[0]=='-'){
			flag=1;
			for(j=0;j<len;j++)
				x[j]=x[j+1];
			len-=1;
		}
		else
			flag=0;

		n=b2ten(x,len);

		if(n>2147483647)
			n=2147483647;
		if(flag)
			y[i]=-n;
		else
		    y[i]=n;
		i++;
	}

	len=i;
	for(i=0;i<len-1;i++)
		printf("%d\n",y[i]);
	printf("%d",y[i]);

	return 0;
}
