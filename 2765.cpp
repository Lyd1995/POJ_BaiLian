#include<stdio.h>
#include<string.h>


int main(){
	char e[30];
	char t[100];
	double f=1.0/8;
	scanf("%s",e);
	int len,i;
	int j;
	double sum=0.0;
	len=strlen(e);
	for(i=2;i<len;i++){
		sum+=(e[i]-'0')*f;
		f/=8;
	}
	i=0;
	while(sum!=0){
		sum*=10;
		j=sum;
		t[i++]=j+'0';
		sum=sum-j;
	}
		
	printf("%s [8] ",e);
	printf("= ");
	printf("0.");
	for(j=0;j<i;j++)
		printf("%c",t[j]);
	printf(" [10]");

	return 0;
}
