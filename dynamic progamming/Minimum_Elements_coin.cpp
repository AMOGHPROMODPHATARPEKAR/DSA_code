#include <bits/stdc++.h>
using namespace std;
int solveMem(vector<int> &num, int x, vector<int> &dp)
{
    // base case
    if (x == 0)
    {
        return 0;
    }
    if (x < 0)
    {
        return INT_MAX;
    }
    if (dp[x] != -1)
    {
        return dp[x];
    }
    int mini = INT_MAX;

    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveMem(num, x - num[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    dp[x] = mini;
    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x + 1, -1);
    int ans = solveMem(num, x, dp);
    if (ans == INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int solvetab(vector<int> &num, int x)
{
    vector<int>dp(x+1,INT_MAX);
    dp[0] = 0;

    for(int i=1;i<=x;i++)
    {
        //find amount for 1 TO x

        for(int j=0;j<num.size();j++)
        {
            if(i-num[j]>=0 && dp[i-num[j]] != INT_MAX)
            {
                dp[i] = min(dp[i],1+dp[i-num[j]]);
            }
        }
    }
    if(dp[x] == INT_MAX)
    {
        return -1;
    }
    return dp[x];

}

int main()
{
    vector<int> a ={1,2,3};
    // cout<<"MIN coin req is "<<minimumElements(a,3)<<endl;
    cout<<"MIN coin req is "<<solvetab(a,10)<<endl;
    
}

// REC+MEM
// TC:X*n
// SC:O(X)

// TAB
// TC:X*n
// SC:O(X)
