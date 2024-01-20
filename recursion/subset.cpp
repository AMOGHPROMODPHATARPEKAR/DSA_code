#include <iostream>
#include<vector>
using namespace std;

    void solve(vector<int>nums,int index, vector<int>output,vector<vector<int>>& ans){
        //base case
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        //exclude
        solve(nums,index+1,output,ans);
        //include
        output.push_back(nums[index]);
        solve(nums,index+1,output,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int index=0;
        solve(nums,index,output,ans);
        return ans;
    }
int main()
{
vector<int>a ={1,2,3};
vector<vector<int>>ans=subsets(a);
for(int i=0;i<ans.size();i++)
{
    for(int j=0;j<ans[i].size();j++)
    {
        cout<<"["<<ans[i][j]<<"]";
    }cout<<endl;
}
}