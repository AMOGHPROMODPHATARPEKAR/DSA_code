#include<bits/stdc++.h>
using namespace std;

  vector<int> twoSum(vector<int>& arr, int target) {
       unordered_map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}
string read(int n, vector<int> book, int target)
{
    int left=0,right=n-1;
    sort(book.begin(),book.end());
    int sum=0;
    while(left<right)
    {
        sum=book[left]+book[right];
        if(sum == target)
        {
            return "YES";
        }else if (sum<target)left++;
        else right--;
    }
    return "NO";
}
int main()
{
    int a[5]={1,2,5,8,4};
int s=9;
    vector<vector<int>>ans;
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++){
           if(a[i]+a[j]==s)
           {
            vector<int>temp;
            temp.push_back(min(a[i],a[j]));
            temp.push_back(max(a[i],a[j]));
            ans.push_back(temp);
           }
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
     for(int j=0;j<ans[i].size();j++)
      {
        cout<<ans[i][j]<<" ";
      }cout<<endl;
    }
   cout<<"pair sum using hashing"<<endl;
   vector<int>b={1,2,5,8,4};
  vector<int>hash = twoSum(b,9);
  cout<<hash[0]<<"  "<<hash[1];
  cout<<"\nTarget possible "<<read(b.size(),b,9);
}