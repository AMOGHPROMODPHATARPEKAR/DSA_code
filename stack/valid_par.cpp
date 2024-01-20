#include <bits/stdc++.h>
using namespace std;

bool matches(char top, char ch) {
  if ((ch == ')' && top == '(') || (ch == '}'&&top=='{')
  ||(ch==']' && top == '['))
    return true;
    else
    return false;
}
bool isValidParenthesis(string s)
{
    stack<char>st;

    for(int i=0;i<s.length();i++)
    {
        char ch =s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
          st.push(ch);
        }
        else{
            if(!st.empty())
            {
                char top =st.top();
                if(matches(top,ch))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if(st.empty())
            {
               return true;
            }else
            {
                return false;
            }
    
}

int main()
{
    string par="({[]})";
    if(isValidParenthesis(par))
    {
        cout<<"balance";
    }

    else{
        cout<<"unbalanced";
    }
}