#include<stdio.h>
#include<stdlib.h>
typedef enum
{
	lparen,rparen,plus,minus,times,divide,mod,eos,operand
}precedence;
char expr[100];
int stack[100];
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
		case '/':return divide;
		case '%':return mod;
		case'\0':return eos;
		default:return operand;
	}
}
void push(int *top,int i)
{
	if((*top)>=99)
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
int eval()
{
	precedence token;
	char symbol;
	int op1,op2;
	int n=0,top=-1;
	token=getToken(&symbol,&n);
	while(token !=eos)
	{
		if(token==operand)
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
		token=getToken(&symbol,&n);
	}
	return pop(&top);
}
void main()
{
	printf("Enter the expression\n");
	scanf("%s",expr);
	int ans=eval();
	printf("the reult is %d\n",ans);
}
