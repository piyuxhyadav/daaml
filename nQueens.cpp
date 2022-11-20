#include <bits/stdc++.h>
using namespace std;

int n;
int queen[20];

bool check(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int prow = i;
        int pcol = queen[i];

        if (pcol == col || abs(row - prow) == abs(col - pcol))
        {
            return 0;
        }
    }
    return 1;
}

int rec(int level)
{

    if (level == n)
    {
        int i = 0;
        int j = 0;
        cout << "[";
        for (int i = 0; i < n; i++)
        {
            if (queen[i] != -1)
            {
                cout << "(" << i << "," << queen[i] << ")";
            }
        }
        cout << "]" << endl;
        return 1;
    }

    // solve
    int ans = 0;
    for (int col = 0; col < n; col++)
    {

        if (check(level, col))
        {
            queen[level] = col;

            ans += rec(level + 1);
            queen[level] = -1;
        }
    }

    // return
    return ans;
}

int main()
{
    cin >> n;
    memset(queen, -1, sizeof(queen));
    cout << rec(0);
}