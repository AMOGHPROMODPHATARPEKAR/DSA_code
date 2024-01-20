#include <iostream>
using namespace std;

int power(int m,int n)
{
 if(n==0)
 return 1;

 return m*power(m,n-1);
}
int power_op(int a,int b){
    if(b==0)
    return 1;
    
    if(b==1)
    return a;

    int ans=power_op(a,b/2);

    if(b%2==0)
    {
        return ans*ans;
    }else{
        return a*ans*ans;
    }

}
int main()
{
    int m,n;
    cin >> m>>n;
    cout << power(m,n)<<endl;
    cout<<power_op(m,n);
}