#include <stdio.h>
#include <limits.h>
#define MAX_SIZE 100
void parentheses(int s[MAX_SIZE][MAX_SIZE], int i, int j)
{
    if (i == j) 
        printf("A%d", i);
    else 
    {
        printf("(");
        parentheses(s, i, s[i][j]);
        parentheses(s, s[i][j] + 1, j);
        printf(")");
    }
}
void chainorder(int dim[], int n)
{
    int m[MAX_SIZE][MAX_SIZE] = {0};
    int s[MAX_SIZE][MAX_SIZE] = {0};
    for (int l = 2; l <= n; l++) 
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + dim[i - 1] * dim[k] * dim[j];
                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("Optimal parenthesization: ");
    parentheses(s, 1, n);
    printf("\nMinimum number of scalar multiplications: %d\n", m[1][n]);
} 
int main()
{
    int dim[] = {5, 10, 3, 12, 5, 50, 6};
    int n = sizeof(dim) / sizeof(dim[0]) - 1;
    chainorder(dim, n);
return 0;
}