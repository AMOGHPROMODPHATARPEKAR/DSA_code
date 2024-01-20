#include <bits/stdc++.h>
using namespace std;
int solveMem(vector<int> cost, int n, vector<int> &dp)
{
    // base case
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }
    // step3

    if (dp[n] != -1)
    {
        return dp[n];
    }

    // step2
    dp[n] = cost[n] + min(solveMem(cost, n - 1, dp), solveMem(cost, n - 2, dp));
    return dp[n];
}
int min_climb(vector<int> cost)
{
    int n = cost.size();
    // Step1
    vector<int> dp(n + 1, -1);
    int ans = min(solveMem(cost, n - 1, dp), solveMem(cost, n - 2, dp));
    return ans;
}
int solveTab(vector<int> cost, int n)
{
    // step1
    vector<int> dp(n + 1, -1);

    // step2:base case analysis
    dp[0] = cost[0];
    dp[1] = cost[1];

    //step3 : rest of all

    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);

}

int solve3(vector<int> cost, int n)
{
   
    // step1:base case analysis
    int prev2 = cost[0];
    int prev1 = cost[1];

    
    for (int i = 2; i <n; i++)
    {
        int cur = cost[i] + min(prev1,prev2);
        prev2 = prev1;
        prev1= cur;
    }

    return min(prev1,prev2);
}
int main()
{
    vector<int> cost = {10, 15, 20,40};
    // cout << min_climb(cost);
    // cout<<solveTab(cost,cost.size());
    cout<<solve3(cost,cost.size());
}

// REC+MEM
// TC:O(N)
// SC:O(n)+O(N)

// TAB
// TC:O(N)
// SC:O(n)

// SPACE
// TC:O(N)
// SC:O(1)
