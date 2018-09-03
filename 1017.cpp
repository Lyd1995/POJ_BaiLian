#include<stdio.h>

#define max 100000

int main(){
	int a,b,c,d,e,f,two,one;
	int sum[max];
	int i=0;
	two=one=0;
	while(1){
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		if(a==0&&b==0&&c==0&&d==0&&e==0&&f==0)
			break;

		sum[i]=f+e+d+(c+3)/4;

		switch (c%4){
			case 0 : two=0;break;
			case 1 : two=5;break;
			case 2 : two=3;break;
			case 3 : two=1;break;
		}

		two+=5*d;

		if(b>two)
			sum[i]+=(b-two+8)/9;

		one=sum[i]*36-f*36-e*25-d*16-c*9-b*4;

		if(a>one)
			sum[i]+=(a-one+35)/36;
		i++;
	}
	for(int j=0;j<(i-1);j++)
	printf("%d\n",sum[j]);
	printf("%d",sum[i-1]);
	return 0;
}
