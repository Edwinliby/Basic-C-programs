#include<stdio.h>

struct poly
{
 int coe;
 int exp;
} p1[10], p2[10], p3[10];

int n,m,i,j,k;
int read(struct poly p[10], int a);
int display(struct poly p[10], int a);

int main()
{
  printf("Enter the number of terms of first Polynomial:");
  scanf("%d",&n);
  read(p1,n);
  printf("First Poly:\n");
  display(p1,n);

  printf("\nEnter the number of terms second Polynomial:\n");
  scanf("%d",&m);
  read(p2,m);
  printf("Second Poly:\n");
  display(p2,m);

  i=0,j=0,k=0;

	while(i<n && j<m)
	{
		if(p1[i].exp==p2[j].exp)
		{
			p3[k].coe=p1[i].coe + p2[j].coe;
			p3[k].exp=p1[i].exp;
			i++;
			j++;
			k++;
		}
		else if(p1[i].exp>p2[j].exp)
		{
			p3[k].coe=p1[i].coe;
			p3[k].exp=p1[i].exp;
			i++;
			k++;
		}
		else
		{
			p3[k].coe=p2[j].coe;
			p3[k].exp=p2[j].exp;
			j++;
			k++;
		}
	}
	while(i<n)
	{
		p3[k].coe=p1[i].coe;
		p3[k].exp=p1[i].exp;
		i++;
		k++;
	}
	while(j<m)
	{
		p3[k].coe=p2[j].coe;
		p3[k].exp=p2[j].exp;
		j++;
		k++;
	}
 
  printf("\nNew Polynomial:\n");
  for(i=0; i<=k; i++)
  {
   if(i<k)
     printf("%dx^%d +",p3[i].coe,p3[i].exp);
   else
     printf("%dx^%d",p3[k-1].coe,p3[k-1].exp); 
  }
}

/*Polynomial read Function*/
int read(struct poly p[10], int a)
{
  printf("Enter the coeficents in Descending Order:\n");
  for(i=0;i<=a;i++)
     { 
       printf("\t"); 
       scanf("%d",&p[i].coe); 
     }
  printf("Enter the exponents in Descending Order:\n");
  for(i=0;i<=a;i++)
     {
       printf("\t"); 
       scanf("%d",&p[i].exp);
     }
}

/*Polynomial display Function*/
int display(struct poly p[10], int a)
{
  for(i=0;i<=a;i++)
  {
   if(i<a)
     printf("%dx^%d +",p[i].coe,p[i].exp);
   else
     printf("%dx^%d",p[a].coe,p[a].exp); 
  }
}