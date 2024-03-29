int solve(vector<vector<int>> mat,int i,int j,int &maxi)
    {
        if(i>=mat.size() || j>=mat[0].size())
        {
            return 0;
        }
        
        int right=solve(mat,i,j+1,maxi);
        int diagonal = solve(mat,i+1,j+1,maxi);
        int down = solve(mat,i+1,j,maxi);
        
        if(mat[i][j] == 1)
        {
            int ans = 1+min(right,min(diagonal,down));
            maxi=max(maxi,ans);
            return ans;
        }else
        {
            return 0;
        }
        
    }
    int solveMem(vector<vector<int>>&mat,int i,int j,int &maxi,vector<vector<int>>&dp)
    {
        if(i>=mat.size() || j>=mat[0].size())
        {
            return 0;
        }
        
        if(dp[i][j] !=-1)
        {
            return dp[i][j];
        }
        
        int right=solveMem(mat,i,j+1,maxi,dp);
        int diagonal = solveMem(mat,i+1,j+1,maxi,dp);
        int down = solveMem(mat,i+1,j,maxi,dp);
        
        if(mat[i][j] == 1)
        {
            dp[i][j] = 1+min(right,min(diagonal,down));
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
        }else
        {
            return dp[i][j]=0;
        }
        
    }
    int solveTab(vector<vector<int>>&mat,int n,int m,int &maxi)
    {
        //handles the base case
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int right=dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                 if(mat[i][j] == 1)
                {
                dp[i][j] = 1+min(right,min(diagonal,down));
                maxi=max(maxi,dp[i][j]);
                }else
                {
                     dp[i][j]=0;
                 }
            }
        }
        
        
    }
    int solveSOP(vector<vector<int>>&mat,int n,int m,int &maxi)
    {
        //handles the base case
        vector<int>cur(m+1,0);
        vector<int>next(m+1,0);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int right=cur[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                 if(mat[i][j] == 1)
                {
                cur[j] = 1+min(right,min(diagonal,down));
                maxi=max(maxi,cur[j]);
                }else
                {
                    cur[j]=0;
                 }
            }
            next=cur;
        }
        
        
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
      int maxi=0;
    //   vector<vector<int>>dp(n,vector<int>(m,-1));
    //   solve(mat,0,0,maxi);
    // solveMem(mat,0,0,maxi,dp);
    // solveTab(mat,n,m,maxi);
    solveSOP(mat,n,m,maxi);
      return maxi;
   
    }