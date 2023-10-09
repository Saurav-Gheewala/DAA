#include <stdio.h>
int seqsea(int arr[], int n, int key)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == key)
                return i;
        } 
    return -1;
} 
int binsrch(int arr[], int l, int r, int key)
{
    if (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return binsrch(arr, l, mid - 1, key);
        else
            return binsrch(arr, mid + 1, r, key);
    } 
    return -1;
} 
int biniter(int arr[], int n, int key)
{
    int l = 0;
    int r = n - 1;
    while (l <= r) 
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            r = mid - 1;
        else
            l = mid + 1;
    } 
    return -1;
}
int main() 
{
    int arr[20000];
    double ti;
    int i,j,size,t1,t2,times,l,r;
    struct timeval tv;
    struct timezone tz;
    printf("Enter Size: ");
    scanf("%d", &size);
    int *arr = (lnt *)malloc (size * (sizeof (int));
    for(int i = 0; i < size ; i++)
    {
        arr[i] = i + 1;

    }
    printf("Enter element to find ");
    scanf("%d",&key);
    l = 0;
    r = size - 1;
    gettimeofday(&tv , &t2);
    t1 = tv.tv_usec;
    int x = binsrch(arr , size , 5);
    gettimeofday(&tv , &t2);
    t2 = tv.tv_usec
    times = t2 - t1;
    ti = (double)times/1000000;
    printf("Time Is %d", ti);
    if(x == -1)
        printf("Element Not Found ");
    else    
        printf("Found At Place %d" ,x)
    return 0;
}