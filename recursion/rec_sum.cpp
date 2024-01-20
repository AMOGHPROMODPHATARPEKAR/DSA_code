     #include <iostream>
using namespace std;

int sum(int a[],int n,int s)
{ 
if(n==0)
return s;
s+=a[0];
return sum(a+1,n-1,s);
}
int main()
{ 
    int ar[]={1,2,3,3,10};
    cout<<"sum = "<<sum(ar,5,0);
}