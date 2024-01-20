#include<bits/stdc++.h>
using namespace std;
int length(char a[]){
    int count=0;
    for(int i=0;a[i]!='\0';i++){
        count++;
    }
    return count;
}
char toLower(char ch){
    if((ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))
    {
        return ch;
    }else{
    return ch -'A'+'a';
    } 
}
bool pal(char a[],int len){
      int s=0;
     int e=len-1;
while (s<=e)
{
    if(toLower(a[s])!=toLower(a[e])){
        return false;
    }
    s++;
    e--;
}
return true;
}
int main()
{
    char a[10];
    cin>>a;
    int len=length(a);
if(pal(a,len)){
    cout<<"palindrome\n";
}else{
    cout<<"not a palindrome";
}
   
}