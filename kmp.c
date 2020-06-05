#include<stdio.h>
#include<string.h>
int failure[100];
void fail(char *pat)
{
	int i,j,n;
	n=strlen(pat);
	failure[0]=-1;
	for(j=1;j<n;j++)
	{
		i=failure[j-1];
		while(pat[j]!=pat[i+1] && (i>=0))
			i=failure[i];
		if(pat[j]==pat[i+1])
			failure[j]=i+1;
		else
			failure[j]=-1;
	}
}
int pmatch(char *s,char *p)
{
	int ls,lp,i=0,j=0;
	ls=strlen(s);
	lp=strlen(p);
	while(i<ls && j<lp)
	{
		if(s[i]==p[j])
		{
			i++;
			j++;

		}
		else if(j==0) i++;
		else
			j=failure[j-1]+1;
	}
	return (j==lp)?(i-lp+1):-1;
}
void main()
{
	char s[100] ,p[100];
	printf("Enter the string and pattern\n");
	scanf("%s%s",s,p);
	fail(p);
	int i=pmatch(s,p);
	if(i!=-1)
		printf("Pattern found at %d\n",i);
	else
		printf("Pattern not found\n");
}



