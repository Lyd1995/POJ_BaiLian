#include<stdio.h>
#include<string.h>


char message[10000];
char message_en[10000];
/*
typedef struct encrption{
	char c[10000];
	int num[10000];
	int le;
}encryption;

encryption ch1,ch2,ch3;
*/

void divide(int len,int sec[]){
	int i,j,k;	
	for(i=0;i<len;i++){
		if(message_en[i]>='a' && message_en[i]<='i'){
			j=i+1;
			k=0;
			if(sec[0]==0){
	    		message[i]=message_en[i];
				continue;
			}
			while(1){
				if(message_en[j%len]>='a' && message_en[j%len]<='i'){
					k++;

					if(k==sec[0]){
						message[j%len]=message_en[i];
						break;
					}
					j++;
				}
				else
    				j++;
			}
		}
		if(message_en[i]>='j' && message_en[i]<='r'){
    		j=i+1;
    		k=0;
			if(sec[1]==0){
	    		message[i]=message_en[i];
				continue;
			}
   			while(1){
	   			if(message_en[j%len]>='j' && message_en[j%len]<='r'){
	   				k++;
	   				if(k==sec[1]){
				    	message[j%len]=message_en[i];
	    				break;
					}
					j++;
				}
		    	else
		     		j++;
			}
		}
		if(message_en[i]>='s' || message_en[i]=='_'){
	    	j=i+1;
	    	k=0;
			if(sec[2]==0){
	    		message[i]=message_en[i];
				continue;
			}
	    	while(1){
		    	if(message_en[j%len]>='s' || message_en[j%len]=='_'){
		    		k++;
		    		if(k==sec[2]){
		     			message[j%len]=message_en[i];
		   				break;
					}	
					j++;
				}
				else
					j++;
			}
		}
	}
	return;
}

int main(){
	int i,len;
	int sec[3];

	while(1){
		
		for(i=0;i<3;i++)
			scanf("%d",&sec[i]);

		if(sec[0]==0 && sec[1]==0 && sec[2]==0)
			break;

		scanf("%s",message_en);
		len=strlen(message_en);
		divide(len,sec);
		message[len]='\0';
		printf("%s\n",message);

	}
	return 0;
}
