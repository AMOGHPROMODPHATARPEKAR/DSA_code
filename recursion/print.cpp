#include <iostream>
using namespace std;

void print(int n)
{
    if (n==0)
    return;
       
    //  cout<<n<<" ";//tail
    
     print(n-1);

     cout<<n<<" ";//head
}
int main()
{
    int n;
    cin >> n;
    print(n);
}