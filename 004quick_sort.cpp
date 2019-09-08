#include<iostream>
#include<stdlib.h>
#include <conio.h>
#include<stdio.h>
#include<time.h>

using namespace std;

void swap(int *m, int *n)
{
    int t = *m;
    *m = *n;
    *n = t;
}

// Last value of array chosen as PIVOT
int partition(int arr[], int l, int r)
{
    int i, j, pivot;
    // 'j' will keep account of the large value with which
    // we have to exchange next smaller value than pivot.
    j = l-1;
    i = l;
    pivot = arr[r];
    for(i; i<=r-1; i++)
    {
        // Its not (arr[i] > pivot) because we wait for
        // the next smaller value to exchange with it.
        if(arr[i] < pivot)
        {
            j++;
            swap(&arr[j], &arr[i]);
        }
    }
    // At last, Exchange pivot value(or in this case 'the last value')
    // with the value greater than it.
    swap(&arr[j+1], &arr[r]);
    return j+1;
}

void quickSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int pivotIndex = partition(arr, l, r);

        quickSort(arr, l, pivotIndex-1);
        quickSort(arr, pivotIndex+1, r);
    }
}

int main()
{
    // // TESTING
    // int arr[] = {5,1,9,4,7,3,8,6};
    // int arrSize = sizeof(arr)/sizeof(arr[0]);
    // cout<<"Last Element: "<<arr[arrSize-1];
    // quickSort(arr, 0, arrSize-1);
    // for(int i=0; i<arrSize; i++)
    // {
    //     cout<<"\n"<<"Element "<<i<<": "<<arr[i];
    // }

    int n;
    cout<<"Enter the size of Array(preferred sizes- 5000, 10000, 15000): ";
    cin>>n;
    cout<<"\n";
    if(n<1)
    {
        cout<<"Try next time!";
    }
    else
    {
        clock_t start, end;
        int arr[n];
        //BEST
        for(int i=0;i<n;i++)
        {
            arr[i] = i;
        }
        cout<<">>Best Case\n";
        start = clock();
        quickSort(arr, 0, n-1);
        end = clock();
        cout<<"Time taken: "<<(double)(end - start)/CLOCKS_PER_SEC<<"\n";

        //AVERAGE
        for(int i=0;i<n;i++)
        {
            arr[i] = rand()%n;
        }
        cout<<"\n>>Average Case\n";
        start = clock();
        quickSort(arr, 0, n-1);
        end = clock();
        cout<<"Time taken: "<<(double)(end - start)/CLOCKS_PER_SEC<<"\n";

        //WORST
        int x = n;
        for(int i=0;i<n;i++)
        {
            arr[i] = x;
            x = x-1;
        }
        cout<<"\n>>Worst Case\n";
        start = clock();
        quickSort(arr, 0, n-1);
        end = clock();
        cout<<"Time taken: "<<(double)(end - start)/CLOCKS_PER_SEC<<"\n";
    }

    return 0;
}
