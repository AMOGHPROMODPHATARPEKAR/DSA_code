#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// brute force
vector<vector<int>> merge_int(vector<vector<int>>a)
{
    int n=a.size();
    sort(a.begin(),a.end());
    vector<vector<int>>ans;

    for(int i=0;i<n;i++)
    {
        int start =a[i][0];
        int end =a[i][1];
        if(!ans.empty()  && end <= ans.back()[1])
        {
            continue;
        }
        for(int j=i+1;j<n;j++)
        {
            if(a[j][0] <= end)
            {
                end =max(end,a[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
  return ans;
}
vector<vector<int>> merge_opt(vector<vector<int>>& a) {
        int n=a.size();
    sort(a.begin(),a.end());
    vector<vector<int>>ans;

    for(int i=0;i<n;i++)
    {
      if(ans.empty() || a[i][0] > ans.back()[1])
      {
          ans.push_back(a[i]);
      }
      else{
       ans.back()[1]=max(a[i][1],ans.back()[1]);
      }
    }
  return ans;
    }
int main()
{
    vector<vector<int>>a={{1,3},{2,4},{8,9},{9,10}};
    vector<vector<int>>ans = merge_opt(a);
    for(int i=0;i<ans.size();i++)
  {
    for(int j=0;j<ans[i].size();j++)
    {
     cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }

}