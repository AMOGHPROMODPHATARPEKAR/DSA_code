#include <iostream>
#include<vector>
using namespace std;

    void solve(string nums,int index, string output,vector<string>& ans){
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
    vector<string> subsets(string nums) {
        vector<string>ans;
        string output ="";
        int index=0;
        solve(nums,index,output,ans);
        return ans;
    }
int main()
{
string a="abc";
vector<string>ans=subsets(a);
for(int i=0;i<ans.size();i++)
{
   cout<<ans[i]<<" ";
}
}