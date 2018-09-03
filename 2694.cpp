#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

double an;

double trans(void){
	char c[100];
	scanf("%s",c);
	switch (c[0]){
	case '+':return trans()+trans();
	case '-':return trans()-trans();
	case '*':return trans()*trans();
	case '/':return trans()/trans();
	default :return atof(c);
	}
}

int main(){
	an=trans();
	printf("%f",an);
	return 0;
}
