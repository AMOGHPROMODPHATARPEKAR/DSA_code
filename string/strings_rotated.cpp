   #include<bits/stdc++.h>
using namespace std;
bool areRotations(string s1,string s2)
    {
        if (s1.size() != s2.size())
        return false;
 
    queue<char> q1;
    for (int i = 0; i < s1.size(); i++) {
        q1.push(s1[i]);
    }
 
    queue<char> q2;
    for (int i = 0; i < s2.size(); i++) {
        q2.push(s2[i]);
    }
 
    int k = s2.size();
    while (k--) {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1)
            return true;
    }
    return false;
    }

    int main() {
    string a = "amazon";
string b = "azonam";
string s1 ="geeksforgeeks";
string s2 ="geeksgeeksfor";
if(areRotations(a,b))
{
    cout<<"yes roated";
}
else{

    cout<<"NO roated";
}
    return 0;
}