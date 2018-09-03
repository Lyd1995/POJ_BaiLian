#include<stdio.h>
#include<string.h>

char a[10000],a1[10000];
char b[10000],b1[10000];


int main(){
	gets(a);
	gets(b);
	int i,len_a,len_b,flag;
	flag=0;
	len_a=strlen(a);
	len_b=strlen(b);
	int k,j;
	k=0;
	for(i=0;i<len_a;i++){
		if(a[i]==' ')
			continue;
		else
			a1[k++]=a[i];
	}
	j=0;
	for(i=0;i<len_b;i++){
		if(b[i]==' ')
			continue;
		else
			b1[j++]=b[i];
	}

	if(k==j){
		for(i=0;i<k;i++){
			if(a1[i]-b1[i]!=0 && a1[i]-b1[i]!=32 && b1[i]-a1[i]!=32){
				printf("NO");
				return 0;
			}
		}
		printf("YES");
	}
	else
    	printf("NO");
	return 0;
}

