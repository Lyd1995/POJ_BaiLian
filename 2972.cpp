#include<stdio.h>
#include<string.h>

long b2long(char a[],int c){
	int i;
	int b[8];
	int len=strlen(a);
	int j,f;
	long sum=0;
	j=0;
	f=1;
	for(i=len-1;i>=0;i--){
		if(a[i]-'0'<c){
		b[j]=(a[i]-'0')*f;
		f*=c;
		sum+=b[j];
		j++;
		}
		else
			return -1;
	}
	return sum;
}

int main(){
	char q[8],p[8],r[8];
	scanf("%s%s%s",p,q,r);
	int i;
	long q_t,p_t,r_t;

	for(i=2;i<=16;i++){
		q_t=b2long(q,i);
		p_t=b2long(p,i);
		r_t=b2long(r,i);
		if(q_t==-1||p_t==-1||r_t==-1)
			continue;
		else
			if(r_t==q_t*p_t)
				break;
	}
	if(i>16)
		printf("%d",0);
	else
		printf("%d",i);


	return 0;
}
