#include<stdio.h>
#include<string.h>

char ch[]={"VWXYZABCDEFGHIJKLMNOPQRSTU"};
char message[205];

int main(){
	int i,len;
	gets(message);
	// entrance:
	while(strcmp(message,"START")==0){
		gets(message);//键入信息
		len=strlen(message);
		for(i=0;i<len;i++){
			if(message[i]>='A'&& message[i]<='Z')
				message[i]=ch[message[i]-'A'];
		}
		printf("%s\n",message);
		gets(message);//输入END
		gets(message);//输入START
	}
	return 0;
}
