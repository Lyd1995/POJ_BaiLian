#include<stdio.h>
#include<string.h>
#include<cmath>
#include<stdlib.h>

int queenplace[92][8];
int broad[8][8];
int k,count;


void queen(int n){
	int j;
	int i1,j1;
	if(n==8){
		count++;
		return;
	}
	else{
		for(j=0;j<8;j++){
			if(broad[n][j]==-1){//等于说明可以放置
				broad[n][j]=n;
			  //  queenplace[k][n]=j;			
				for(k=count;k<92;k++){
					queenplace[k][n]=j+1;
				}
				//第n个皇后的领域：
				for(i1=0;i1<8;i1++){
					for(j1=0;j1<8;j1++){
						if(broad[i1][j1]==-1 && (i1==n || j1==j || abs(i1-n)==abs(j1-j)))
							broad[i1][j1]=n;
					}
				}
				queen(n+1);
               //撤回
				for(i1=0;i1<8;i1++){
					for(j1=0;j1<8;j1++){
						if(broad[i1][j1]==n)
							broad[i1][j1]=-1;
					}
				}
			}
		}
	}
}

int main(){
	int i,j;
	
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			broad[i][j]=-1;
		}
	}
	count=0;

	queen(0);

	int m,n;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		for(i=0;i<8;i++)
	    	printf("%d",queenplace[m-1][i]);
		printf("\n");
	}



	return 0;
}
