#include<iostream>
#include<vector>
using namespace std;
int main(){

    vector<int>a (5,1);
    int size =a.size();
    for(int i=0;i<size;i++)
    cout<<a[i]<<" ";
    cout<<"\nElement at 2nd Index "<<a.at(2)<<endl;
    cout<<"empty or not "<<a.empty()<<endl;
    cout<<"first "<<a.front()<<endl;
    cout<<"last "<<a.back()<<endl;
    vector<int>v;
    cout<<"Capacity "<<v.capacity()<<endl;
    v.push_back(4);
    cout<<"Capacity "<<v.capacity()<<endl;
    v.push_back(6);
    cout<<"Capacity "<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"Capacity "<<v.capacity()<<endl;
    a.pop_back();
    for(int i:a){
        cout<<i<<" ";
    }
}