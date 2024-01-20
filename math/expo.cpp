#include<iostream>
#include<vector>
using namespace std;
// a^b%m
int expo_mod(int a,int b,int m){
int res=1;
while(b>0){
if(b&1){
    res=(1LL*res*(a)%m)%m;
}
a=((a)%m*(a)%m)%m;
b=b>>1;
return res;
}
}
int main()
{
    int a,b,m;
    cin>>a>>b>>m;
    cout<<"em = "<<expo_mod(a,b,m);
     return 0;
}