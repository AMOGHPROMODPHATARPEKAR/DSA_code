#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "size of array " << sizeof(a) << endl;
    cout << "adrees of 1st element" << a << endl;
    cout << "value of 1st element " << *(&a[0]) << endl;
    (*a)++;
    cout << "value of 1st element " << *a << endl;
    cout << "value of 1st element " << a[0] << endl;
    cout << "3rd " << a[2] << endl;  // internal is *(a+i)
    cout << "3rd " << 2 [a] << endl; // chalak bro because internal is *(i+a)
    cout << "3rd " << *(a + 2) << endl;

    int *p = a;
    cout << p << endl;
    cout << *p << endl;
    cout << &p << endl;

    p = p + 2;
    // a=a+1; error cannot re-assign address
    cout << *p << endl;
    cout << "int array and string array\n";
    int arr[5] = {1, 5, 7};
    char ch[6] = "avni";
    cout << arr << endl;
    cout << ch << endl;
    char *c = &ch[0];
    cout << "by pinter  " << c << endl; // print entire string
    cout << "by pinter  " << *c << endl;
    cout << "by pinter  " << *(c + 2) << endl;
    char temp = 'z';
    char *t = &temp;
    cout << "by p0inter  " << t << endl; // till it gets a null
    // double pointer

    cout << "double pointer \n\n";
    int i = 5;
    int *ptr = &i;
    int **q = &ptr;
    cout <<&ptr<<"  "<< ptr << "   " << *ptr << endl;
    cout << q << "   " << *q <<"  "<<**q<< endl;

    return 0;
}