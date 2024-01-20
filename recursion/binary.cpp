#include <iostream>
using namespace std;

bool binary(int a[], int s, int e, int key)
{
    if (s > e)
    {
        return false;
    }
    
    int mid = s + (e - s) / 2;
    if (key == a[mid])
    {
        return true;
    }

   if (key < a[mid])
    {
        return binary(a, s, mid - 1, key);
    }
    else
    {
        return binary(a, mid + 1, e, key);
    }
}
int main()
{
    int ar[] = {1, 2, 3, 3, 5};
    int key;
    cout << "enter key \n";
    cin >> key;
    if (binary(ar, 0, 4, key))
    {
        cout << "present" << endl;
    }
    else
    {
        cout << "not present" << endl;
    }
}