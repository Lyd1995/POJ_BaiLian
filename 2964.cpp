#include<stdio.h>
#include<string.h>

int days[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
char week[7][20]={ "Saturday","Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

int day_y[]={365,366};

typedef struct calendar1{
	int y,m,d;
	char we[20];
}calendar1;

calendar1 cal;

int judge(int y){
	if(y%100==0){
		if(y%400==0)
			return 1;
		else
			return 0;
	}
	else{
		if(y%4==0)
			return 1;
		else
			return 0;
	}
}

int year(int &n){
	int j;
	j=judge(cal.y);
	while(n>=day_y[j]){
		n-=day_y[j];
		if(n<0){
			n+=day_y[j];
			break;
		}
		cal.y++;
		j=judge(cal.y);
	}
	return j;
}

void month(int &n,int num){
	int j;
	j=num;
	while(n>=days[j][cal.m]){
		n-=days[j][cal.m];
		cal.m++;
	}
}

void day(int &n){
	cal.d+=n;
}


void weeks(int n){
	int i,len;
	i=n%7;
	len=strlen(week[i]);
	strcpy(cal.we,week[i]);
	cal.we[len]='\0';
}

int main(){
	int k,n;

	while(1){
		scanf("%d",&n);
	//	n++;
		if(n==-1)
			break;
		cal.y=2000;
		cal.m=1;
		cal.d=1;
		
		weeks(n);
		k=year(n);

		month(n,k);
        day(n);
		
		printf("%d-%02d-%02d %s\n",cal.y,cal.m,cal.d,cal.we);
	}
	return 0;
}
