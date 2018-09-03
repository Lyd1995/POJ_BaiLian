#include<stdio.h>
#include<string.h>

char str1[1000],str2[1000];

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
/*
int maxcomlen(int i,int j)
{
	if(i==0||j==0)
		return 0;
	if(str1[i-1]==str2[j-1])
		return (maxcomlen(i-1,j-1)+1);
	else
		return (max(maxcomlen(i,j-1),maxcomlen(i-1,j)));
}*/
int maxcomlen[1000][1000];

int main()
{
	int i,j,sublen;
	while(scanf("%s",str1)!=EOF)
	{
		scanf("%s",str2);
		memset(maxcomlen,0,sizeof(maxcomlen));

		int len1=strlen(str1);
		int len2=strlen(str2);

		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				if(str1[i-1]==str2[j-1])
				{
					maxcomlen[i][j]=maxcomlen[i-1][j-1]+1;
				}
				else
				{
					maxcomlen[i][j]=max(maxcomlen[i-1][j],maxcomlen[i][j-1]);
				}
			}
		}
		sublen=maxcomlen[len1][len2];
		printf("%d\n",sublen);
	}
	return 0;
}
