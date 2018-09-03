#include<stdio.h>
#include<string.h>
#include<algorithm>

int main(){
	char s[1005];
	char c;
	int ch[26];
	int len,i,j,n,max;
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		memset(ch,0,sizeof(ch));
		len=strlen(s);
		for(i=0;i<len;i++)
			ch[s[i]-'a']++;
		max=0;
		for(i=25;i>=0;i--){
			if(ch[i]>=max){
				max=ch[i];
				j=i;
			}
		}

		c=j+'a';

		printf("%c ",c);
		printf("%d\n",max);
	
	}
	return 0;
}
