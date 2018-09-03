#include<stdio.h>
#include<string.h>

int used[10];
char s[10];
char an[10];

void permutation(int n,int len){
	int i;
	if(n==len)
		printf("%s\n",an);
	else{
		for(i=0;i<len;i++){
			if(used[i]==0){
				an[n]=s[i];
				used[i]=1;
				permutation(n+1,len);
				used[i]=0;
			}
		}
	}
	return ;
}

int main(){
	
	gets(s);
	int len=strlen(s);
	an[len]='\0';
	memset(used,0,sizeof(used));
	permutation(0,len);//从第几个位置开始
	return 0;
}
