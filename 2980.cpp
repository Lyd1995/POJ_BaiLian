#include<stdio.h>
#include<string.h>

int an1[205];
int an2[205];

char c1[205];
char c2[205];

int ans[500];


int main(){
	gets(c1);
	gets(c2);
	int len1,len2,i,j,k,m;

	memset(ans,0,sizeof(ans));

	len1=strlen(c1);
	len2=strlen(c2);

	j=0;
	for(i=len1-1;i>=0;i--)
		an1[j++]=c1[i]-'0';

	m=0;
	for(i=len2-1;i>=0;i--)
		an2[m++]=c2[i]-'0';

	for(i=0;i<len1;i++){
		for(k=0;k<len2;k++)
			ans[i+k]+=an1[i]*an2[k];
	}
    int temp;
	for(i=0;i<420;i++){
		if(ans[i]>9){
    		temp=ans[i];
    		ans[i]=temp%10;
    		ans[i+1]+=temp/10;
		}
	}
    int flag=0;
	for(i=420;i>=0;i--){
		if(flag){
			printf("%d",ans[i]);
		}
		else{
			if(ans[i]){
				printf("%d",ans[i]);
				flag=1;
			}
		}
	}
    if(flag==0)
		printf("0");

	return 0;
}
