#include <stdio.h>
#include <malloc.h>
#include <conio.h>
struct node
{
	int coeff;
	int exp;
	struct node *next;
};
struct node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

void create(struct node *node)
{
	char ch;
	printf("\n Enter the coeff and exponent in decending order:");
	do
	{
		printf("\n Enter coeff:");
		scanf("%d", &node->coeff);
		printf("\n Enter exp:");
		scanf("%d", &node->exp);
		node->next = (struct node *)malloc(sizeof(struct node));
		node = node->next;
		node->next = NULL;
		printf("\n continue(y/n):\n");
		ch = getch();
	} while (ch == 'y' || ch == 'Y');
}
void show(struct node *node)
{
	while (node->next != NULL)
	{
		printf("%dx^%d", node->coeff, node->exp);
		node = node->next;
		if (node->next != NULL)
			printf("+");
	}
}
void polyadd(struct node *poly1, struct node *poly2, struct node *poly)
{
	while (poly1->next && poly2->next)
	{
		if (poly1->exp > poly2->exp)
		{
			poly->exp = poly1->exp;
			poly->coeff = poly1->coeff;
			poly1 = poly1->next;
		}
		else if (poly1->exp < poly2->exp)
		{
			poly->exp = poly2->exp;
			poly->coeff = poly2->coeff;
			poly2 = poly2->next;
		}
		else
		{
			poly->exp = poly1->exp;
			poly->coeff = poly1->coeff + poly2->coeff;
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
		poly->next = (struct node *)malloc(sizeof(struct node));
		poly = poly->next;
		poly->next = NULL;
	}
	while (poly1->next || poly2->next)
	{
		if (poly1->next)
		{
			poly->exp = poly1->exp;
			poly->coeff = poly1->coeff;
			poly1 = poly1->next;
		}
		if (poly2->next)
		{
			poly->exp = poly2->exp;
			poly->coeff = poly2->coeff;
			poly2 = poly2->next;
		}
		poly->next = (struct node *)malloc(sizeof(struct node));
		poly = poly->next;
		poly->next = NULL;
	}
}

int main()
{
	char ch;
		poly1 = (struct node *)malloc(sizeof(struct node));
		poly2 = (struct node *)malloc(sizeof(struct node));
		poly = (struct node *)malloc(sizeof(struct node));
		printf("\nEnter 1st number:");
		create(poly1);
		printf("\nEnter 2nd number:");
		create(poly2);
		printf("\n1st Number:");
		show(poly1);
		printf("\n2nd Number:");
		show(poly2);
		polyadd(poly1, poly2, poly);
		printf("\nAdded polynomial:");
		show(poly);
	
}