#include<bits/stdc++.h>
using namespace std;

char max_occ(string s){
    int a[26]={0};
    for(int i=0;i<s.length();i++){
     char ch=s[i];
     int num=ch-'a';
     a[num]++;
    }
    int maxi=-1;
    int ans=-1;
     for(int i=0;i<26;i++){
    if(a[i]>maxi){
        ans=i;
        maxi=a[i];
    }
     }
     char fn;
     fn=ans+'a';
     return fn;
}
int main()
{
string s;
cin>>s;
cout<<max_occ(s);
}