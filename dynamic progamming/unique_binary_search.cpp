int solve(int n)
    {
        if(n<=1)
            return 1;
        
        int ans=0;
        //all nodes to be root
        for(int i=1;i<=n;i++)
        {
            ans += (solve(i-1) * solve(n-i));
        }
        return ans;
    }
    int solveMem(int n,vector<int>&dp)
    {
        if(n<=1)
            return 1;
        
        if(dp[n] != -1)
        {
            return dp[n];
        }

        int ans=0;
        //all nodes to be root
        for(int i=1;i<=n;i++)
        {
            ans += (solve(i-1) * solve(n-i));
        }
        return dp[n]= ans;
    }
    int solveTab(int n)
    {
        vector<int>dp(n+1,0);
        dp[0]=dp[1] =1;

    
        //i_> numsber of node
        for(int i=2;i<=n;i++)
        {
            //j->root node
            for(int j=1;j<=i;j++)
            {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }

        return dp[n];
    }
    int catalan(int n,int k)
    {
         long res=1;
        if(k>n-k)
            k=n-k;             //Since Ci(n,k)=Ci(n,n-k), property of binomial coefficients
        for(int i=0;i<k;i++)
        {
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }
    int numTrees(int n) {
        // return solve(n);
        // vector<int>dp(n+1,-1);
        // return solveMem(n,dp);
        return solveTab(n);

        //direct solution catalan number (2n)! / ((n + 1)! n!)
    return catalan(2*n,n) / n+1;
    }