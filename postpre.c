#include<stdio.h>
#include<string.h>
#include<ctype.h>
int top=-1;
int outx=0;	
char stack[50];//operator stack
char b[50];//expression storage
void reverse(char array[50]) //reverses the infix expression
 {
	int i,j;
	char temp[100];
	for (i=strlen(array)-1,j=0;i+1!=0;--i,++j) {
		temp[j]=array[i];
	}
	temp[j]='\0';
	strcpy(array,temp);
	return array;
}
	int isoperator(char c) //checks if character is an operator
		{ 
			if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
				return 1;
			else 
				return 0;
		}
	int getprior(char c) //finds priority of operator
		{
			if(c=='^')
				return 3;
			else if(c=='*'||c=='/')
				return 2;
			else if(c=='+'||c=='-')
				return 1;
			else 
				return 0;
		}
	void push(char c)
		{
			if(top>=50)
				printf("\nStack Overflow");
			else
			{
			top=top+1;
			stack[top]=c;
			}
		}
	char pop()
		{	
			if(top<0)
				printf("\nStack Underflow");
			else
			{
				char c;
				c=stack[top];
				top=top-1;
				return c;
			}
		}
void convertpost(char *a,int n) //converts infix to postfix
	{
		int i=0;
		char x;
		push('(');
		strcat(a,")");
		while(i<=n)
			{
				if(a[i]=='(')
					push(a[i]);
				else if(isalpha(a[i])||isdigit(a[i]))
					{
						b[outx]=a[i];
						outx++;
					}		
				else if(isoperator(a[i])==1)
				{
					x=pop();
					if(getprior(x)!=3||getprior(a[i])!=3)
					{
						while(isoperator(x)==1&&getprior(x)>=getprior(a[i]))
						{
						b[outx]=x;
						outx++;
						x=pop();
						}
					}
					push(x);
					push(a[i]);
					
				}
				else if(a[i]==')')
				{
					x=pop();
					while(x!='(')
					{
					b[outx]=x;
					outx++;
					x=pop();
					}
				}
				if(i==n)
				{
					while(top>=0)
					{
						b[outx]=pop();
						outx++;
					}
				}
				i++;
			
			}
	}
	void convertpre(char *a,int n) //converts infix to prefix
	{
		int i=0;
		char x;
		push(')');
		strcat(a,"(");
		while(i<=n)
			{
				if(a[i]==')')
					push(a[i]);
				else if(isalpha(a[i])||isdigit(a[i]))
					{
						b[outx]=a[i];
						outx++;
					}		
				else if(isoperator(a[i])==1)
				{
					x=pop();
					if(getprior(x)!=3||getprior(a[i])!=3)
					{
						while(isoperator(x)==1&&getprior(x)>=getprior(a[i]))
						{
						b[outx]=x;
						outx++;
						x=pop();
						}
					}
					push(x);
					push(a[i]);
					
				}
				else if(a[i]=='(')
				{
					x=pop();
					while(x!=')')
					{
					b[outx]=x;
					outx++;
					x=pop();
					}
				}
				if(i==n)
				{
					while(top>=0)
					{
						b[outx]=pop();
						outx++;
					}
				}
				i++;
			
			}
	}
	
int main()
	{
		char exp[50],exp2[50];
		int n,i;
		printf("\nEnter infix expression:");
		scanf("%s",exp);
		strcpy(exp2,exp);
		n=strlen(exp);
		convertpost(exp,n);
		printf("\nPostfix Expression:");
		for(i=0;i<outx;i++)
		printf("%c",b[i]);
		outx=0;
		top=-1;
		printf("\n");
		reverse(exp2);
		convertpre(exp2,n);
		reverse(b);
		printf("Prefix Expression:");
		for(i=0;i<outx;i++)
		printf("%c",b[i]);
		printf("\n\n\n");		
	}

