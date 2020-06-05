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
		while(pat[j] != pat[i+1] && (i>=0))
			i=failure[i];
		if(pat[j]==pat[i+1])
			failure[j]=i+1;
		else
			failure[j]=-1;
	}
	printf("Failure function is \n");
	for(i=0;i<n;i++)
		printf("%d\t",failure[i]);
	printf("\n");
}
int pmatch(char *s,char *pat)
{
	int i=0,j=0,ls,lp;
	ls=strlen(s);
	lp=strlen(pat);
	while(i<ls && j<lp)
	{
		if(s[i]==pat[j])
		{
			i++;
			j++;
		}
		else if(j==0)
			i++;
		else
			j=failure[j-1]+1;
	}
	return ((j==lp)?(i-lp+1):-1);
}
void main()
{
	int i;
	char s[90],pat[90];
        printf("Enter the string and pattern\n");
	scanf("%s%s",s,pat);
	fail(pat);
	i=pmatch(s,pat);
	if(i==-1)
		printf("Pattern not found\n");
	else
		printf("pattern found at %d\n",i);
}
