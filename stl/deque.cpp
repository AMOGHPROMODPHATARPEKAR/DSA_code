#include<iostream>
#include<deque>
using namespace std;
int main(){
deque<int>q;
q.push_back(2);
q.push_front(4);
    for(int i:q){
        cout<<i<<" ";
    }
    cout<<endl;
    q.pop_back();
        for(int i:q){
        cout<<i<<" ";
    }    cout<<endl;
    cout<<"\nElement at 0th Index "<<q.at(0)<<endl;
    cout<<"empty or not "<<q.empty()<<endl;
    cout<<"first "<<q.front()<<endl;
    cout<<"last "<<q.back()<<endl;
    q.push_back(2);
    q.push_front(5);
    cout<<"before erase "<<endl;
            for(int i:q){
        cout<<i<<" ";
    }    cout<<endl;
    q.erase(q.begin(),q.begin()+2);
           cout<<"after erase "<<endl;  
            for(int i:q){
        cout<<i<<" ";
    }    cout<<endl;
}