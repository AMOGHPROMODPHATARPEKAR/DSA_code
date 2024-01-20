#include<bits/stdc++.h>
using namespace std;
int length(char a[]){
    int count=0;
    for(int i=0;a[i]!='\0';i++){
        count++;
    }
    return count;
}
void reverse(char a[],int len){
            int st=0;
        int e=len-1;
        while(st<e){
            swap(a[st++],a[e--]);
        }
    
}
int main()
{
    char a[10];
    cin>>a;
    cout<<"name is "<<a<<endl;
    a[2]='\0';
    int len=length(a);
    cout<<"The length = "<<len<<endl;
    // reverse(a,len);
    // cout<<"after reverse "<<a;
    string s="abbcd";
    s[2]='\0';
cout<<a<<endl;
cout<<s<<endl;
}