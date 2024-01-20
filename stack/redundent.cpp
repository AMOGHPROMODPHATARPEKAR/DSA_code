#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char>st;
    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];

        if(ch == '('|| ch == '+'|| ch == '-'|| ch == '*'|| ch == '/')
        {
            st.push(ch);
        }
        else if(ch == ')')
        {
            bool isredunant = true;
            while(st.top()!='(')
            {
                char top=st.top();
                if(top == '+'||top == '-'||top == '*'||top == '/')
                {
isredunant = false;
                }
                st.pop();
            }
            if(isredunant == true)
            return true;

            st.pop();
        }
    }
    return false;
}
int main()
{
    string par="((a+b-(c*d)))";
    if(findRedundantBrackets(par))
    {
        cout<<" redundent";
    }

    else{
        cout<<" not redundent";
    }
}