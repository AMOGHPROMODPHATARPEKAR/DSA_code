#include<bits/stdc++.h>
using namespace std;
    int c=0;
void bubble(int a[],int n){

    for(int i=0;i<n-1;i++){
        bool swapi=false;
        for(int j=0;j<n-1-i;j++){
           
            if(a[j]>a[j+1])
            { c++;
                swap(a[j],a[j+1]);
                swapi=true;
            }
        }
        if(swapi==false){break;}
    }
}
int main(){
int a[7]={8,22,7,9,31,5,13};
bubble(a,7);
for(int i=0;i<7;i++)
cout<<a[i]<<" ";
cout<<endl<<"count "<<c;
}
