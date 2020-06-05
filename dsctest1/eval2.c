#include<stdio.h>
#include<stdlib.h>
typedef enum
{
        lparen,rparen,plus,minus,times,divide,mod,eos,operand
}precedence;
int stack[100];
char expr[100];
//static int isp[]={0,19,12,12,13,13,13,0};
//static int icp[]={20,19,12,12,13,13,13,0};
void push(int *top,precedence i)
{
        if(*top==99)
                printf("Stack full\n");
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
int eval()
{
        int n=0;
        char symbol;
        precedence token;
        int top=-1;
	int op1,op2;
        //stack[0]=eos;
        token=getToken(&symbol,&n);
        while(token !=eos)// ;token=getToken(&symbol,&n))
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
        printf("Enter the expresssion\n");
        scanf("%s",expr);
        printf("The result is :%d",eval());

}

