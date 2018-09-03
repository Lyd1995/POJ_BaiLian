#include<stdio.h>
#include<cstring>

#define max 200

int main(){
	char add1[max+10];
	char add2[max+10];
	int i,j;

	int a1[max+10];
	int a2[max+10];

	int len1,len2;

	memset(a1,0,sizeof(a1));
	memset(a2,0,sizeof(a2));

	scanf("%s",add1);
	scanf("%s",add2);

	len1=strlen(add1);
    len2=strlen(add2);


	j=0;
	for(i=len1-1;i>=0;i--){
		a1[j++]=add1[i]-'0';
		
	}

	j=0;
	for(i=len2-1;i>=0;i--){
	
		a2[j++]=add2[i]-'0';
	}
	if(a1[len1-1]==0&&a2[len2-1]==0)
		printf("%d",0);
	else
	{
	for(i=0;i<max+10;i++){
		a1[i]+=a2[i];
		if(a1[i]>9){
			a1[i]=a1[i]-10;
			a1[i+1]++;
		}
	}

	bool flag=false;
	for(i=max+9;i>=0;i--){
		if(flag==false){
			if(a1[i])
				flag=true;
		}
		if(flag)
			printf("%d",a1[i]);
	}
	}
	return 0;
}
