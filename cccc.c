#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#define max 10
int top=-1;
char stack[max];
void peep();
void push();
void pop();

void main()
{
    string ex[]={"x+y*z"};
    

    
}


void push()
{
    char value;
    if(top==max-1)
    {
        printf("\nstack is full\n");
    }
    else{
        top=top+1;
        stack[top]=value;
    }
}
void pop()
{
    if(top!=-1)
    {
        top=top-1;

    }
}
void peep()
{
    char d=stack[top];

}