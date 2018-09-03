#include<stdio.h>

int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};


int main(){
	int n,i;
	int month,day,num,month_r,day_r;
	

	scanf("%d",&n);

	while(n--){
		int during=0;
		scanf("%d %d %d %d %d",&month,&day,&num,&month_r,&day_r);
		if(month==month_r)
			during=day_r-day;
		else{
			during+=days[month]-day;
			for(i=month+1;i<month_r;i++)
				during+=days[i];
			during+=day_r;
		}
		for(i=0;i<during;i++)
			num*=2;
		printf("%d\n",num);
	}
	return 0;
}
