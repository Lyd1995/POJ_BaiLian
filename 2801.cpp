#include<stdio.h>
#include<cstring>
#include<cmath>
#include<stdlib.h>

#define maxn 100
#define ma 12

int main(){
	int n,m,p,i,j;
	int characters[26];
	char matrix[ma];
	char word[maxn];

	memset(characters,0,sizeof(characters));
	scanf("%d%d%d",&n,&m,&p);

	for(i=0;i<n;i++){
		scanf("%s",matrix);
		
		for(j=0;j<m;j++)
			characters[matrix[j]-'A']++;
	}

	for(i=0;i<p;i++){
		scanf("%s",word);

		for(j=0;word[j]!='\0';j++)
			characters[word[j]-'A']--;
	}

	for(i=0;i<26;i++){
		
		while(characters[i]>0){
			printf("%c",'A'+i);
			characters[i]--;
		}
	}

	return 0;
}

