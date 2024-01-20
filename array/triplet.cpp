  #include<iostream>
  #include<vector>
  #include<algorithm>
using namespace std;
int main()
{
    int a[5]={1,2,5,8,0};
int s=9;
    vector<vector<int>>ans;
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++){
          for(int k=j+1;k<5;k++)
          {
             if(a[i]+a[j]+a[k]==s)
           {
            vector<int>temp;
            temp.push_back(a[i]);
            temp.push_back(a[j]);
            temp.push_back(a[k]);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
           }
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

}