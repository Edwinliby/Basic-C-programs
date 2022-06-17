#include <stdio.h>

void main()
{
    int n, m, k, i, c1[100], c2[100]; 
    int c3[100]={0};
    printf("Enter the degree of first Polynomial:");
    scanf("%d", &n);
    printf("Enter the Coefficents:\n");

    for (i = 0; i <= n; i++)
    {
        printf("\t");
        scanf("%d", &c1[i]);
    }
    for (i = 0; i <= n; i++)
    {
        if (i < n)
            printf("%dx^%d +", c1[i], i);
        else
            printf("%dx^%d", c1[i], i);
    }
    printf("\nEnter the degree of second polynomial:");
    scanf("%d", &m);
    printf("\nEnter the Coefficents:\n");
    for (i = 0; i <= m; i++)
    {
        printf("\t");
        scanf("%d", &c2[i]);
    }
    for (i = 0; i <= m; i++)
    {
        if (i < m)
            printf("%dx^%d +", c2[i], i);
        else
            printf("%dx^%d", c2[i], i);
    }

    printf("\nAdding the two polynomials");
    if (m > n)
    {
        for (i = 0; i <= m; i++)
            c3[i] = c1[i];
        k = m;
        for (i = 0; i <= k; i++)
            c3[i] += c2[i];
    }
    else
    {
        for (i = 0; i <= n; i++)
            c3[i] = c2[i];
        k = n;
        for (i = 0; i <= k; i++)
            c3[i] += c1[i];
    }
    printf("\nThe new polymomial: ");
    for (i = 0; i <= k; i++)
    {
        if (i < k)
            printf("%dx^%d +", c3[i], i);
        else
            printf("%dx^%d", c3[i], i);
    }
}