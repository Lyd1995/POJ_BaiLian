#include<stdio.h>
#include<string.h>

char hab[19][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol", "chen","yax","zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
char tzo[20][10]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen","eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int tzo_int[13]={1,2,3,4,5,6,7,8,9,10,11,12,13};

typedef struct tzol{
	int num,year;
	char word[10];
}tzol;

tzol maya;
//第一天用0表示还是1表示
//用0表示，则sum：0~364，tzo:0~259

int main(){
	int i,n,sum,m,k;
	char month[10];
	int day,year;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		sum=0;
		scanf("%d. %s %d",&day,month,&year);
		for(m=0;m<19;m++){
			if(strcmp(month,hab[m])==0) break;
		}

		sum+=year*365+m*20+day;//hab:0-364   tzo:0-259
		maya.year=sum/260;
		k=sum%260;
		maya.num=tzo_int[k%13];

		if(i==0)
			printf("%d\n",n);
	
		printf("%d %s %d\n",maya.num,tzo[k%20],maya.year);
	}

	return 0;
}

