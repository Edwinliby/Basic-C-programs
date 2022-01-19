#include<stdio.h>

int n,m,k,i;
int c[100]={0},c1[100]={0},c2[100]={0},c3[100]={0}; 
int read(int c[100], int a);
int display(int c[100], int a);

void main()
{
  printf("Enter the degree of first Polynomial:");
  scanf("%d",&n);
  printf("Enter the Coefficents:");
  read(c1,n);
  printf("First Polynomial:");
  display(c1,n);
  printf("\nEnter the degree of second polynomial:");
  scanf("%d",&m);
  printf("\nEnter the Coefficents:");
  read(c2,m);
  printf("Second Polynomial:");
  display(c2,m);
  printf("\nAdding the two polynomials:-");
  if (m>n)
 {
   k=m;
  for( i=0;i<=m;i++)
   c3[i] = c1[i];
  for( i=0;i<=k;i++)
   c3[i] += c2[i];
 }
 else
 {
   k=n;
  for( i=0;i<=n;i++)
   c3[i] = c2[i];
  for( i=0;i<=k;i++)
    c3[i] += c1[i];
 }
  printf("\nThe new polymomial: ");
  display(c3,k);
}
int read(int c[100], int a)
{
  for(i=0;i<=a;i++)
     { 
       printf("\nCoefficent %d:",i+1);
       scanf("%d",&c[i]);
     }
}

int display(int c[100], int a)
{
  for(i=0;i<=a;i++)
  {
   if(i<a)
     printf("%dx^%d +",c[i],i);
   else
     printf("%dx^%d",c[i],i); 
  }
}
