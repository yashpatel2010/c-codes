//infix to postfix
#include<stdio.h>
#define size 100
int top=-1;
char stack[size];


void push(char item)
{
    if(top>=size-1){
        printf("\nThe stack is full\n");
    }
    else{
        top++;
        stack[top]=item;
    }
}
char pop()
{
    char item=stack[top];
    top=top-1;
    return (item);

}
int is_operator(char symbol)
{
    if(symbol=='^' || symbol=='*' || symbol=='/' || symbol=='+' || symbol=='-') return 1;
    else return 0;
}
int precedence(char symbol)
{
    if(symbol=='^')return 3;
    else if (symbol=='*' || symbol=='/')return 2;
    else if(symbol=='+' || symbol =='-')return 1;
    else return 0;
}


int main()
{
    char infix[size],postfix[size];
    int i=0,j=0;                                           //intial value
    printf("\nEnter infix expression: ");
    gets(infix);

    while(infix[i]!='\0')
    {
        char item=infix[i];
        if(item=='(')
        {
            push(item);
        }
        else if (item>='A' && item<='Z' || item>='a' && item<='z' )
        {   postfix[j]=item;
            j++;
        }
        else if(is_operator(item)==1)
        {
            char temp=pop();
            while(is_operator(item)==1 && precedence(temp)>=precedence(item))      //* - case
            {
                postfix[j]=temp;
                j++;
                temp=pop();
            }
            
            push(temp);                          //- * case
            push(item);
            
        
        }
        else if(item==')')
        {
            char temp=pop();
            while(temp!='(')                    //when it reaches left perentheniss print all elements up to this perenthenis
            {
                postfix[j]=temp;
                j++;
                temp=pop();
            }
        }
        else
        {
            printf("\n Invalid arithmetic expression\n");
            
            return 0;
        }
        i++;
    }
    while(top>-1)                          //for popping the case with out perenthenis
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';                          //when poping of elements are completed
    printf("\nThe postfix expression is: ");
    puts(postfix);
    
    return 0;
}    
