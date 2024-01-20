#include<iostream>
#include<vector>
using namespace std;
bool isprime(int n)
{  
    if(n<=1)
    return 0; 

    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}
//optimised 
// sieve of eraosthenes
// TC- O(n*log(logn))
int count_prime(int n){
    int count=0;
    vector<bool>prime(n+1,true);
    prime[0]=prime[1]=0;
    for(int i=2;i<n;i++){
       
       if(prime[i]){
        count++;
     
       for(int j=i*2;j<n;j=j+i){
        prime[j]=0;
       }
         }
    }
    return count;

}
int main()
{
    int n;
    cin>>n;
    if(isprime(n))
    cout<<"prime number\n";
    else
    cout<<"Not a prime\n";
   
    int c=count_prime(n);
    cout<<c;
     return 0;
}