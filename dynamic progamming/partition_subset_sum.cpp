    int solve(int index,int n,int a[],int target)
    {
        if(index >=n)
            return 0;
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        
        int incl = solve(index+1,n,a,target - a[index]);
        int excl = solve(index+1,n,a,target);
        
        return (incl || excl);
    }
    int solveMem(int index,int n,int a[],int target,vector<vector<int>>&dp)
    {
        if(index >=n)
            return 0;
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        
        if(dp[index][target] != -1)
        {
            return dp[index][target];
        }
        
        int incl = solveMem(index+1,n,a,target - a[index],dp);
        int excl = solveMem(index+1,n,a,target,dp);
        
        return dp[index][target] = (incl || excl);
    }
    
    int solveTab(int n,int a[],int t)
    {
        vector<vector<int>>dp(n+1,vector<int>(t+1,0));
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int index=n-1;index>=0;index--)
        {
            for(int target = 0;target <= t;target++)
            {
                 int incl=0;
                 if(target - a[index] >=0)
                    incl= dp[index+1][target - a[index]];
                    
                int excl = dp[index+1][target];
                
                dp[index][target] = (incl || excl);
            }
        }
        
        return dp[0][t];
    }
    int solveOp(int n,int a[],int t)
    {
        vector<int>cur(t+1,0);
        vector<int>next(t+1,0);
        
        
        
            cur[0]=1;
            next[0]=1;

        
        for(int index=n-1;index>=0;index--)
        {
            for(int target = 0;target <= t;target++)
            {
                 int incl=0;
                 if(target - a[index] >=0)
                    incl= next[target - a[index]];
                    
                int excl = next[target];
                
                cur[target] = (incl || excl);
            }
            next =cur;
        }
        
        return next[t];
    }
    
    int equalPartition(int N, int arr[])
    {
        int total=0;
        for(int i=0;i<N;i++)
        {
            total+=arr[i];
        }
        if(total & 1)
            return 0;
        
        int target = total/2;
        
        // return  solve(0,N,arr,target);
        // vector<vector<int>>dp(N,vector<int>(target+1,-1));
        // return solveMem(0,N,arr,target,dp);
        
        // return solveTab(N,arr,target);
        return solveOp(N,arr,target);
    }