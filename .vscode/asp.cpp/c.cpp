#include<iostream>
using namespace std;
int main()
{
    int a[6]={5,1,2,3,4,2};
    int ans=0;
    for(int i=0;i<6;i++)
    {
        ans=ans^a[i];
        cout<<ans<<endl;
    }
    for(int i=1;i<6;i++)
    {
        ans=ans^i;
        cout<<ans<<endl;
    }
   
    cout<<ans;
}