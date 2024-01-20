#include<iostream>
using namespace std;
int fact(int n)
{ int f=1;
    for(int i=1;i<=n;i++)
    {
        f= f*i;
    }
return f;
}
int nCr(int n,int r)
{
    int num=fact(n);
    int den=fact(r)*fact(n-r);
    return num/den;
}
int main()
{ int n,r;
    cout<<"enter n and r";
    cin>>n>>r;
    cout<<"the result is "<<nCr(n,r)<<endl;
    return 0;
}