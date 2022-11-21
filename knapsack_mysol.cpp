// dp

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    int m = 8;
    int p[5] = {0, 1, 2, 5, 6};
    int wt[5] = {0, 2, 3, 4, 5};
    int k[5][9];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            if (i == 0 || w == 0)
            {
                k[i][w] = 0;
            }
            else if (wt[i] <= w)
            {
                k[i][w] = max(p[i] + k[i - 1][w - wt[i]], k[i - 1][w]);
            }
            else
            {
                k[i][w] = k[i - 1][w];
            }
        }
    }

    // cout << k[n][m];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << k[i][j] << "  ";
        }
        cout << endl;
    }

    int i = n;
    int j = m;

    while (i > 0 && j >= 0)
    {
        if (k[i][j] == k[i - 1][j])
        {
            cout << i << " = 0 ";
            i--;
        }
        else
        {
            cout << i << " = 1 ";
            j = j - wt[i];
            i--;
        }
    }
}