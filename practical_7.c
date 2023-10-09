#include <stdio.h>
void makeChange(int coins[], int n, int amount)
{
    int count = 0;
    for (int i = 0; i < n; i++) 
    {
        while (amount >= coins[i]) 
        {
            amount -= coins[i];
            count++;
        }
    }
    printf("Minimum number of coins needed: %d\n", count);
} 
int main() 
{
    int coins[] = {25, 10, 5, 1};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount;
    printf("Enter the amount to make change for: ");
    scanf("%d", &amount);
    makeChange(coins, n, amount);
return 0;
}