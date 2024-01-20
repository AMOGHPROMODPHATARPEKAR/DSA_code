#include<bits/stdc++.h>
using namespace std;
    bool areIsomorphic(string str1, string str2)
          {
        
        // Your code here
       int n = str1.length();
       if(n!=str2.length())
       {
           return false;
       }
        unordered_map<char,char>freq1;
        unordered_map<char,char>freq2;
        
        for(int i=0;i<n;i++)
        {
           
            freq1[str1[i]] = str2[i];
            freq2[str2[i]] = str1[i];
        
        }
        
        for(int i=0;i<n;i++)
        {
           
            if(freq1[str1[i]]!=str2[i] || freq2[str2[i]]!=str1[i])
            {
                return false;
            }
        
        }
        
        return true;
        
    }
int main()
{
   string s1="aab";
   string s2 = "ccb";
   if(areIsomorphic(s1,s2))
   {
    cout<<"strings are isomorphic";
   }
   else
   {
        cout<<"strings are not isomorphic";

   }
}