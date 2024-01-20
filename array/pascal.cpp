#include<iostream>
#include<vector>
using namespace std;
//finding element in pascal tree
// r - Rows
// c - coloum

// formula = r-1 C c-1

long long combination(int n,int r)
{
  long long res = 1;
  for(int i=0;i<r;i++)
  {
    res = res*(n-i);
    res =res/(i+1);
  }
  return res;
}

//brute force
void printrow(int n)
{
    
    for(int i=0;i<n;i++)
    {
        cout<<combination(n-1,i)<<" ";
    }
}
//optimised T O(n) S O(1)
void print_row(int n)
{
    int ans = 1;
    cout<<ans<<" ";
    for(int i=1;i<n;i++)
    {
        ans = ans*(n-i);
        ans =ans/i;
    cout<<ans<<" ";

    }
}
//brute force to create pascal triangle
vector<vector<int>> pascal(int n)
{
    vector<vector<int>>ans;

    for(int i=1;i<n;i++)
    { vector<int>temp;
        for(int j=1;j<=i;j++)
        {
        temp.push_back(combination(i-1,j-1));
        }
        ans.push_back(temp);
    }
    return ans;
}

//optimised to create pascal triangle
vector<int> generaterow(int n)
{
    vector<int>temp;
   long long ans = 1;
    temp.push_back(ans);
    for(int i=1;i<n;i++)
    {
        ans = ans*(n-i);
        ans =ans/i;
    temp.push_back(ans);
}
return temp;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

    for(int i=1;i<=numRows;i++)
    { 
        ans.push_back(generaterow(i));
    }
    return ans;
    }
int main()
{
    cout<<"Element at 5 R 3rd element = "<<combination(4,2)<<endl;
    cout<<"the elements at 5 row is"<<endl;
    print_row(5);
    cout<<endl;
    vector<vector<int>>ans = generate(5);
    cout<<"pascal triangle "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}