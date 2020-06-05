#include<stdio.h>
typedef enum
{
        lparen,rparen,plus,minus,times,divide,mod,eos,operand}precedence;
char expr[100];
precedence stack[100];
static int isp[]={0,19,12,12,13,13,13,0};
static int icp[]={20,19,12,12,13,13,13,0};
void push(int *top,precedence i)
{
        if((*top)>=100)
                printf("Stack ful\n");
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
void post()
{
        precedence token;
        char symbol;
        int n=0;
        int top=0;
	stack[0]=eos;
        for(token=gettoken(&symbol,&n);token!=eos;token=gettoken(&symbol,&n))
	{
                if(token == operand)
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
        int ans;
        printf("Enter the expr\n");
        scanf("%s",expr);
        post();
       	//ans=eval();
        //printf("The result is %d\n",ans);
}
