#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];

char postfix[MAX],infix[MAX];

int top=-1;
void intopos();
int pr(char x);
char pop();
int isempty();
 void print();
void push(char y);

int main()
{
	printf("Enter the Expression: ");
	gets(infix);
	intopos();
	print();
	return 0;
}

 void intopos()
 {
 	int i,j=0;
 	char next,symbol;
 	
 	for(i=0;i<strlen(infix);i++)
 	{
 		symbol=infix[i];
 		switch(symbol)
 		{
 			case '(':
 				push(symbol);
 				break;
 			case ')':
 				while((next=pop())!='(')
 				postfix[j++]=next;
 				break;
 			case '+':
 			case '-':
 			case '*':
 			case '/':
 		    case '^':
 		    	while(!isempty() && pr(stack[top])>=pr(symbol))
 		    	postfix[j++]=pop();
 		    	push(symbol);
 		    	break;
 		    default:
 		    	postfix[j++]=symbol;
		 }
	 }
	 while(!isempty())
	 postfix[j++]=pop();
	 postfix[j]='\0';
 }
 
 int pr(char x)
 {
 	if(x=='+'|| x=='-')
 	return 1;
 	else if(x=='*'|| x=='/')
 	return 2;
 	else if(x=='^')
 	return 3;
 	else
 	return 0;
 }
 
 void print()
 {
 	for(int i=0;i<strlen(postfix);i++)
 	printf("%c",postfix[i]);
 }
 
 void push(char y)
 {
 	if(top==MAX-1)
 	printf("OVERFLOW!!!");
 	else
 	{
 		top++;
 		stack[top]=y;
	 }
 }
 
 char pop()
 {
 	if(top==-1)
 	printf("UNDEFLOW!!!!");
 	else
 	{
 		char z=stack[top];
 		top--;
 		return z;
	 }
 }
 
 int isempty()
 {
 	if(top==-1)
 	return 1;
	 else
	 return 0; 
 }