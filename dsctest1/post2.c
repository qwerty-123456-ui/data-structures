#include<stdio.h>
#include<stdlib.h>
typedef enum
{
	lparen,rparen,plus,minus,times,divide,mod,eos,operand
}precedence;
precedence stack[100];
char expr[100];
static int isp[]={0,19,12,12,13,13,13,0};
static int icp[]={20,19,12,12,13,13,13,0};
void add(int *top,precedence i)
{
	if(*top==99)
		printf("Stack full\n");
	else
		stack[++(*top)]=i;
}
precedence pop(int *top)
{
	if(*top<0)
		printf("Stack empty\n");
	else
		return stack[(*top)--];
}
void printtoken(precedence t)
{
	switch(t)
	{
		case plus:printf("+");
			  break;
		case minus:printf("-");
			   break;
		case times:printf("*");
			   break;
		case divide:printf("/");
			    break;
		case mod:printf("%%");
			 break;
	}
}
precedence getToken(char *symbol,int *n)
{
	*symbol=expr[(*n)++];
	switch(*symbol)
	{
		case '(':return lparen;
	        case ')':return rparen;
	       	case '+':return plus;
		case '-':return minus;
	       	case '*':return times;
		case '?':return divide;
		case '%':return mod;
	        case '\0':return eos;
	       	default:return operand;
	}
}
void postfix()
{
	int n=0;
	char symbol;
	precedence token;
	int top=0;
	stack[0]=eos;
	for(token=getToken(&symbol,&n) ; token !=eos ;token=getToken(&symbol,&n))
	{
		if(token==operand)
			printf("%c",symbol);
		else if(token==rparen)
		{
			while(stack[top] != lparen)
				printtoken(pop(&top));
			pop(&top);
		}
		else
		{
			while(isp[stack[top]]>=icp[token])
				printtoken(pop(&top));
			add(&top,token);
		}
	}
	while((token=pop(&top))!=eos)
		printtoken(token);
}
void main()
{
	printf("Enter the expresssion\n");
	scanf("%s",expr);
	postfix();
}
























	

