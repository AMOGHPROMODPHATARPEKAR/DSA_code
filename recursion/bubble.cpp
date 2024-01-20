#include <iostream>
using namespace std;
void print(int a[],int n){
    for(int i=0;i<5;i++)
    cout<<a[i]<<" ";
}
void bubble(int a[], int n)
{ 
    if(n==0 || n==1)
    return;

    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
        }
    }
    bubble(a,n-1);

}
int main()
{
    int ar[] = {1, 6, 5,2,0};
    bubble(ar,5);
    print(ar,5);
}