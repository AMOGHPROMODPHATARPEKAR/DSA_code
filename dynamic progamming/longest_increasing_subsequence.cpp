int solve(int n, int a[],int cur,int prev)
    {
        //base case
        if(cur == n)
            return 0;
        
        //include
        int take=0;
        if(prev == -1 || a[cur]>a[prev])
            take=1+solve(n,a,cur+1,cur);
        
        //exclude
        int notTake = solve(n,a,cur+1,prev);
        
        return max(take,notTake);
    }
    int solveMem(int n, int a[],int cur,int prev,vector<vector<int>>&dp)
    {
        //base case
        if(cur == n)
            return 0;
        
        if( dp[cur][prev+1] != -1)
        {
            return  dp[cur][prev+1];
        }
        
        //include
        int take=0;
        if(prev == -1 || a[cur]>a[prev])
            take=1+solveMem(n,a,cur+1,cur,dp);
        
        //exclude
        int notTake = solveMem(n,a,cur+1,prev,dp);
        
        dp[cur][prev+1] =  max(take,notTake);
        return dp[cur][prev+1];
    }
    int solveTab(int n, int a[])
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        
        for(int cur=n-1;cur>=0;cur--)
        {
            for(int prev=cur-1;prev>=-1;prev--)
            {
                 //include
                int take=0;
                if(prev == -1 || a[cur]>a[prev])
                    take=1+dp[cur+1][cur+1];
                
                //exclude
                int notTake = dp[cur+1][prev+1];
                
                dp[cur][prev+1] =  max(take,notTake);
            }
        }
        
       
        return dp[0][0];
    }
    int solveOp(int n, int a[])
    {
        vector<int>curRow(n+1,0);
        vector<int>nextRow(n+1,0);
        
        for(int cur=n-1;cur>=0;cur--)
        {
            for(int prev=cur-1;prev>=-1;prev--)
            {
                 //include
                int take=0;
                if(prev == -1 || a[cur]>a[prev])
                    take=1+nextRow[cur+1];
                
                //exclude
                int notTake = nextRow[prev+1];
                
                curRow[prev+1] =  max(take,notTake);
            }
            nextRow=curRow;
        }
        
       
        return nextRow[0];
    }
    
    //dp with binary search
    int solveOptimal(int n,int a[])
    {
        if(n==0)
            return 0;
        
        vector<int>ans;
        ans.push_back(a[0]);
        
        for(int i=1;i<n;i++)
        {
            if(a[i]>ans.back())
            {
                ans.push_back(a[i]);
            }else
            {
                int index = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
                ans[index] =a[i];
            }
        }
        
        return ans.size();
        
    }
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       
    //   return solve(n,a,0,-1);
    //   vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //   return solveMem(n,a,0,-1,dp);
    
    // return solveTab(n,a);
    // return solveOp(n,a);
    return solveOptimal(n,a);
       
    }

    // TC -O(n2) SC-O(n2) for rec+mem and tab
    // sc-O(n) for space optimize
    // TC for dp with binary is O(n*(nlogn)) and SC -O(n)