
    int solve(vector<int>& satisfaction,int index,int time)
    {
        if(index == satisfaction.size())
            return 0;
        
        int incl = satisfaction[index]*(time+1) + solve(satisfaction,index+1,time+1);
        int excl=0+ solve(satisfaction,index+1,time);

        return max(incl,excl);
    }
    int solveMem(vector<int>& satisfaction,int index,int time,vector<vector<int>>&dp)
    {
        if(index == satisfaction.size())
            return 0;
        
        if(dp[index][time] != -1)
        {
            return dp[index][time];
        } 

        int incl = satisfaction[index]*(time+1) + solveMem(satisfaction,index+1,time+1,dp);
        int excl=0+ solveMem(satisfaction,index+1,time,dp);

        dp[index][time]=max(incl,excl);
        return dp[index][time];
    }
    
    int solveTab(vector<int>& satisfaction)
    {
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int index=n-1;index>=0;index--)
        {
            for(int time=index;time>=0;time--)
            {
                int incl = satisfaction[index]*(time+1) + dp[index+1][time+1];
                int excl=0+ dp[index+1][time];

                dp[index][time]=max(incl,excl);
            }
        }

        
        return dp[0][0];
    }
    int solveOP(vector<int>& satisfaction)
    {
        int n=satisfaction.size();
        vector<int>cur(n+1,0);
        vector<int>next(n+1,0);

        for(int index=n-1;index>=0;index--)
        {
            for(int time=index;time>=0;time--)
            {
                int incl = satisfaction[index]*(time+1) + next[time+1];
                int excl=0+ next[time];

                cur[time]=max(incl,excl);
            }
            next=cur;
        }

        
        return next[0];
    }
    int solveOP2(vector<int>& satisfaction)
    {
        int n=satisfaction.size();
        vector<int>next(n+1,0);

        for(int index=n-1;index>=0;index--)
        {
            for(int time=0;time<=index;time++)
            {
                int incl = satisfaction[index]*(time+1) + next[time+1];
                int excl=0+ next[time];

                next[time]=max(incl,excl);
            }
        }

        
        return next[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        // return solve(satisfaction,0,0);
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solveMem(satisfaction,0,0,dp);

        // return solveTab(satisfaction);
        // return solveOP(satisfaction);
        return solveOP2(satisfaction);
    }

rec+mem TC  O(N2) sc O(n2)
tab TC O(N2) sc O(n2)
space opt TC O(N2) sc O(n)