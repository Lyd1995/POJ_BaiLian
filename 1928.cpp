#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<cmath>
using namespace std;

int matrix[100][100];

typedef struct monkey{
	int num;
	int x,y;
}monkey;

monkey mo[10000];

bool cmp(monkey a,monkey b){
	if(a.num>b.num) return true;
	else return false;
}

int main(){
	int n,m,t;
	int sum,k;
	int curi,curj,toltime;
	int c;
	scanf("%d",&c);
	while(c--){

    	scanf("%d %d %d",&m,&n,&t);
		k=sum=0;

    	int i,j;
    	for(i=1;i<=m;i++){
	    	for(j=1;j<=n;j++){
	     		scanf("%d",&matrix[i][j]);
	     		if(matrix[i][j]!=0){
	    			mo[k].num=matrix[i][j];
	    			mo[k].x=j;
	    			mo[k].y=i;
	    			k++;
				}
			}
		}

    	sort(mo,mo+k,cmp);

    	curi=0;
    	curj=mo[0].x;
    	toltime=0;

    	int dx,dy;

     	for(i=0;i<k;i++){
    		dx=abs(mo[i].x-curj);//列间距
         	dy=abs(mo[i].y-curi);//行间距
    		if(toltime+dx+dy+1+mo[i].y<=t){
    			toltime+=dx+dy+1;
    			sum+=mo[i].num;
    			curi=mo[i].y;
    			curj=mo[i].x;
    		//	printf("%d\n",mo[i].num);
			}
    		else
	    		break;		
		}
    	printf("%d\n",sum);
	}
	return 0;
}
