#include<stdio.h>
int main()
{
	int i,n,a[50],flag=0,k;
	printf("Enter the array size:");
	scanf("%d",&n);
	printf("Enter the array elements:");
	for(i =0; i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the search element:");
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
	 if ( k == a[i])
	   { flag=1;
	     break; 
	   }
	}
	if(flag ==1)
	printf("Element found at index: %d and location %d ",i,i+1);
	else
	printf("Element not found");
}
	
