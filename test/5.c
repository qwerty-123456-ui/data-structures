#include<stdio.h>
#include<stdlib.h>
typedef enum {
	lparen,rparen,plus,minus,times,divide,mod,eos,operand
}precedence;
static int icp[]={20,19,12,12,13,13,13,0};
static int isp[]={0,19,12,12,13,13,13,0};
char expr[100];
precedence stack[100];
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
precedence gettoken(char *symbol,int *n)
{
	(*symbol)=expr[(*n)++];
	switch(*symbol)
	{
		case '(':return lparen;
		case ')':return rparen;
		case '+':return plus;
		case '-':return minus;
		case '*':return times;
		case '/':return divide;
                case '%':return mod;
                case '\0':return eos;
		default:return operand;
	}	
}
void push(int *top,precedence token)
{
	stack[++(*top)]=token;
}
precedence pop(int *top)
{
	if(top<0)
		printf("empty\n");
	else
	return stack[(*top)--];
}
void postfix()
{
	char symbol;
	int n=0;
	precedence token;
	int top=0;
	stack[0]=eos;
	int i;
	for(token=gettoken(&symbol,&n);token!=eos;token=gettoken(&symbol,&n))
	{
		if(token==operand)
			printf("%c",symbol);
		else if(token==rparen)
		{
			while(stack[top]!=lparen)
				printtoken(pop(&top));
			pop(&top);
		}
		else 
		{
			while(isp[stack[top]]>=icp[token])
				printtoken(pop(&top));
			push(&top,token);
		}
	}
	while((token=pop(&top))!=eos)
		printtoken(token);
	printf("\n");
}
void main()
{
	printf("Enetre expression\n");
	scanf("%s",expr);
	postfix();
}


