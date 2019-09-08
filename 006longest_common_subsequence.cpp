#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void lcs(char *A, char *B, int m, int n)
{
    int L[m + 1][n + 1];
    // Creating table
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (A[i - 1] == B[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1; // upper left diagonal value + 1
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); // Max of left and top digit
        }
    }

    int index = L[m][n];
    char outString[index + 1]; // LCS string
    outString[index] = '\0';   // C++ char array rules: It ends with \0 null character.
    int i = m, j = n;          // Backtrack
    while (i > 0 && j > 0)
    {
        // On same character
        if (A[i - 1] == B[j - 1])
        {
            outString[index - 1] = A[i - 1];
            i--;
            j--;
            index--;
        }
        // In direction of Max of left and top digit
        else if (L[i - 1][j] > L[i][j - 1]) // Move Up
            i--;
        else // Move left
            j--;
    }
    cout << "\nLength of LCS: " << L[m][n] << "\nLongest Common Subsequence(LCS): " << outString;
}

int main()
{
    char stringA[] = "NISHANT";
    char stringB[] = "SHAEQT";
    int m = strlen(stringA), n = strlen(stringB);
    lcs(stringA, stringB, m, n);

    return 0;
}
