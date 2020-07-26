#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

//using malloc//
/*
int main()
{
    int *ptr,n,i;
    printf("enter the element of an array: ");
    scanf("%d",&n);
    ptr=(int *)malloc(n*sizeof(int));

    if(ptr==0)
    {
        printf("memory is not allocated\n");
        return;
    }
    else{
        printf("memory is successfully allocated");
    }
    for ( i=0;i<n;i++)
    {
        ptr[i]=i+1;
    }
    printf("the elements of an array are:");
    for (i=0;i<n;i++)
    {
        printf("%d",ptr[i]);
    }
}
*/

//using calloc
int main()
{
    int *ptr,n,i;

    printf("enter the number of element: ");
    scanf ("%d",&n);

    ptr=(int *)calloc(n,sizeof(int)); 

    if(ptr==0)
    {
        printf("memory allocation is fail!!");
    }
    else{
        printf("memory is successfully allocated!!");
    }

    for (i=0;i<n;i++){
        ptr[i]=i+1;
    }
    printf("\nthe elements of an array: ");
    for (i=0;i<n;i++)
    {
        printf("%d",ptr[i]);
    }
}