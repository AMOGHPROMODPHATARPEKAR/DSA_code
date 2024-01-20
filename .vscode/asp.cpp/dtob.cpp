#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,i=0,ans=0;

    cin>>n;
    while(n!=0)
    {
        int bit=n&1;
        int power=pow(10,i);
        ans=bit*power+ans;
        n=n>>1;
        i++;
        
    }
    cout<<ans;

    return 0;
}