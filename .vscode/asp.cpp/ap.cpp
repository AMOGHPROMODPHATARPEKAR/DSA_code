#include<iostream>
using namespace std;
int Ap(int a,int d,int n)
{
    return a+(n-1)*d;
}
int main()
{
    int n,a,d;
    cout<<"enter first term and difference od ap\n";
    cin>>a>>d;
    cout<<"enter n to be found\n";
    cin>>n;
    cout<<"the "<<n<<"th term of AP is "<<Ap(a,d,n)<<endl;
    return 0;
}