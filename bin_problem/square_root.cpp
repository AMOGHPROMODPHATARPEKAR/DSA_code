#include <iostream>
using namespace std;
long long int sqrt_int(int x)
{
    int s = 0;
    int e = x;
    long long int mid = s + (e - s) / 2;
    long long int ans = -1;
    while (s <= e)
    {
        long long int square = mid * mid;
        if (square == x)
            return mid;

        if (square < x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
double morePrecision(int n, int precision, int temp)
{
    double factor = 1;
    double ans = temp;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int temp = sqrt_int(n);
    cout << "Answer is " << morePrecision(n, 5, temp);
}