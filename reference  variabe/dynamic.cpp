#include <iostream>
#include <vector>
using namespace std;
// new and delete
//dynamic is heap memory &static is stack memory

int getsum(int *a,int n){
    int sum=0;
    for(int i=0;i<n;i++){
sum+=a[i];
}
return sum;
}
int main()
{
int n;
cin>>n;

int *arr = new int[n];
for(int i=0;i<n;i++){
cin>>arr[i];
}
cout<<"sum "<<getsum(arr,n)<<endl;
delete [] arr;
//2D array dynamic
cout<<arr[2];
int r,c;
cin>>r>>c;
int **a=  new int*[r];
for(int i=0;i<r;i++){
    a[i]=new int [c];
}

for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cin>>a[i][j];
    }
}
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cout<<a[i][j]<<" ";
    }cout<<endl;
}
for(int i=0;i<r;i++){
delete [] a[i];
}
delete []a;
    return 0;
}