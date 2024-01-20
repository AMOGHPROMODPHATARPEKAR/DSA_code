#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// brute force
void  rotate_a(int a[3][3],int ans[3][3],int n)
{
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
     ans[j][n-i-1] =a[i][j];
    }
  }
}
//optimal
void rotate_opt(vector<vector<int>>& matrix) {
           
            //step1 transpose 
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i + 1; j < matrix[i].size(); j++)
            swap(matrix[i][j], matrix[j][i]);
    }
    //step2 reverse
    for(int i=0;i<matrix.size();i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
    }
int main()
{
    int  a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int ans[3][3];
      rotate_a(a,ans,3);
    for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
     cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
 vector<vector<int>>b =  {{1,2,3},{4,5,6},{7,8,9}};
  rotate_opt(b);
  cout<<"optimal\n";
  
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
     cout<<b[i][j]<<" ";
    }
    cout<<endl;
  }
}