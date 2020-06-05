#include<stdio.h>
#include<string.h>
int failure[100];
void fail(char *pat)
{
	int i,j;
	int n=strlen(pat);
	failure[0]=-1;
	for(j=1;j<n;j++)
	{
		i=failure[j-1];
		while(pat[j]!=pat[i+1] &&(i>=0))
			i=failure[i];
		if(pat[j]==pat[i+1])
			failure[j]=i+1;
		else
			failure[j]=-1;
	}
}
int pmatch(char *s,char *p)
{
	int ls,i=0,j=0,lp;
	ls=strlen(s);
	lp=strlen(p);
	while(i<ls  && j<lp)
	{
		if(s[i]==p[j])
		{
			i++;
			j++;
		}
		else if(j==0) i++;
		else j=failure[j-1]+1;
	}
	return ((j==lp)?(i-lp+1):-1);
}
void main()
{
	char s[50],p[50];
	int ans;
	printf("Enetre the string and pattern\n");
	scanf("%s%s",s,p);
	fail(p);
	ans=pmatch(s,p);
	if(ans==-1)
		printf("Pattern not found\n");
	else
	{
		//ans =pmatch(s,p);
		printf("Pattern found at %d\n",ans);
	}
}
