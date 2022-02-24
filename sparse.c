#include<stdio.h>

int A[50][50], B[50][50], b[50][50] = {0}, t[50][50] = {0};
int i, j, r, c;
int n, sr, s;

int spar(int r, int c, int a[50][50]);
int input(int r, int c, int a[50][50]);
int display(int sr);
int add(int p[50][50], int q[50][50]);

int main()
{
	printf("Enter no of rows : ");
	scanf("%d",&r);
	printf("Enter no.of columns : ");
	scanf("%d",&c);

	printf("\nEnter the first matrix :");
	input(r,c,A);
	spar(r,c,A);
	display(sr);

	printf("\nEnter the second matrix :");
	input(r,c,B);
	spar(r,c,B);
	display(sr);

	printf("\nSum of two sparse matrix :");
	add(A,B);
	spar(r,c,t);
	display(sr);
}

int input(int r, int c, int a[50][50])
{	
	n = 0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("\nElements for %d row and %d column :",i,j);
			scanf("%d",&a[i][j]);
			if(a[i][j] != 0)
		 		 n++;
		}
	}
	sr = n;
}

int spar(int r, int c, int a[50][50])
{
	b[0][0] = r;
	b[0][1] = c;
	b[0][2] = n;
	s=1;
	for(i=0; i<r ;i++)
	{
	 	for(j=0; j<c ;j++)
		{
			if(a[i][j] != 0)
			{
			   b[s][0] = i;
			   b[s][1] = j;
			   b[s][2] = a[i][j];
			   s++;
			}
		}
	}
}

int display(int sr)
{
	printf("\nsparse matrix :- \n");
	for(i=0; i<=sr; i++)
    {
		printf("\n");
		for(j=0; j<3; j++)
		{
			printf("%d",b[i][j]);
			printf("\t");
		}
	}
}

int add(int p[50][50], int q[50][50])
{
	n=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			t[i][j] = p[i][j] + q[i][j];
			if( t[i][j] != 0)
				n++;		
		}
	}
	sr=n;
}
