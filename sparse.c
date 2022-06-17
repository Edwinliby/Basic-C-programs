#include<stdio.h>

int A[50][50], B[50][50], b[50][50] = {0}, t[50][50] = {0};
int i, j, r, c,s1,s2;
int n, sr, s;

int spar(int a[50][50]);
int input(int a[50][50]);
int display();
int add(int p[50][50], int q[50][50]);

int main()
{
	printf("Enter no of rows : ");
	scanf("%d",&r);
	printf("Enter no.of columns : ");
	scanf("%d",&c);

	printf("\nEnter the first matris :");
	input(A);
	spar(A);
	display();

	printf("\nEnter the second matris :");
	input(B);
	spar(B);
	display();

	printf("\nSum of two sparse matris :");
	add(A,B);
	spar(t);
	display();
}

int input(int a[50][50])
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

int spar(int a[50][50])
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

int display()
{
	printf("\nSparse matris :- \n");
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
	sr=0;
	for(i=0; i<r ;i++)
	{
	 	for(j=0; j<c ;j++)
		{
			if(p[i][j] != 0 || q[i][j] != 0)
				sr++;
		}
	}

	s1=p[0][2];
	s2=q[0][2];
	i=j=s=0;

	while(i<=s1 && j<=s2)
    {   
	if(p[i][0] < q[j][0])      
	{       
		t[s][0] = p[i][0];      
		t[s][1] = p[i][1];       
		t[s][2] = p[i][2];       
		s++;         
		i++;      
	}   
	else if(q[j][0] < p[i][0])      
	{	       
		t[s][0]=q[j][0];          
		t[s][1]=q[j][1];          
		t[s][2]=q[j][2];
    	s++; 
		j++;
	}
	else if(p[i][1]<q[j][1])      
	{    
		t[s][0]=p[i][0];  
		t[s][1]=p[i][1]; 
		t[s][2]=p[i][2];  
		s++; 
		i++;
    }
	else if(q[j][1]<p[i][1])      
	{ 
		t[s][0]=q[j][0]; 
		t[s][1]=q[j][1];  
		t[s][2]=q[j][2];   
		s++;   
		j++;
	}  
	else
	{   
		t[s][0]=p[i][0];       
		t[s][1]=p[i][1];  
		t[s][2]=p[i][2]+q[j][2];  
		s++;    
		i++;       
		j++;   
		}
    }
	while(i<=s1)       
	{   
		t[s][0]=p[i][0];   
		t[s][1]=p[i][1];   
		t[s][2]=p[i][2];    
		i++;    
		s++;
    }
	while(j <= s2)  
    { 
		t[s][0]=q[j][0]; 
		t[s][1]=p[j][1];    
		t[s][2]=p[j][2]; 
		j++;
		s++;
    }
   
t[0][2]=s-1;     
}
