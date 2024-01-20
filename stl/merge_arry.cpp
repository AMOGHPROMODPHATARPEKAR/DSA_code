#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int>v1,int m,vector<int>v2,int n){
 
int i=0,j=0;
vector<int>v3;
while (i<m &&j<n)
{
   if(v1[i]<v2[j])
   {
    v3.push_back(v1[i]);
    i++;
   }else{
    v3.push_back(v2[j]);
    j++;
   }
}

while (i<m)
{
     v3.push_back(v1[i]);
    i++;
}
while (j<n)
{
   v3.push_back(v2[j]);
    j++;
}
v1 = v3;
return v1;

}

void print(vector<int>a){
    for(int i:a)
    {
        cout<<i<<" ";
    }cout<<endl;
}

int main(){
    vector<int>v1={1,2,3,0,0,0};
    vector<int>v2={2,5,6};
   v1=merge(v1,3,v2,3);
 
    print(v1);
}