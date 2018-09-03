#include<stdio.h>
#include<cstring>

#define maxn 200

int compare(int a[],int b[],int l1,int l2){
	if(l1>l2)
		return 1;
	if(l1<l2)
		return -1;
	else{
		int i;
		for(i=l1-1;i>=0;i--){
			if(a[i]==b[i])
				continue;
			if(a[i]>b[i])
				return 1;
			if(a[i]<b[i])
				return -1;
		}
		return 0;
	}
}

int subtract(int a[],int b[],int l1,int l2){
	int i;
	for(i=0;i<l1;i++){
		a[i]-=b[i];
		if(a[i]<0){
			a[i]+=10;
			a[i+1]--;
		}
	}
	for(i=l1-1;i>=0;i--){
		if(a[i])
			return i;
	}
}


int main(){
	char str1[maxn],str2[maxn];
	scanf("%s",&str1);
	scanf("%s",&str2);

	int len1,len2;

	len1=strlen(str1);
	len2=strlen(str2);

	int i,j;
	int sub1[maxn],sub2[maxn];

	memset(sub1,0,sizeof(sub1));
	memset(sub2,0,sizeof(sub2));

	j=0;
	for(i=len1-1;i>=0;i--)
		sub1[j++]=str1[i]-'0';


	j=0;
	for(i=len2-1;i>=0;i--)
		sub2[j++]=str2[i]-'0';

	int flag,len;

	flag=compare(sub1,sub2,len1,len2);
	if(flag==0)
		printf("%d",0);

	if(flag==1){
		len=subtract(sub1,sub2,len1,len2);
		for(i=len;i>=0;i--)
			printf("%d",sub1[i]);	
	}

	if(flag==-1){
		len=subtract(sub2,sub1,len2,len1);
		sub2[len]=-sub2[len];
		for(i=len;i>=0;i--)
			printf("%d",sub2[i]);	
	}
	return 0;
}

