#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int peek1[3]={23,28,33};

int cur[3];

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int main(int argc, char** argv)
{
	int p,e,i,d;
	int j,k;
	int ncases,days;
	int p1,e1,i1;
	ncases=1;
	
	while(1)
	{
		scanf("%d %d %d %d",&p,&e,&i,&d);
		k=0;
		if(p==-1)
		{
			break;
		}
		
		days=d;
	
		if(i==p&&i==e)
		{
			days=21252;
			printf("Case %d: the next triple peak occurs in %d days.\n",ncases,days-d);
			ncases++;
			continue;
		}
		p=p%23;
		e=e%28;
		i=i%33;
		
		while(1)
		{
			p1=(days-p)%peek1[0];
			e1=(days-e)%peek1[1];
			i1=(days-i)%peek1[2];
			if(i1==0&&p1==0&&e1==0)
			{
	     		printf("Case %d: the next triple peak occurs in %d days.\n",ncases,days-d);
	    		ncases++;
		    	break;
			}
			days++;
		//	k++;
		}
	} 
	return 0;
}
