#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#define CLOCKS_PER_SEC ((clock_t)(1000))

using namespace std;

void swap(int *m, int *n)
{
    int t = *m;
    *m = *n;
    *n = t;
}

void insertionSort(int arr[], int n)
{
    int i, j;
    clock_t start, end;
    start = clock();
    for (i = 0; i < n; i++)
    {
        int arrVal = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > arrVal)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = arrVal;
    }
    end = clock();
    cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";
}

int main()
{
    int n;
    cout << "Enter the size of Array(preferred sizes- 5000, 10000, 15000): ";
    cin >> n;
    cout << "\n";
    if (n < 1)
    {
        cout << "Try next time!";
    }
    else
    {
        int arr[n];
        //BEST
        for (int i = 0; i < n; i++)
        {
            arr[i] = i;
        }
        cout << ">>Best Case\n";
        insertionSort(arr, n);

        //AVERAGE
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % n;
        }
        cout << "\n>>Average Case\n";
        insertionSort(arr, n);

        //WORST
        int x = n;
        for (int i = 0; i < n; i++)
        {
            arr[i] = x;
            x = x - 1;
        }
        cout << "\n>>Worst Case\n";
        insertionSort(arr, n);
    }
    getch();
    
    return 0;
}
