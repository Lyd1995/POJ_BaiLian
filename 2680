#include<stdio.h>
#include<string.h>

typedef struct patient{
	char sex[10];
	float white;
	float red;
	int blood;
	int percent;
	int blood_r;
}patient;


int main(){
	int k,i;
	patient p[100];
	int sta[100];
	memset(sta,0,sizeof(sta));

	scanf("%d",&k);

	for(i=0;i<k;i++){
		scanf("%s %f %f %d %d %d",&p[i].sex,&p[i].white,&p[i].red,&p[i].blood,&p[i].percent,&p[i].blood_r);
		if(p[i].sex[0]=='f'){

			if(p[i].blood>150||p[i].blood<110)
				sta[i]++;
			if(p[i].percent>40||p[i].percent<36)
				sta[i]++;
		}
		else{
			if(p[i].blood>160||p[i].blood<120)
				sta[i]++;
			if(p[i].percent>48||p[i].percent<42)
				sta[i]++;
		}

		if(p[i].white>10.0||p[i].white<4.0)
			sta[i]++;

		if(p[i].blood_r>300||p[i].blood_r<100)
			sta[i]++;

		if(p[i].red>5.5||p[i].red<3.5)
			sta[i]++;
	}
	for(i=0;i<k-1;i++){
		if(sta[i]==0)
			printf("normal\n");
		else
			printf("%d\n",sta[i]);
	}

	if(sta[i]==0)
			printf("normal\n");
	else
			printf("%d\n",sta[i]);

	return 0;
}
