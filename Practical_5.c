#include <stdio.h>
#include<sys/time.h>
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        } 
        else 
        {
            arr[k] = R[j];
            j++;    
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;    
    }
}
void mergesrt(int arr[], int left, int right)
{
    if (left < right) 
    {
    int mid = left + (right - left) / 2;
    mergesrt(arr, left, mid);
    mergesrt(arr, mid + 1, right);
    merge(arr, left, mid, right);
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
        arr[i] = rand()%10000; 
    }
    gettimeofday(&tv , &t2);
    t1 = tv.tv_usec;
    mergesrt(arr , size);
    gettimeofday(&tv , &t2);
    t2 = tv.tv_usec
    times = t2 - t1;
    ti = (double)times/1000000;
    printArray(arr , size);
    printf("Time Is Equal To %d" , ti);
return 0;
}