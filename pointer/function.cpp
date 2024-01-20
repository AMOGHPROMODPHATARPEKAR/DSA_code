#include <iostream>
#include <vector>
using namespace std;

void update(int *ptr)
{

    *ptr = *ptr + 1;

    cout << "inside\n";
    cout << "value " << *ptr;
    ptr = ptr + 1;
    cout << " address " << ptr << endl;
}

void array(int a[])
{ 
    cout<<"size : "<<sizeof(a)<<endl;
    a[2]=5;
}
int main()
{
    int n = 5;
    int *p = &n;
    cout << "Before\n";
    cout << "value " << *p << " address " << p << endl;
    update(p);
    cout << "after\n";
    cout << "value " << *p << " address " << p << endl;
int arr[4]={1,2,3,4};

    cout<<"size : "<<sizeof(arr)<<endl;
array(arr);
for(int i=0;i<4;i++)
{
    cout<<arr[i]<<" ";
}
    return 0;
}