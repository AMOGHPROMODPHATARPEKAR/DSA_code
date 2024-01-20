#include <bits/stdc++.h>
using namespace std;
int solveMem(vector<int> &num, int n, vector<int> &dp)
{
    // base case
    if (n < 0)
        return 0;

    if (n == 0)
        return num[0];

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int incl = solveMem(num, n - 2, dp) + num[n];
    int excl = solveMem(num, n - 1, dp) + 0;

    dp[n] = max(incl, excl);
    return dp[n];
}

int solvetab(vector<int> &num)
{
    int n = num.size();
    vector<int> dp(n, 0);
    dp[-1] =0;
    dp[0] = num[0];
     
    for (int i = 1; i < n; i++)
    {
    
        int  incl = dp[i - 2] + num[i];
        int excl = dp[i - 1] + 0;
        dp[i] = max(incl, excl);
    }

    return dp[n - 1];
}


int solve3(vector<int> &num)
{
    int n = num.size();

    int prev2 = 0;
    int prev1 = num[0];

    for (int i = 1; i < n; i++)
    {
        int incl =prev2+ num[i];

        int excl = prev1 + 0;
        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}
int houseRobber(vector<int>& valueInHouse)
{
    
    int n = valueInHouse.size();
    if(n == 1)
    {
        return valueInHouse[0];
    }

    vector<int>first,last;

    for(int i=0;i<n;i++)
    {
        if(i!= n-1)
        {
            first.push_back(valueInHouse[i]);
        }
        if(i !=0)
        {
            last.push_back(valueInHouse[i]);
        }
    }

    return max(solve3(first),solve3(last));

}

int main()
{
    vector<int> a = {2,1, 3, 5};
    cout<<"Maximun sum of non adjacent that robber took : "<<houseRobber(a)<<endl;

}

// REC+MEM
// TC:O(N)
// SC:O(N)+O(N)

// TAB
// TC:O(N)
// SC:O(N)

// SPACE OPT
// TC:O(N)
// SC:O(1)
