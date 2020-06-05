#include<stdio.h>
#define MAX_SIZE 100
#define MAX_EXPR_SIZE 100
typedef enum
{
	lparan,rparan,plus,minus,times,divide,mod,eos,operand
}precedence;
int stack[MAX_SIZE];
char expr[MAX_EXPR_SIZE];
int top=-1;
void stackFull();
int eval();
void add(int *,int);
int pop(int *);
precedence getToken(char *,int *);
void main()
{
		int ans;
                printf("Enter the expression and to end enter . \n");
                scanf("%s",expr);
		ans=eval();
                printf("The result is %d\n",ans);
         
}
void add(int *top,int i )
{
        //printf("e");
        if(*top>=(MAX_SIZE-1))
        {
                //printf("e");
                stackFull();
        }
        //printf("error");
        stack[++(*top)]=i;
}
int pop(int *top)
{
        if(*top<0)
        {
              printf("Stack empty \n");
        }
        else
                return stack[(*top)--];
}
void stackFull()
{
        printf("Stack Full\n ");
}

int eval(void)
{
	precedence token;
	char symbol;
	int op1,op2;
	int n=0;
	int top=-1;
	token=getToken(&symbol,&n);
	while(token != eos)
	{
		if(token==operand)
			add(&top,symbol-'0');
		else
		{
			op2=pop(&top);
			op1=pop(&top);
			switch(token)
			{
				case plus:add(&top,op1+op2);
					  break;
				case minus:add(&top,op1-op2);
                                          break;
				case times:add(&top,op1*op2);
                                          break;
	                        case divide:add(&top,op1/op2);
                                          break;
                                case mod:add(&top,op1%op2);
                                          break;
			}
		}
		token=getToken(&symbol,&n);
	}
	return pop(&top);
}
precedence getToken(char *symbol, int *n)
{
	*symbol=expr[(*n)++];
	switch(*symbol)
	{
		case '(':return lparan;
		case ')':return rparan;
		case '+':return plus;
		case '-':return minus;
		case '/':return divide;
		case '*':return times;
		case '%':return mod;
		case '\0':return eos;
		default:return operand;
	}
}


