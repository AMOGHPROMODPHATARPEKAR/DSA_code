#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 1 || n == 0)
        return 1; // base case return mandatory
    else
        return (n * fact(n - 1));
}
int main()
{
    int n;
    cin >> n;
    cout << fact(n);
}