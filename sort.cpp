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

void selectionSort(int arr[], int n)
{
    int i, j, min_index;
    clock_t start, end;
    start = clock();
    for(i=0;i<n-1;i++)
    {
        min_index = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]>arr[min_index])
            {
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
    end = clock();
    cout<<"Time taken: "<<(double)(end - start)/CLOCKS_PER_SEC<<"\n";
}

int main()
{
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
        int arr[n];
        //BEST
        for(int i=0;i<n;i++)
        {
            arr[i] = i;
        }
        cout<<">>Best Case\n";
        selectionSort(arr, n);

        //AVERAGE
        int x = n;
        for(int i=0;i<n;i++)
        {
            arr[i] = x;
            x = x-1;
        }
        cout<<"\n>>Average Case\n";
        selectionSort(arr, n);

        //WORST
        for(int i=0;i<n;i++)
        {
            arr[i] = 0;
        }
        cout<<"\n>>Worst Case\n";
        selectionSort(arr, n);
    }

    return 0;
}
