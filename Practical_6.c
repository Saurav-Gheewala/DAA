#include <stdio.h>
#include<sys/time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
} 
int part(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot) 
        {      
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
return (i + 1);
}
void qcksrt(int arr[], int low, int high)
{
    if (low < high) 
    {
        int pi = part(arr, low, high);
        qcksrt(arr, low, pi - 1);
        qcksrt(arr, pi + 1, high);
    }
}
void prtarr(int arr[], int n)
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
        arr[i] = rand()%10000; 
    }
    gettimeofday(&tv , &t2);
    t1 = tv.tv_usec;
    qcksrt(arr , 0 , 6);
    gettimeofday(&tv , &t2);
    t2 = tv.tv_usec
    times = t2 - t1;
    ti = (double)times/1000000;
    printArray(arr , size);
    printf("Time Is Equal To %d" , ti);
return 0;
}