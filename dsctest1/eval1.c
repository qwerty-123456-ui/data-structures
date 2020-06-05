#include<stdio.h>
#define MAXSIZE 100
int stack[MAXSIZE];
char expr[MAXSIZE];
typedef enum
{ lparen,rparen,plus,minus,times,divide,mod,eos,operand
}precedence;
void push(int *top,int i)
{
	if(*top ==MAXSIZE-1)
		printf("STACK FULL \n");
	else 
		stack[++(*top)]=i;
}
int pop(int *top)
{
	if(*top<0)
		printf("STACK EMPTY\n");
	else
		return stack[(*top)--];
}
precedence gettoken(char *symbol,int *n)
{
	*symbol=expr[(*n)++];
	switch(*symbol)
	{
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
	int n=0;
	int top=-1;
	char symbol;
	int op1,op2;
	token=gettoken(&symbol,&n);
	while(token != eos)
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
		token=gettoken(&symbol,&n);
	}
	return pop(&top);
}	

void main()
{
	printf("Enter the expression\n");
	scanf("%s",expr);
	int ans=eval();
	printf("The result of expression is %d\n",ans);
}
