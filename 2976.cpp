#include<stdio.h>
#include<string.h>
char str1[100005],str2[100005];

int judge(int len1,int len2){
	int i,j;
	j=0;
	for(i=0;i<len2;i++){
		if(str1[j]==str2[i]){
			if(j<len1-1)
	    		j++;
			else{
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 1;
}


int main(){

	while(scanf("%s",str1)!=EOF){
		scanf("%s",str2);
		int len1,len2,f;
		
		len1=strlen(str1);
		len2=strlen(str2);

		f=judge(len1,len2);
	}
	return 0;
}
		
