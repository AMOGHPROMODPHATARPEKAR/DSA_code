void solve(vector<int>& candidates, int target,int index,vector<int>output,vector<vector<int>>&ans)
    {
        if(target < 0)
        {
            return;
        }
        if(index>= candidates.size())
        {
            if(target == 0)
            {
            sort(output.begin(),output.end());
            if(find(ans.begin(),ans.end(),output) == ans.end())
            {
                ans.push_back(output);
            }
            }
            return;
        }
        //exclude
        solve(candidates,target,index+1,output,ans);
        //include
            output.push_back(candidates[index]);
            solve(candidates,target-candidates[index],index,output,ans);



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>output;
        solve(candidates,target,0,output,ans); 
        return ans;
    }

    // TC-2^k*k
    // SC- k*x