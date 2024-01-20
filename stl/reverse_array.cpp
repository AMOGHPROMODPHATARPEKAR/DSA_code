#include<iostream>
#include<vector>
using  namespace std;
vector<int> reverse_A(vector<int>a){
vector<int>v=a;
int s=0;
int e=a.size()-1;
while (s<=e)
{
    swap(v[s],v[e]);
    s++;
    e--;
}
return v;
}
void print(vector<int>a){
    for(int i:a)
    {
        cout<<i<<" ";
    }cout<<endl;
}
int main(){

    vector<int>v;
    v.push_back(4);
        v.push_back(5);
    v.push_back(8);
    v.push_back(10);
print(v);
cout<<"afterr reverse\n";
vector<int>ans= reverse_A(v);
print(ans);
}