#include <iostream>
using namespace std;
void print(int a[], int n)
{
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
}
void select(int a[], int n)
{

    if (n == 0 || n == 1)
        return;

    int mini = 0;
    for (int i = 1; i < n ; i++)
    {
        if (a[i] < a[mini])
        mini=i;
 
    }
    swap(a[0], a[mini]);

    select(a + 1, n - 1);
}
int main()
{
    int ar[] = {1, 6, 5, 2, 0};
    select(ar, 5);
    print(ar, 5);
}