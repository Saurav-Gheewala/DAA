#include <stdio.h>
#include <stdlib.h>
struct Item
{
    int value;
    int weight;
};
int compare(const void *a, const void *b)
{
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    double ratio1 = (double)item1->value / item1->weight;
    double ratio2 = (double)item2->value / item2->weight;
    if (ratio1 > ratio2)
        return -1;
    else if (ratio1 < ratio2)
        return 1;
    else
        return 0;
}
double grdysac(int capacity, struct Item items[], int n)
{
    qsort(items, n, sizeof(struct Item), compare);
    int curwght = 0;
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) 
    {
        if (curwght + items[i].weight <= capacity)
        {
            curwght += items[i].weight;
            totalValue += items[i].value;
        } 
        else 
        {
            int remcap = capacity - curwght;
            totalValue += (double)remcap * items[i].value / items[i].weight;
            break;
        }    
    } 
return totalValue;
} 
int main() 
{
    int capacity = 50;
    struct Item items[] =
    {
        {60, 10},
        {100, 20},
        {120, 30},
    };
    int n = sizeof(items) / sizeof(items[0]);
    double maxValue = grdysac(capacity, items, n);
    printf("Maximum value in the knapsack: %.2lf\n", maxValue);
return 0;
}