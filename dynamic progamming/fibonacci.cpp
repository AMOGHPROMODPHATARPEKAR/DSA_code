#include<bits/stdc++.h>
using namespace std;

//METHOD 1:TOP DOWN APPROACH - RECURSION + MEMOIZATION
int fib(int n,vector<int>&dp)
{
         if(n==0 || n==1)
  return n;
  //step3: return the stored value
  if(dp[n] != -1)
  {
return dp[n];
  }
 //step2: store value
   dp[n] = fib(n-1,dp)+fib(n-2,dp);
   return dp[n];
}
//METHOD2 - TABULATION
int fib2(int n){
    //step1
    vector<int>dp(n+1,-1);

    //step2 - base cases
    dp[0] = 0;
    dp[1] =1;

    for(int i =2 ;i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
//space optimized fib 
int fib3(int n)
{
    int prev1=1;
    int prev2 =0;
    if(n == 0)
    {
     return prev2;
    }

    for(int i=2;i<=n;i++)
    {
        int cur = prev1+prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;

}
int main()
{
      int n;
      cin>>n;
     //step1:create a dp array
      vector<int>dp(n+1,-1);
      cout<<"fib series is\n";
    for(int i=0;i<=n;i++)
    cout << fib3(i)<<" ";
      return 0; 
}
//method 1
// TC :O(N)
// SC :O(N)+O(N) =O(N)

//method 2
// TC :O(N)
// SC :O(N)

//method 3
// TC :O(N)
// SC :O(1)