#include <stdio.h>
#include <limits.h>
int min(int a, int b)
{
    return (a < b) ? a : b;
} 
int minCoins(int coins[], int n, int amount)
{
    int dp[amount + 1];
    for(int i = 0; i <= amount; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                int subproblem = dp[i - coins[j]];
                if(subproblem != INT_MAX && subproblem + 1 < dp[i])
                {
                    dp[i] = subproblem + 1;
                }
            }
        }
    }
return dp[amount];
} 
int main() 
{ 
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount;
    printf("Enter the amount to make change for: ");
    scanf("%d", &amount);
    int minCoinsNeeded = minCoins(coins, n, amount);
    printf("Minimum number of coins needed: %d\n", minCoinsNeeded);
return 0;
}