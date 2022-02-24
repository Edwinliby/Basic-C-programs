#include<stdio.h>

struct Polynomial
{
    int coe;
    int exp;
};

struct Polynomial P1[15], P2[15], result[15];

void display(struct Polynomial poly[], int terms)
{
    for(int i=0;i<=terms;i++)
    {
        if(i<terms)
        printf("%dx^%d +",poly[i].coe,poly[i].exp);
        else
        printf("%dx^%d",poly[terms].coe,poly[terms].exp); 
    }
}

int read(struct Polynomial poly[])
{
    int terms, i;
    printf("\nNumber of terms: ");
    scanf("%d", &terms);
    printf("\nEnter the coeffecients and exponents in DESCENDING order");
    for(i = 0 ; i<terms; i++)
    {
        printf("\nCoeffecient:");
        scanf("%d", &poly[i].coe);
        printf("Exponent:");
        scanf("%d", &poly[i].exp);
    }
    return terms;
}

int add(int n, int m)
{
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while(i < n && j < m)
    {
        if(P1[i].exp == P2[j].exp)
        {
            result[k].coe = P1[i].coe + P2[j].coe;
            result[k].exp = P1[i].exp;
            i++;
            j++;
            k++;
        }
        else if(P1[i].exp > P2[j].exp)
        {
            result[k].coe = P1[i].coe;
            result[k].exp = P1[i].exp;
            i++;
            k++;
        }
        else
        {
            result[k].coe = P2[i].coe;
            result[k].exp = P2[j].exp;
            j++;
            k++;
        }
    }

    while(i < n)
    {
        result[k].coe = P1[i].coe;
        result[k].exp = P1[i].exp;
        k++;
        i++;
    }

    while(j < m)
    {
        result[k].coe = P2[j].coe;
        result[k].exp = P2[j].exp;
        k++;
        j++;
    }
    return k;
}

int main()
{
    int n, m, resultCount;
    printf("First Expression:");
    n = read(P1);
    printf("\nSecond Expression:");
    m = read(P2);
    resultCount = add(n, m);
    printf("\nFinal Expression:");
    display(result, resultCount);
}