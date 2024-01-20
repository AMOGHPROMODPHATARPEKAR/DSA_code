 int longestSubsequence(vector<int>& arr, int difference) {
        int ans=0;
        int n=arr.size();
        unordered_map<int,int>dp;
        
        for(int i=0;i<n;i++)
        {
            int temp = arr[i] - difference;
                int tempAns=0;
                
                //cjeck if already present ans
                if(dp.count(temp))
                {
                    tempAns = dp[temp];
                }
                
                dp[arr[i]] = 1+tempAns;
                ans= max(ans,dp[arr[i]]);
        }
       return ans;
    }