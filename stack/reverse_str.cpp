#include <bits/stdc++.h> 
using  namespace std;

int main()
{
string a="amogh";
stack<char>s;
for(int i=0;i<a.length();i++)
{
    s.push(a[i]);
}

string ans="";
while (!s.empty())
{
   char ch = s.top();
   ans.push_back(ch);
   s.pop();
}
cout<<"answer is "<<ans;
}