#include<stdio.h>
#include<stdlib.h>

int i,j,n,a[50];
void selectionsort();

void main()
{
    printf("Enter the array size:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }    
    selectionsort();
}

void selectionsort()
{
    int min,temp;
    for(i=0;i<n-1;i++)
    {
       min = i;
       for(j=i+1;j<n;j++)
       {
           if(a[j] < a[min])
                min = j;
       }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
    printf("The sorted array elements:");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
        printf(" ");
    }   
}