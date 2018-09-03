#include<stdio.h>
#include<string.h>

char time_regular[][5]={"UTC","GMT","BST","IST",
"WET","WEST","CET","CEST",
"EET","EEST","MSK","MSD",
"AST","ADT","NST","NDT",
"EST","EDT","CST","CDT",
"MST","MDT","PST","PDT",
"HST","AKST","AKDT","AEST",
"AEDT","ACST","ACDT","AWST"};
float differ[]={0,0,1,1,
0,1,1,2,
2,3,3,4,
-4,-3,-3.5,-2.5,
-5,-4,-6,-5,
-7,-6,-8,-7,
-10,-9,-8,10,
11,9.5,10.5,8};

char time1[10],ori[10],tar[10],time2[10];
//从凌晨12:00开始，计算时间
//a.m.:  12：01--12:59---01:00--00:59--11:59  a.m.
//p.m.:   12：00--12:59--11:59  p.m.
int translate(int &hour,int &minute,char time_ap[]){
	int i,j;
	float d;
	int sum;
	sum=i=j=0;
	while(strcmp(ori,time_regular[i])!=0)
		i++;
	while(strcmp(tar,time_regular[j])!=0)
		j++;
	d=differ[j]-differ[i];

	d*=60;
	if(time_ap[0]=='a'){
		if(hour==12)
			hour=0;
		sum+=hour*60+minute+(int)d;
	}
	if(time_ap[0]=='p'){
		if(hour<12)
			hour+=12;
		sum+=hour*60+minute+(int)d;
	}
	if(time_ap[0]==' '){
		sum+=hour*60+(int)d;
	}

	return sum;
}

int main(){
	int ncase,hour,minute,time;
	char ti[10],ampm[5];
	scanf("%d",&ncase);

	while(ncase--){
		scanf("%s",ti);
		ampm[0]=' ';
		switch (ti[0]){
		case 'n': 
			hour=12;
			minute=0;
			break;
		case 'm':
			hour=0;
			minute=0;
			break;
		default :
			sscanf(ti,"%d:%d",&hour,&minute);
			scanf("%s",ampm);
		}
    	scanf("%s %s",ori,tar);
    	time=translate(hour,minute,ampm);
		if(time<0)
			time+=1440;
		time=time%1440;
		switch (time){
		case 0:
			printf("midnight\n");
			break;
		case 720:
			printf("noon\n");
			break;
		default :
			hour=time/60;
			minute=time%60;
			if(time<720){
				if(hour>0)
		     		printf("%d:%02d a.m.\n",hour,minute);
				else
					printf("12:%02d a.m.\n",minute);
			}
			else{
				if(hour==12)
                      printf("12:%02d p.m.\n",minute);
			    else
					  printf("%d:%02d p.m.\n",hour%12,minute);
			}
		}
	}
	return 0;
}
