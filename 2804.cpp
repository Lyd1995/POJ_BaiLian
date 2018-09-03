#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char c[20];
char s[20];
char inputc[20];

typedef struct dictionaries{
	char ch1[11],ch2[11];
}dictionaries;

dictionaries word[100005];
/*
void interpret(int n){
	int i,j;
	
	while(1){
		gets(c);
		if(c[0]=='\0')
			break;
		for(i=0;i<n;i++){
			j=1;
			j=strcmp(c,word[i].ch2);
			if(j==0)
				break;
		}
		if(j==0)
			printf("%s\n",word[i].ch1);
		else
			printf("eh\n");
	}
	return;
}
*/
bool cmp(dictionaries a,dictionaries b){
	if(strcmp(a.ch2,b.ch2)<0)  return true;
	else return false;
}

int main(){
	int i,len,k;
	k=0;

	while(1){
		gets(inputc);
		if(inputc[0]=='\0')
			break; 
		len=strlen(inputc);
		for(i=0;i<len;i++){
			if(inputc[i]==' '){
				strncpy(word[k].ch1,inputc,i);
				strncpy(word[k].ch2,inputc+i+1,len-i-1);
				word[k].ch1[i]='\0';
				word[k].ch2[len-i-1]='\0';
				k++;
				break;
			}
		}
	}

	sort(word,word+k,cmp);
	int max,min,in,flag;

	while(scanf("%s",c)!=EOF){
  		min=0;
	    max=k-1;
		flag=1;
		while(max>min){
			in=(max+min)/2;
			if(strcmp(word[in].ch2,c)==0){
				printf("%s\n",word[in].ch1);
				flag=0;
				break;
			}
			if(strcmp(word[in].ch2,c)>0)
				max=in;
			if(strcmp(word[in].ch2,c)<0)
				min=in+1;
		}
		if(flag){
	    	if(strcmp(word[max].ch2,c)==0)
	    		printf("%s\n",word[max].ch1);
    		else{
	    		if(strcmp(word[min].ch2,c)==0)
    	    		printf("%s\n",word[min].ch1);
	    		else
	     			printf("eh\n");
			}
		}
	}

	return 0;
}
