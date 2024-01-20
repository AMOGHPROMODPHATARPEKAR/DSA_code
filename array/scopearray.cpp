#include<iostream>
using namespace std;
void update(int a[],int n)
{
    a[2]=3;
    cout<<"in function"<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int main()
{
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    update(a,n);
    cout<<"\nin main\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}