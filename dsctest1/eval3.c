#include<stdio.h>
typedef enum
{
	lparen,rparen,plus,minus,times,divide,mod,eos,operand
}precedence;
int stack[100];
char expr[100];

void push(int *top,int n)
{
	if(*top>= 99)
		printf("Stack full\n");
	else
		stack[++(*top)]=n;
}
int pop(int *top)
{
	int i;
	if(*top<0)
	{
		i=32767;
		return i;
	}
	else
		return stack[(*top)--];
}
precedence getToken(char *symbol,int *n)
{
	*symbol=expr[(*n)++];
	switch(*symbol)
	{
		case '+':return plus;
		case '-':return minus;
		case '*':return times;
		case '/':return divide;
		case '%':return mod;
		case ')':return rparen;
		case '(':return lparen;
		case '\0':return eos;
		default:return operand;
	}
}
int eval()
{
	precedence token;
	char symbol;
	int n;
	int op1,op2;
	int top=-1;
	token=getToken(&symbol,&n);
	while(token!=eos)
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
	int n=eval();
	printf("The result is %d\n",n);
}


