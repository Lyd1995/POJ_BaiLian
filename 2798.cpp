#include<stdio.h>
#include<string.h>

int main(){
	int n;
	scanf("%d",&n);
	char b[10005];
	char s[]={"0123456789ABCDEF"};
	int f[]={1,2,4,8};
	while(n--){
	    scanf("%s",b);
		int len=strlen(b);
		if(len==1&&b[0]=='0'){
			printf("0");	
			printf("\n");
			continue;
		}
		int i,j,sum;
		int d=len%4;
		sum=0;
		for(i=d;i>0;i--){
			if(b[d-i]=='1') 
				sum+=f[i-1];
		}
		if(sum)
		   printf("%c",s[sum]);
		for(i=d;i<len;i+=4){
			sum=0;
			for(j=0;j<4;j++){
				if(b[i+j]=='1')
					sum+=f[3-j];
			}
			printf("%c",s[sum]);
		}
		putchar('\n');
	}
	return 0;
}
