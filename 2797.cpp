#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct index1{ 
           char ch[25];
		   char pre[25];
}index1;

index1 word[1005];
/*
bool cmo(index x,index y){
	if(strcmp(x.ch,y.ch)<0) return true;
	else return false;
}*/

void prefix(int n){
	int i,j,k,flag;
	char co[25];
	for(i=0;i<n;i++){//需要寻找前缀的单词
		int len=strlen(word[i].ch);
		for(j=0;j<len;j++){//前缀长度
			strncpy(word[i].pre,word[i].ch,j+1);
			word[i].pre[j+1]='\0';
			flag=0;
			for(k=0;k<n;k++){//比对
				if(k!=i){
					strncpy(co,word[k].ch,j+1);
					co[j+1]='\0';
					if(strcmp(word[i].pre,co)==0)
						break;
					else
						flag++;
				}
			}
			if(flag==n-1)
				break;//该单词的最短前缀已找到
		}
	}
	return;
}

int main(){
	int i=0;
	while(scanf("%s",word[i++].ch)!=EOF);

//	sort(word1,word1+i,cmp);
	/*1、三重循环
	1：从第i个单词开始依次与除i之外的单词比较
	2、确定单词前缀长度，最长敞开式
	3比较
	*/
	prefix(i-1);
	int j;
	for(j=0;j<i;j++)
		printf("%s %s\n",word[j].ch,word[j].pre);
	return 0;
}
	
	
