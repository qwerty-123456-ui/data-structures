#include<stdio.h>
#define MAXSIZE 100
char expr[MAXSIZE];
typedef enum 
{lparen,rparen,plus,minus,times,divide,mod,eos,operand}precedence;
precedence stack[MAXSIZE];
static int isp[]={0,19,12,12,13,13,13,0};
static int icp[]={20,19,12,12,13,13,13,0};
void push(int *top,precedence t)
{
	if(*top ==MAXSIZE-1)
		printf("Stack full \n");
	else
		stack[++(*top)]=t;
}
precedence pop(int *top)
{
	if(*top < 0){
		printf("Stack empty\n");
	}
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
                case '(':return lparen;
                case ')':return rparen;
                case '*':return times;
                case '/':return divide;
                case '%':return mod;
                case '\0':return eos;
		default:return operand;
	}
}
void printtoken(precedence t)
{switch (t)
	{
		case plus:printf("+");
			  break;
		case minus:printf("-");
			   break;
		case divide:printf("/");
			    break;
		case times:printf("*");
                           break;
		case mod:printf("%%");
			 break;
	}
}
void post()
{
	precedence token;
	char symbol;
	int n=0;
	int top=0;
	stack[0]=eos;
	for(token=gettoken(&symbol,&n) ; token !=eos ; token= gettoken(&symbol,&n))
	{
		if(token==operand)
			printf("%c",symbol);
		else if(token==rparen)
		{
			while(pop(&top) != lparen)
				printtoken(pop(&top));
			pop(&top);
		}
		else
		{
			while(isp[stack[top]] >= icp[token])
				printtoken(pop(&top));
			push(&top,token);
		}
	}
	while((token=pop(&top)) != eos)
		printtoken(token);
	printf("\n");
}
void main()
{printf("Enter the expression \n");
	scanf("%s",expr);
	post();
}






