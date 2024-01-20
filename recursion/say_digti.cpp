     #include <iostream>
using namespace std;

void sayDigit(string a[],int n)
{ 
    if(n==0)
    return;

    int digit=n%10;
    n=n/10; 
    
    sayDigit(a,n);
    cout<<a[digit]<<" ";

}
int main()
{ 
    string a[10]={"Zero", "one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cin >> n;
    sayDigit(a,n);
}