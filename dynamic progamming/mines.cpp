int solve(int i, int j, int n, int m, vector<vector<int>> &M,vector<vector<int>> &dp){
        if(i < 0 || i >= n || j < 0 || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int a = solve(i-1, j+1, n, m, M, dp);
        int b = solve(i, j+1, n, m, M, dp);
        int c = solve(i+1, j+1, n, m, M, dp);
        
        return dp[i][j] = max(max(a, b), c)+M[i][j];
    }
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i = 0 ; i < n ; i++){
            int a = solve(i, 0, n, m, M, dp);
            if(a > ans) ans = a;
        }
        
        return ans;
    }

Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

to the cell diagonally up towards the right 
to the right
to the cell diagonally down towards the right
Find out maximum amount of gold which he can collect until he can no longer move.