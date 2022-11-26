#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 50
#define HGT 10
char * stk[HGT];
int t=-1;

int convert(char *);
char * pop();
void push(char *x);

int main(void)
{
	char a[20];
	
	printf("enter expression:");
	fgets(a,20,stdin);
	
	convert(a);
	
	printf("infix expression :%s\n",pop());
}

int convert(char *a)
{	char *psh=(char *)malloc(MAX);
	char *op2=(char *)malloc(MAX);
	char *op1=(char *)malloc(MAX);
	char *pus=(char *)malloc(MAX);
	int len=strlen(a);
	static int i=0;
	if(i==len-1)
		return 0;
	else if(isdigit(a[i]))
	{	strcpy(psh,(char[2]){a[i],'\0'});
		
		push(psh);
		
	}
	else
	{
		
		op2=pop();
		op1=pop();
		
		strcpy(pus,"");
		strcat(pus,"(");
		strcat(pus,op1);
		strcat(pus,(char[2]){a[i],'\0'});
		strcat(pus,op2);
		strcat(pus,")");
		push(pus);
		
		
	}
	i++;
	convert(a);
	return 0;

}

void push(char *x)
{
	char *new=(char *)malloc(MAX);
	strcpy(new,x);
	
	stk[++t]=new;
	
	
}

char * pop()
{	
	char *new=(char *)malloc(MAX);
	char *x;
	x=stk[t];
	
	strcpy(new,x);
	
	free(stk[t]);
	t--;
	return new;
}
