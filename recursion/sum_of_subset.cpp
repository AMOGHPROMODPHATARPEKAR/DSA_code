void solve(vector<int> arr, int N,int index,int sum,vector<int>&ans)
    {
        if(index>=N)
        {
            ans.push_back(sum);
            return;
        }
        //exclude
        solve(arr,N,index+1,sum,ans);
        //include
        solve(arr,N,index+1,sum+arr[index],ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        int sum=0;
        vector<int>ans;
         solve(arr,N,0,sum,ans);
         return ans;
    }