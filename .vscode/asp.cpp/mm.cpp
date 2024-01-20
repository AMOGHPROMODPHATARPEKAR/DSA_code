#include<iostream>
using namespace std;
int gmin(int a[],int n)
{
    int m=INT8_MAX;
    for(int i=0;i<n;i++)
    {
        m=min(m,a[i]);
    }
    return m;
}
int gmax(int a[],int n)
{
    int m=INT8_MIN;
    for(int i=0;i<n;i++)
    {
        m=max(m,a[i]);
    }
    return m;
}
int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"minimun = "<<gmin(a,n)<<endl;
    cout<<"maximun = "<<gmax(a,n)<<endl;

    return 0;
}