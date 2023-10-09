#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
int max(int a, int b)
{
    return (a > b) ? a : b;
} 
int lcs(char X[], char Y[], int m, int n)
{
    int dp[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n; j++)
    dp[0][j] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            {
                if (X[i - 1] == Y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
    }
    char lcsStr[MAX_SIZE];
    int index = dp[m][n];
    lcsStr[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0) 
    {
        if (X[i - 1] == Y[j - 1]) 
        {
            lcsStr[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } 
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    printf("Longest Common Subsequence: %s\n", lcsStr);
return dp[m][n];
} 
int main() 
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    int lcsLength = lcs(X, Y, m, n);
    printf("Length of Longest Common Subsequence: %d\n", lcsLength);
return 0;
}