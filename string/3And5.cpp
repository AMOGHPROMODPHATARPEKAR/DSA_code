#include<bits/stdc++.h>
using namespace std;
int sum(int n)
{
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(i%3==0 || i%5==0)
        {
            res += i;
        }
    }
    return res;
}
int main()
{
    int n=6;
    cout<< sum(n);
}