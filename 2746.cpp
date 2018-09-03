#include<stdio.h>
#include<string.h>

int num[500];

int main(){
	int n,m;
	while(1){
		scanf("%d %d",&n,&m);
		memset(num,1,sizeof(num));
		if(n==0&&m==0)
			break;
		int i,j,flag;
		i=1;
		j=1;
		flag=0;
		while(1){
			for(i=1;i<=n;i++){
				if(num[i]!=0){
					if(j==m){//报号J
		     		   	num[i]=0;
						flag++;
			     		j=1;
						if(flag==n)
				    		break;
						continue;
					}
					j++;//下一个
				}
			}
			if(flag==n)
				break;
		}
		printf("%d\n",i);
	}
	return 0;
}

