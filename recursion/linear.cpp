#include <iostream>
using namespace std;

bool linear(int a[], int n, int key)
{
    if (key == a[0])
        return true;
        
    if (n == 0)
        return false;

    return linear(a + 1, n - 1, key);
}
int main()
{
    int ar[] = {1, 2, 3, 3, 5};
    int key;
    cout << "enter key \n";
    cin >> key;
    if (linear(ar, 5, key))
    {
        cout << "present" << endl;
    }
    else
    {
        cout << "not present" << endl;
    }
}