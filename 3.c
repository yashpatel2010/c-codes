//stack operation implemention//

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int top=-1,stack[MAX];
void push();
void pop();
void display();
void peek();
void change();



void main()
{
    int choice;

    while(1)
    {
        printf("\n *** STACK MENU ***");
        printf("\n\n 1.PUSH \n 2.POP \n 3.DISPLAY \n 4.PEEK \n 5.CHANGE \n 6.EXIT");
        printf("\nSelect any no. from menu:");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            case 4:peek();
            break;
            case 5:change();
            break;
            case 6:exit(0);
            
            default:printf("\n Invalid choice!!");
        }
    }
}
void push()
{
    int value;
    if (top==MAX-1)
    {
        printf("\nStack is full\n\n");
    }
    else
    {
        printf("\nEnter any element that you want to push: ");
        scanf("%d",&value);
        top=top+1;
        stack[top]=value; 
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nstack is empty\n");
    }
    else{
        printf("deleted element is %d",stack[top]);
        top=top-1;
        display();

        }
       
    }

void display()
{
    int i;
    if(top==-1)
    {
        printf("the stack is empty!!");
    }
    else{
        printf("\n the stack is...\n");
        for (i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
void peek()
{
    
    int p=stack[top];
    printf("next element to be deleted is: %d",p);
}
void change()
{
    if(top==-1){
        printf("\nstack is empty\n");
    }
    else{
    printf("\nEnter a value which you can change in place of last input: ");
    scanf("%d",&stack[top]);
    display();
    }
}







