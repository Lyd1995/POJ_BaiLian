#include<stdio.h>
#include<string.h>

char str[105][105];

void strrev1(char a[]){
	int i,len;
	char c;
	len=strlen(a);
	for(i=0;i<(len/2);i++){
		c=a[len-i-1];
		a[len-i-1]=a[i];
		a[i]=c;
	}
}

int searchStr(char str_min[],int n,int substr_max){
	//三层循环：1：子串长度
	//2：只要到最短的字符串里面找到子串即可，因为如果最短的里面都没有符合条件的，其他的字符串里面找到的子串也一定不符合
	//3：将所得子串与字符串比较
	int substr_len=substr_max;
	int str_len=strlen(str_min);
	char substr[105],substr_rev[105];
	int i,j;
	//1
	while(substr_len){
		
		for(i=0;i+substr_len<=str_len;i++){
			strncpy(substr,str_min+i,substr_len);
			strncpy(substr_rev,str_min+i,substr_len);
			substr[substr_len]='\0';
			substr_rev[substr_len]='\0';
			strrev1(substr_rev);
			int flag=1;
			//3
			for(j=0;j<n;j++){
				//判断是否为子串
				if(strstr(str[j],substr)==NULL&&strstr(str[j],substr_rev)==NULL){
					flag=0;//不是子串
					break;
				}
			}
			if(flag==1)//成功返回
				return substr_len;
		}
		substr_len--;
	}
	return 0;
}

int main(){
	int n,i,t;
	char str_min[105];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int substr_max=105;

		for(i=0;i<n;i++){
			scanf("%s",str[i]);
			int len=strlen(str[i]);
			if(substr_max>len){
				substr_max=len;
				strcpy(str_min,str[i]);
			} 
		}
		printf("%d\n",searchStr(str_min,n,substr_max));
	}
	return 0;
}

