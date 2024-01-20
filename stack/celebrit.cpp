#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;
    // step1 push all element
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // step2

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (M[a][b] == 1)
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int candidate = s.top();
    // step3: single element is potential candidate
    // verify
    bool rowcheck = false;
    int zerocount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[candidate][i] == 0)
        {
            zerocount++;
        }
    }
    if (zerocount == n)
    {
        rowcheck = true;
    }

    bool colcheck = false;
    int onecount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][candidate] == 1)
        {
            onecount++;
        }
    }
    if (onecount == n - 1)
    {
        colcheck = true;
    }

    if (rowcheck == 1 && colcheck == 1)
    {
        return candidate;
    }
    else
    {
        return -1;
    }
}
int main()
{
    vector<vector<int>> arr = {{0, 1, 0},{ 0, 0, 0}, {0, 1, 0}};
    int ans = celebrity(arr, 3);
    cout << " the celebrity is " << ans;
}