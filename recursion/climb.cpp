     #include <iostream>
using namespace std;

     int climbStairs(int n) {
        //destination to start
        //below start
        if(n<0)
        return 0;
     //at start
        if(n==0)
        return 1;
        
        return climbStairs(n-1)+climbStairs(n-2);
    }
int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n);
}