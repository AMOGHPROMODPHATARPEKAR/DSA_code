#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int>h(26);
        for(int i=0;i<s.size();i++)
        {
            h[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++)
        {
            int x= --h[t[i]-'a'];
            if(x<0) return false;
        }
        return true;
    }
    bool isAnagram2(string s, string t) {
        if(s.size() != t.size()) return false;

        map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            int x= --mp[t[i]];
            if(x<0) return false;
        }
        return true;
    }
int main()
{
    string a="youtube";
    string b="outbeyu";
    if(isAnagram2(a,b))
    {
        cout<<"ANAGRAM";
    }
    else
    {
        cout<<"NOT Anagaram";
    }
}