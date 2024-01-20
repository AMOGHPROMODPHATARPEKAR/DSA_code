#include <bits/stdc++.h> 
using  namespace std;
void delete_mid(stack<int>&s,int count,int n)
{
if(count == n/2)
{
    s.pop();
    return;
}
int num = s.top();
s.pop();
delete_mid(s,count+1,n);
s.push(num);
}
void PrintStack(stack<int> s)
{
    if (s.empty()) 
        return;
     
 
    int x = s.top();
 
    s.pop();
 
    // Recursively call the function PrintStack
    PrintStack(s);
 
    
    cout << x << " ";
 
    
    s.push(x);
}
int main()
{
stack<int>s;
s.push(5);
s.push(15);
s.push(3);
s.push(54);
s.push(32);
PrintStack(s);
cout<<endl;
int count = 0;
delete_mid(s,count,s.size());
PrintStack(s);
}