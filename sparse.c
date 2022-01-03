#include<stdio.h>
#define srow 50
#define mrow 20
#define mcol 20
#define scol 50
int mat[mrow][mcol],sparse[srow][scol];
int i,j,nzero=0,mr,mc,sr,s;
int spar();
int input();
int display();

int main()
{
	printf("Enter no.of rows: ");
	scanf("%d",&mr);
	printf("Enter no.of columns: ");
	scanf("%d",&mc);

	printf("\nEnter the first matrix:-");
	input();
	spar();
	display();

	printf("\nEnter the second matrix:-");
	input();
	spar();
	display();
}

int input()
{
	for(i=0;i<mr;i++)
	{
		for(j=0;j<mc;j++)
		{
		printf("\nElements for %d row and %d column :-",i,j);
		scanf("%d",&mat[i][j]);
		}
	}
}

int spar()
{
	printf("\nEntered matrix:");
	for(i=0; i<mr ;i++)
	{printf("\n");
		for(j=0; j<mc ;j++)
		{
		  printf("%d\t",mat[i][j]);
		  if(mat[i][j]!=0)
		  nzero++;
		}
	}
	
	sr=nzero+1;
	sparse[0][0] = mr;
	sparse[0][1] = mc;
	sparse[0][2] = nzero;
	s=1;
	for(i=0; i<mr ;i++)
	{
	 	for(j=0; j<mc ;j++)
		{
			if(mat[i][j]!=0)
			{
			   sparse[s][0]=i+1;
			   sparse[s][1]=j+1;
			   sparse[s][2]=mat[i][j];
			   s++;
			}
		}
	}
}

int display()
{
	printf("\nsparse matrix is: \n");
	for(i=0;i<sr-1;i++)
    {
		printf("\n");
		for(j=0;j<3;j++)
		{
		printf("%d",sparse[i+1][j]);
		printf("\t");
		}
	}
}