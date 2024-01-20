#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num = 5;
    cout << num << endl;
    cout << "adress " << &num;
    int *p = &num;
    cout << "\naddress " << p << endl;
    cout << "value at ad " << *p << endl;
    num = 8;
    cout << "value " << num << endl;
    cout << "value by pointer " << *p << endl;
    cout << "size of integer " << sizeof(num) << endl;
    cout << "size of pointer " << sizeof(p) << endl;
    double d = 10.09;
    double *p2 = 0;
    p2 = &d;
    cout << "size of double " << sizeof(d) << endl;
    cout << "size of pointer " << sizeof(p2) << endl;

    (*p2)++;
    cout<<d<<endl;
     //copy
     int *q= p;
     cout<<p<<"   "<<*p<<endl;
     cout<<q<<"   "<<*q<<endl;

    return 0;
}