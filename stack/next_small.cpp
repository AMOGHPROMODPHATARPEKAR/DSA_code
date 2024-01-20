#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);

    for(int i=n-1;i>=0;i--)
    {
        int cur = arr[i];
        while(s.top()>=cur)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(cur);
    }
    return ans;
}
int main()
{
    vector<int>arr={2,1,4,3};
    vector<int>ans =nextSmallerElement(arr,4);
    for(int i=0;i<4;i++)
    {
        cout<<ans[i]<<" ";
    }
}