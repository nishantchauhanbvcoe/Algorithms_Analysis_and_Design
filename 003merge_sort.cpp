#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m-l+1, n2 = r-m;
    int l_arr[n1], r_arr[n2];

    // Dividing array into two subarrays
    for(i=0;i<n1;i++)
    {
        l_arr[i] = arr[l+i];
    }
    for(j=0;j<n2;j++)
    {
        r_arr[j] = arr[m+j+1];
    }

    i = 0;
    j = 0;
    k = l;
    while(i<n1 && j<n2)
    {
        if(l_arr[i] <= r_arr[j])
        {
            arr[k] = l_arr[i];
            i++;
        }
        else
        {
            arr[k] = r_arr[j];
            j++;
        }
        k++;
    }

    // If any element of arrays are left
    while(i < n1)
    {
        arr[k] = l_arr[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = r_arr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int m = l + (r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
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
        clock_t start, end;
        int arr[n];
        //BEST
        for(int i=0;i<n;i++)
        {
            arr[i] = i;
        }
        cout<<">>Best Case\n";
        start = clock();
        mergeSort(arr, 0, n);
        end = clock();
        cout<<"Time taken: "<<(double)(end - start)/CLOCKS_PER_SEC<<"\n";

        //AVERAGE
        for(int i=0;i<n;i++)
        {
            arr[i] = rand()%n;
        }
        cout<<"\n>>Average Case\n";
        start = clock();
        mergeSort(arr, 0, n);
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
        mergeSort(arr, 0, n);
        end = clock();
        cout<<"Time taken: "<<(double)(end - start)/CLOCKS_PER_SEC<<"\n";
    }

    return 0;
}
