#include<iostream>
using namespace std;
void sa(int a[],int n)
{
   for(int i=0;i<n;i=i+2)
   {
    if(i+1<n)
    swap(a[i],a[i+1]);
   }
}
int main()
{
     int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    sa(a,n);
    cout<<"alternate swaped array is \n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}