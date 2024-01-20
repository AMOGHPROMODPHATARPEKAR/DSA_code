#include<iostream>
#define m  1000000007
#include <vector>
using namespace std;
long long int solveMem(int n,vector<int>&dp)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }

    dp[n] = ((n-1)%m*((solveMem(n-2,dp))%m+(solveMem(n-1,dp))%m)%m)%m;
    return dp[n];
}
long long solveTab(int n)
{
    vector<long long int>dp(n+1,-1);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        dp[i] =((i-1)%m*((dp[i-2])%m+(dp[i-1])%m)%m)%m;
    }
    return dp[n];
}
long long solve3(int n)
{
    long long int prev2=0;
    long long int prev1=1;
    for(int i=3;i<=n;i++)
    {
        int ans =((i-1)%m*((prev1)%m+(prev2)%m)%m)%m;
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
long long int countDerangements(int n) {

    vector<int>dp(n+1,-1);
    return solveMem(n,dp);
    
}

int main()
{
    int n=5;
    cout<<"number of de-arrangements by rec+mem: "<<countDerangements(n)<<endl;
    cout<<"number of de-arrangements by tab : "<<solveTab(n)<<endl;
    cout<<"number of de-arrangements by space opt : "<<solve3(n)<<endl;
    
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