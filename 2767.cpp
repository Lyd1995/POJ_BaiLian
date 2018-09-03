#include<stdio.h>
#include<string.h>


int main(){
	char secret[26]={'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'};
	int i,len,j;
	j=0;
	char str[300];
	char str_un[300];
	gets(str);
	len=strlen(str);
	for(i=0;i<len;i++){
		if(str[i]-'A'>=0&&str[i]-'A'<=25)
		    str_un[i]=secret[str[i]-'A'];
		else
			str_un[i]=str[i];
		
	}

	for(i=0;i<len;i++)
		printf("%c",str_un[i]);

	return 0;
}
