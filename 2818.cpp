#include<stdio.h>
#include<string.h>

int map[205];
int period[205];
char str[10000],str_new[10000];

int calculate(int n){
	int i;
	int tmp,co;

	for(i=1;i<=n;i++){
		co=0;
		tmp=i;
		tmp=map[tmp];
		co++;
		while(tmp!=i){
			tmp=map[tmp];
			co++;
		}
		period[i]=co;
	}
	return 0;
}

int convert(int num,int k){
	int i,times;
	times=k%period[num];

	int tmp;
	tmp=num;

	if(times==0){
		str_new[num-1]=str[num];
		return 0;
	}
	for(i=0;i<times;i++){
		tmp=map[tmp];
	}
	str_new[tmp-1]=str[num];
	return 0;
}

int main(){
	int i,n,f;
   //1：一次循环一个块，每个块得编码不同
	while(scanf("%d",&n)!=EOF && n){

    	for(i=1;i<=n;i++)
    		scanf("%d",&map[i]);
    //周期计算
    	f=calculate(n);
    	int k,len;
	//开始输入字符串：开始编码	
    	while(scanf("%d",&k)!=EOF && k){
			memset(str,' ',sizeof(str));
			memset(str_new,' ',sizeof(str_new));
			gets(str);
    		len=strlen(str);
			
			for(i=1;i<=n;i++){
				if(i!=len)
    	    		f=convert(i,k);//转换
			}

	    	str_new[n]='\0';
    		printf("%s\n",str_new);
		}
		printf("\n");
	}

	return 0;
}
