#include<iostream>
using namespace std;
int sum(int a[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=a[i];
    return sum;
}
int main()
{
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"the sum of array : "<<sum(a,n);
    return 0;
}