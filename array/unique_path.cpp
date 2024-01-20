#include<bits/stdc++.h>
using namespace std;
int uniquePaths(int m, int n) {
       int N=m+n-2;
       int r=m-1;
       double res=1;

       for(int i=1;i<=r;i++)
       {
           res=res*(N-r+i)/i;
       }
       return (int)res;
    }
    int fact(int n)
    {
        int fact=1;
        for(int i=1;i<=n;i++)
        {
            fact *=i;
        }
        return fact;
    }
int uniquePathsOp(int m,int n)
{
     m=m-1;
     n=n-1;

    int res= fact(m+n)/(fact(m)*fact(n));
    return res;
}
    int main()
    {
        cout<<"paths = "<<uniquePathsOp(3,7);
    }