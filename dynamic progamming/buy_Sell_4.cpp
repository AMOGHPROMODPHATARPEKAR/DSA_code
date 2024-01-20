int solve(int index,int operation,int k,vector<int>&prices)
    {
        if(index == prices.size())
            return 0;
        if(operation == 2*k)
            return 0;

        int profit =0;
        if(operation %2 == 0)
        {
            int buyKaro = -prices[index]+ solve(index+1,operation+1,k,prices);
            int skipKaro = 0+ solve(index+1,operation,k,prices);
            profit = max(buyKaro,skipKaro);
        }
        else
        {
            int sellKaro = prices[index] + solve(index+1,operation+1,k,prices);
            int skipKaro = 0+ solve(index+1,operation,k,prices);
            profit = max(sellKaro,skipKaro);
        }

        return profit;
    }
    int solveMem(int index,int operation,int k,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(index == prices.size())
            return 0;
        if(operation == 2*k)
            return 0;

        if(dp[index][operation] != -1)
        {
            return dp[index][operation];
        }

        int profit =0;
        if(operation %2 == 0)
        {
            int buyKaro = -prices[index]+ solveMem(index+1,operation+1,k,prices,dp);
            int skipKaro = 0+ solveMem(index+1,operation,k,prices,dp);
            profit = max(buyKaro,skipKaro);
        }
        else
        {
            int sellKaro = prices[index] + solveMem(index+1,operation+1,k,prices,dp);
            int skipKaro = 0+ solveMem(index+1,operation,k,prices,dp);
            profit = max(sellKaro,skipKaro);
        }

        return dp[index][operation] = profit;
    }
    int solveTab(int k,vector<int>&prices)
    {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));

        for(int index=n-1;index>=0;index--)
        {
            for(int operation=2*k-1;operation >=0;operation --)
            {
                int profit =0;
                if(operation %2 == 0)
                {
                    int buyKaro = -prices[index]+dp[index+1][operation+1];
                    int skipKaro = 0+ dp[index+1][operation];
                    profit = max(buyKaro,skipKaro);
                }
                else
                {
                    int sellKaro = prices[index] + dp[index+1][operation+1];
                    int skipKaro = 0+ dp[index+1][operation];
                    profit = max(sellKaro,skipKaro);
                }

                dp[index][operation] = profit;
            }
        }

        return dp[0][0];  
    }
    int solveOp(int k,vector<int>&prices)
    {
        int n=prices.size();
        
        vector<int>cur(2*k+1,0);
        vector<int>next(2*k+1,0);

        for(int index=n-1;index>=0;index--)
        {
            for(int operation=2*k-1;operation >=0;operation --)
            {
                int profit =0;
                if(operation %2 == 0)
                {
                    int buyKaro = -prices[index]+next[operation+1];
                    int skipKaro = 0+next[operation];
                    profit = max(buyKaro,skipKaro);
                }
                else
                {
                    int sellKaro = prices[index] + next[operation+1];
                    int skipKaro = 0+next[operation];
                    profit = max(sellKaro,skipKaro);
                }

                cur[operation] = profit;
            }
            next=cur;
        }

        return next[0];  
    }
    int maxProfit(int k, vector<int>& prices) {
        // return solve(0,0,k,prices);
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2*k,-1));
        // return solveMem(0,0,k,prices,dp);
        // return solveTab(k,prices);
        return solveOp(k,prices);
    }

    //based on the no of transaction
    //you can also use buysell3 solution just give limit = k 