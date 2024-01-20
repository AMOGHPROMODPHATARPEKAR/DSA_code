#include<iostream>
#include<array>
using namespace std;
int main(){

    array<int,4>a ={ 2,3,5,1};
    int size =a.size();
    for(int i=0;i<size;i++)
    cout<<a[i]<<" ";
    cout<<"\nElement at 2nd Index "<<a.at(2)<<endl;
    cout<<"empty or not "<<a.empty()<<endl;
    cout<<"first "<<a.front()<<endl;
    cout<<"last "<<a.back()<<endl;
}