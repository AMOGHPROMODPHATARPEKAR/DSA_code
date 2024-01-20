int solve(vector<int>& obs,int curpos,int curlan)
    {
        if(curpos == obs.size()-1)
            return 0;
        
        

        if(obs[curpos+1] != curlan)
        {
            return solve(obs,curpos+1,curlan);
        }else
        {
            //sideways jump
            int ans = INT_MAX;
            for(int i=1;i<=3;i++)
            {
                if(curlan != i && obs[curpos] != i)
                {
                    ans = min(ans,1+solve(obs,curpos,i));
                }
            }
                
                return ans;
        }

    }
    int solveMem(vector<int>& obs,int curpos,int curlan,vector<vector<int>>&dp)
    {
        if(curpos == obs.size()-1)
            return 0;
        
        if(dp[curlan][curpos] != -1)
        {
            return dp[curlan][curpos];
        }

        if(obs[curpos+1] != curlan)
        {
            return solveMem(obs,curpos+1,curlan,dp);
        }else
        {
            //sideways jump
            int ans = INT_MAX;
            for(int i=1;i<=3;i++)
            {
                if(curlan != i && obs[curpos] != i)
                {
                    ans = min(ans,1+solveMem(obs,curpos,i,dp));
                }
            }
            dp[curlan][curpos]= ans;
               return dp[curlan][curpos];
        }
    }
    int solveTab(vector<int>& obs)
    {
        
        int n=obs.size()-1;
        vector<vector<int>>dp(4,vector<int>(obs.size(),1e9));

        //base case analyysis
        dp[0][n]=0;
        dp[1][n]=0;
        dp[2][n]=0;
        dp[3][n]=0;

        for(int curpos=n-1;curpos>=0;curpos--)
        {
            for(int curlan=1;curlan<=3;curlan++)
            {
                if(obs[curpos+1] != curlan)
                {
                    dp[curlan][curpos] = dp[curlan][curpos+1];
                }else
                {
                    //sideways jump
                    int ans = 1e9;
                    for(int i=1;i<=3;i++)
                    {
                        if(curlan != i && obs[curpos] != i)
                        {
                            ans = min(ans,1+dp[i][curpos+1]);
                        }
                    }
                    dp[curlan][curpos]= ans;
                }
            }
        }
        
        return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
    }
    int solveOp(vector<int>& obs)
    {
        
        int n=obs.size()-1;
        vector<int>cur(4,INT_MAX);
        vector<int>next(4,0);//base case covered here

       

        for(int curpos=n-1;curpos>=0;curpos--)
        {
            for(int curlan=1;curlan<=3;curlan++)
            {
                if(obs[curpos+1] != curlan)
                {
                    cur[curlan] = next[curlan];
                }else
                {
                    //sideways jump
                    int ans = 1e9;
                    for(int i=1;i<=3;i++)
                    {
                        if(curlan != i && obs[curpos] != i)
                        {
                            ans = min(ans,1+next[i]);
                        }
                    }
                    cur[curlan]= ans;
                }
            }
            next=cur;
        }
        
        return min(next[2],min(1+next[1],1+next[3]));
    }
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        // return solve(obstacles,0,2);

        // vector<vector<int>>dp(4,vector<int>(n,-1));
        // return solveMem(obstacles,0,2,dp);

        // return solveTab(obstacles);
        return solveOp(obstacles);
    }