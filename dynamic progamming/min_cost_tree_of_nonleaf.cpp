class Solution {
public:
    int solve(int left,int right,vector<int>& arr,map<pair<int,int>,int>&maxi)
    {
        if(left == right)
            return 0;
        
        int ans =INT_MAX;
        for(int i=left;i<right;i++)
        {
            ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}] + solve(left,i,arr,maxi) + solve(i+1,right,arr,maxi));
        }
        return ans;
    }
    int solveMem(int left,int right,vector<int>& arr,map<pair<int,int>,int>&maxi,vector<vector<int>>&dp)
    {
        if(left == right)
            return 0;
        
        if(dp[left][right] != -1)
        {
            return dp[left][right];
        }

        int ans =INT_MAX;
        for(int i=left;i<right;i++)
        {
            ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}] + solveMem(left,i,arr,maxi,dp) + solveMem(i+1,right,arr,maxi,dp));
        }
        return dp[left][right] = ans;
    }

    int solveTab(vector<int>& arr,map<pair<int,int>,int>&maxi)
    {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));


        for(int left =n-1;left>=0;left -- )
        {
            for(int right=left ;right< n;right++)
            {
                if(left == right) continue;
                int ans =INT_MAX;
                for(int i=left;i<right;i++)
                {
                ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}] + dp[left][i] +dp[i+1][right]);
                 }
                dp[left][right] = ans;
            }
        }

        return dp[0][n-1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>maxi;
        for(int i=0;i<arr.size();i++)
        {   maxi[{i,i}]=arr[i];
            for(int j=i+1;j<arr.size();j++)
            {
                maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);
            }
        }
        // return solve(0,arr.size()-1,arr,maxi);
        // vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,-1));
        // return solveMem(0,arr.size()-1,arr,maxi,dp);
        return solveTab(arr,maxi);
    }
};