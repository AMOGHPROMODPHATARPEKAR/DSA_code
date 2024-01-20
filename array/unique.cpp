#include<iostream>
using namespace std;
int main()
{
    int a[5]={1,2,3,2,1};
    int ans=0;
    for(int i=0;i<5;i++)
    {
        ans=ans^a[i];
    }
    cout<<ans;
}