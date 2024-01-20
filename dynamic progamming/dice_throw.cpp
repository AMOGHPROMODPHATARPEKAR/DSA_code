  long long solve(int dice, int face, int target,int sum)
{
//   if(target < 0)
//   {
//       return 0;
//   }
//   if(dice == 0 && target !=0)
//   {
//       return 0;
//   }
//   if(dice !=0 && target == 0)
//   {
//       return 0;
//   }
    // if(dice == 0 && target == 0)
    //     return 1;
   if(dice == 0 )
   {
       if(target == sum)
       {
           return 1;
       }
       return 0;
   }

    long long ans=0;
    for(int i=1;i<=face;i++)
    {
        ans+=solve(dice -1,face,target,sum+i);
    }
    return ans;
}

  long long solveMem(int dice, int face, int target,int sum,vector<vector<long long>>&dp)
{
//   if(target < 0)
//   {
//       return 0;
//   }
//   if(dice == 0 && target !=0)
//   {
//       return 0;
//   }
//   if(dice !=0 && target == 0)
//   {
//       return 0;
//   }
//   if(dice == 0 && target == 0)
//     return 1;

     if(sum > target)
        return 0;
  if(dice == 0 )
  {
      if(target == sum)
      {
          return 1;
      }
      return 0;
  }
    if(dp[dice][sum] !=-1)
    {
        return dp[dice][sum];
    }
    long long ans=0;
    for(int i=1;i<=face;i++)
    {
        ans+=solveMem(dice -1,face,target,sum+i,dp);
    }
    return dp[dice][sum]=ans;
}

long long solveTab(int d,int f,int t)
{
    vector<vector<long long>>dp(d+1,vector<long long>(t+1,0));
    dp[0][0]=1;
    
    for(int dice =1;dice<=d;dice++)
    {
        for(int target = 1;target <=t ;target++)
        {
            long long ans=0;
            for(int i=1;i<=f;i++)
            {
                if(target -i >=0)
                    ans+=dp[dice -1][target-i];
            }
            dp[dice][target]=ans;
        }
    }
    return dp[d][t];
}
long long solveOp(int d,int f,int t)
{
    vector<long long>prev(t+1,0);
    vector<long long>cur(t+1,0);
    
    prev[0]=1;
    
    for(int dice =1;dice<=d;dice++)
    {
        for(int target = 1;target <=t ;target++)
        {
            long long ans=0;
            for(int i=1;i<=f;i++)
            {
                if(target -i >=0)
                    ans+= prev[target-i];
            }
            cur[target]=ans;
        }
    }
    return prev[t];
}

    long long noOfWays(int M , int N , int X) {
        
        // return solve(N,M,X,0);
        
        // vector<vector<long long>>dp(N+1,vector<long long>(X+1,-1));
        // return solveMem(N,M,X,0,dp);
        
        return solveTab(N,M,X);
    }