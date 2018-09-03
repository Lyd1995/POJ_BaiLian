#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct student{
	char name[20];
	int term_score;
	int aver_score;
	char leader;
	char west;
	int papers;
	int money;
	int num;
}student;

int cmp(student a,student b){
	if(a.money==b.money) return a.num<b.num;
	else return a.money>b.money;
}



int main(){
	int n,i,sum;
	sum=0;
	scanf("%d",&n);

	student elect[101];

	for(i=0;i<n;i++){
		elect[i].money=0;
		elect[i].num=i;
		scanf("%s %d %d %c %c %d",elect[i].name,&elect[i].term_score,&elect[i].aver_score,&elect[i].leader,&elect[i].west,&elect[i].papers);
		if(elect[i].term_score>80&&elect[i].papers>=1)
			elect[i].money+=8000;
		if(elect[i].term_score>85&&elect[i].aver_score>80)
			elect[i].money+=4000;
		if(elect[i].term_score>90)
			elect[i].money+=2000;
		if(elect[i].term_score>85&&elect[i].west=='Y')
			elect[i].money+=1000;
		if(elect[i].aver_score>80&&elect[i].leader=='Y')
			elect[i].money+=850;
		sum+=elect[i].money;
	}

	sort(elect,elect+n,cmp);

	printf("%s\n",elect[0].name);
	printf("%d\n",elect[0].money);
	printf("%d",sum);

	return 0;
}
