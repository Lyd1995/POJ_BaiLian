#include<stdio.h>
#include<string.h>

char ch1[10000];
char ch2[10000];
int num1[26];
int num2[26];

int main(){
	scanf("%s",ch1);
	scanf("%s",ch2);
	
	memset(num1,0,sizeof(num1));
	memset(num2,0,sizeof(num2));

	int i,j,len;
	len=strlen(ch1);

	for(i=0;i<len;i++){
		num1[ch1[i]-'A']++;
		num2[ch2[i]-'A']++;
	}

	int sum;
	

	for(i=0;i<26;i++){
		for(j=0;j<26;j++){
			if(num1[i]==num2[j]){
				num2[j]-=num1[i];
				break;
			}
		}
	}
	sum=0;
	for(i=0;i<26;i++)
		sum+=num2[i];

	if(sum==0)
		printf("YES");
	else
		printf("NO");

	return 0;
}

