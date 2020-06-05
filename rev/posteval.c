#include<stdio.h>
typedef enum
{
	lparen,rparen,plus,minus,times,divide,mod,eos,operand}precedence;
char expr[100];
int stack[100];
void push(int *top,int i)
{
	if((*top)>=100)
		printf("Stack ful\n");
	else
		stack[++(*top)]=i;
}
int pop(int *top)
{
	if(*top<0)
		printf("Stack empty\n");
	else
		return stack[(*top)--];
}
precedence gettoken(char *symbol,int *n)
{
	*symbol=expr[(*n)++];
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
int eval()
{
	precedence token;
	char symbol;
	int op2,op1,n=0;
	int top=-1;
	token=gettoken(&symbol,&n);
	while(token!=eos)
	{
		if(token == operand)
			push(&top,symbol-'0');
		else
		{
			op2=pop(&top);
			op1=pop(&top);
			switch(token)
			{
				case plus:push(&top,op1+op2);
					  break;
				case minus:push(&top,op1-op2);
					   break;
				case times:push(&top,op1*op2);
					   break;
				case divide:push(&top,op1/op2);
					    break;
				case mod:push(&top,op1%op2);
					 break;
			}
		}
		token=gettoken(&symbol,&n);
	}
	return pop(&top);
}
void main()
{
	int ans;
	printf("Enter the expr\n");
	scanf("%s",expr);
	ans=eval();
	printf("The result is %d\n",ans);
}

