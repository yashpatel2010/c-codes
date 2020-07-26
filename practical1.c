//call by value//
#include<stdio.h>
/*
void swapx(int,int);

int main()
{
    int a=10,b=20;
    printf("\n before swaping---> a=%d & b=%d ",a,b);
    swapx(a,b);
    printf("\n after swaping---> a=%d & b=%d",a,b);
    return 0;
}
void swapx(int x,int y)
{
    printf("\n before swaping---> x=%d & y=%d",x,y);
    int temp;
    temp=x;
    x=y;
    y=temp;
    printf("\n after swaping---> x=%d & y=%d",x,y);
}
*/

void swapx(int *,int *);

int main()
{
    
    int a=10,b=20;
    printf("before swaping---> a=%d & b=%d",a,b);
    swapx(&a,&b);
    printf("\n after swaping---> a=%d & b=%d",a,b);

}
void swapx(int *x,int *y)
{
    printf("\n before swaping---> x=%d & y=%d",*x,*y);
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
    printf("\n after swaping---> x=%d & y=%d ",*x,*y);
}