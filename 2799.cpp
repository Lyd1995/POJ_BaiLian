#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct float1{
	char ch[100];
	int dot;
}float1;

float1 arr[10005];

bool cmp(float1 x,float1 y){
	int flag;
	int lenx,leny;
	char cx[100],cy[100];

	lenx=strlen(x.ch);
	leny=strlen(y.ch);

	if(x.ch[0]=='-'&& y.ch[0]!='-') return true;
	if(x.ch[0]!='-'&& y.ch[0]=='-') return false;
	if(x.ch[0]=='-'&& y.ch[0]=='-'){	
		strncpy(cx,x.ch+1,lenx-1);
		strncpy(cy,y.ch+1,leny-1);
		cx[lenx-1]='\0';
		cy[leny-1]='\0';
		flag=strcmp(cx,cy);
		if(flag>0)
			return true;
		else
			return false;
	}
	else{
		strncpy(cx,x.ch+1,lenx-1);
		strncpy(cy,y.ch+1,leny-1);
		cx[lenx-1]='\0';
		cy[leny-1]='\0';
		flag=strcmp(cx,cy);
		if(flag>0)
			return false;
		else
			return true;
	}
}



int main(){
	int n,i,j,len,dot_max;
	dot_max=0;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%s",arr[i].ch);
		len=strlen(arr[i].ch);
		for(j=0;j<len;j++){
			if(arr[i].ch[j]=='.'){
				arr[i].dot=j;
				if(j>dot_max)
					dot_max=j;
				break;
			}
		}
	}

//	sort(arr,arr+n,cmp);

	for(i=0;i<n;i++){
		for(j=0;j<(dot_max-arr[i].dot);j++)
			printf(" ");
		printf("%s\n",arr[i].ch);
	}

	return 0;
}
