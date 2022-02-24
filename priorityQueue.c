#include<stdio.h>
#include<stdlib.h>

int front=0,rear,n,i,j,a[50];

int enqueue();
int dequeue();
int peek();

int main()
{
    printf("Enter the array size:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(i=0; i<n;i++)
        scanf("%d",&a[i]);
    enqueue();
}

int enqueue()
{
    if((front == 0) &&(rear == n-1))
        printf("OverFlow !");
    else if( front == -1 && rear == -1)
    {
        front =rear=0;
        
    }
}