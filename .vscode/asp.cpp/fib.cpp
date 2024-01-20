#include<iostream>
using namespace std;
int fib(int n)
{
    int a=0,b=1,i=3,c;
    switch(n)
    { 
        case 1:return 0;
    
    case 2: return 1;
    
    default: while(i<=n)
    {
         c=a+b;
         a=b;
         b=c;
         i++;  
    }
    return c;
    
    }
}
int main()
{
    int n;
    cout<<"enter n\n";
    cin>>n;
    cout<<"The "<<n<<"th term of fibonacci series is "<<fib(n)<<endl;
    return 0;
}