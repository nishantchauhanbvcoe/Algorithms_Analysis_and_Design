#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

using namespace std;

void chainOutput(int s[7][7], int i, int j)
{
    if (i == j)
        cout << " A" << i;
    else
    {
        cout << "(";
        chainOutput(s, i, s[i][j]);
        chainOutput(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void matrixchain(int p[], int m[7][7], int s[7][7], int n)
{
    int i, j, k, l, q;
    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = 99999;
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j] && q>0)
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

int main()
{
    // Matrix is considered from 1 to 6, not 0 to 6.
    int m[7][7], s[7][7];
    int n = 6;
    int p[7] = {30,35,15,5,10,20,25};
    matrixchain(p, m, s, n);

    // Printing Cost Matrix
    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j <7; j++)
        {
            if (i > j)
                cout << "_\t";
            else
                cout << m[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n\n";

    // Printing s Matrix
    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            if (i >= j)
                cout << "_\t";
            else
                cout << s[i][j] << "\t";
        }
        cout << "\n";
    }

    cout<<"\nOrder: ";
    chainOutput(s, 1, n);
    return 0;
}
