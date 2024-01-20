#include<iostream>
using namespace std;
void rev(int a[],int n)
{
    int start=0;
    int end=n-1;
    while(start<end)
    {
        swap(a[start],a[end]);
        start++;
        end--;
    }
}
int main()
{
     int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    rev(a,n);
    cout<<"reversed array\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}