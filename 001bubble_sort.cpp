#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>

using namespace std;

void swap(int *m, int *n)
{
    int t = *m;
    *m = *n;
    *n = t;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    clock_t start, end;
    start = clock();
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j], &arr[j]);
            }
        }
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
        bubbleSort(arr, n);

        //AVERAGE
        for(int i=0;i<n;i++)
        {
            arr[i] = rand()%n;
        }
        cout<<"\n>>Average Case\n";
        bubbleSort(arr, n);

        //WORST
        int x = n;
        for(int i=0;i<n;i++)
        {
            arr[i] = x;
            x = x-1;
        }
        cout<<"\n>>Worst Case\n";
        bubbleSort(arr, n);
    }

    return 0;
}
