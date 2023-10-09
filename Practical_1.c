#include<stdio.h>
#include<sys/time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
    printf("\n");
} 
int main() 
{
    int arr[20000];
    double ti;
    int i,j,size,t1,t2,times;
    struct timeval tv;
    struct timezone tz;
    printf("Enter Size: ");
    scanf("%d", &size);
    for(i = 0 i < size ; i++)
    {
        arr[i] = rand()%10000; //Average Case
    //  arr[i] = i + 1;        //Best Case
    //  arr[i] = size - 1;     //Worst Case
    }
    gettimeofday(&tv , &t2);
    t1 = tv.tv_usec;
    bubbleSort(arr , size);
    gettimeofday(&tv , &t2);
    t2 = tv.tv_usec
    times = t2 - t1;
    ti = (double)times/1000000;
    printArray(arr , size);
    printf("Time Is Equal To %d" , ti);
return 0;
}