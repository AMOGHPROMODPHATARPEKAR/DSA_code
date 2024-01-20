#include <bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(string X, string Y, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            if (j == 0)
                dp[i][j] = i;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
    }
    return (dp[m][n]);
}

int lcs(string a, string b)
{
    vector<int> cur(b.length() + 1, 0);
    vector<int> next(b.length() + 1, 0);

    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = 1 + next[j + 1];
            }
            else
            {
                ans = max(next[j], cur[j + 1]);
            }
            cur[j] = ans;
        }
        next = cur;
    }
    return next[0];
}
int main()
{
    string a = "AGGTAB";
    string b = "GXTXAYB";
    // cout << "length of common supersequence is " << shortestCommonSupersequence(a, b, a.length(), b.length());

    //method 2
    int l =  lcs(a,b);
    cout << "length of common supersequence using lcs : " <<( a.length()+b.length() - l)<<endl;
}