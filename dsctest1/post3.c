#include<stdio.h>
typedef enum
{
        lparen,rparen,plus,minus,times,divide,mod,eos,operand
}precedence;
precedence stack[100];
char expr[100];

void push(int *top,precedence n)
{
        if(*top>= 99)
                printf("Stack full\n");
        else
                stack[++(*top)]=n;
}
precedence pop(int *top)
{
        //int i;
        if(*top<0)
        {
		printf("Stck empty\n");
            //    i=32767;
          //      return i;
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
void print(precedence t)
{
	switch(t)
	{
		case :printf("");
		      break;
	         case :printf("");
                      break;
                 case :printf("");
                      break;
                  case :printf("");
                      break;
                 case :printf("");
                      break;


int eval()
{
        precedence token;
        char symbol;
        int n;
        int op1,op2;
        
