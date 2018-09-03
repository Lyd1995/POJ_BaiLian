#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int cmp(int a,int b){
	return a>b;
}

int main(){
	int fr[26],co[26];
	char a[200];
	int i,j,len,max;

	memset(fr,0,sizeof(fr));
	memset(co,0,sizeof(co));
	memset(a,0,sizeof(a));

	for(i=0;i<4;i++){
		gets(a);
		j=0;
		len=strlen(a);
		for(j=0;j<len;j++){
			if(a[j]-'A'>=0&&a[j]-'A'<=25){
			   fr[a[j]-'A']++;
			   co[a[j]-'A']++;
			}
		}
	}

	sort(co,co+26,cmp);
	max=co[0];

	for(i=max;i>0;i--){
		for(j=0;j<26;j++){
			if(fr[j]>=i)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
	for(i=0;i<25;i++)
		printf("%c ",i+'A');
	printf("%c",i+'A');

	return 0;
}

