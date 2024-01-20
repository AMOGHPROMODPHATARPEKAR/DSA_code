#include <iostream>
#include <vector>
using namespace std;
// reference variable is a variable with same memory block of anaother variable
// 2 name single bllock


void update(int &n){  //pass by refernce
    n++;
}
int& fun(int a){
int num=10;
int &ans=num;
return ans;
}
int main()
{
    int i = 5;
    int &j = i; // reference variable syntax
    cout << i << "  " << j << endl;
    i++;
    cout << i << "  " << j << endl;
    j++;
    cout << i << "  " << j << endl;
int n=6;
cout<<"before "<<n<<endl;
update(n);
cout<<"after "<<n<<endl;

fun(n);

    return 0;
}