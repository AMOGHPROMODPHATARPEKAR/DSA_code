#include <iostream>
#include <string>
using namespace std;

string StringChanges(string s) {
   char prev='\0';
    string res="";
   for(int i=0;i<s.length();i++)
   {
    if(isupper(s[i]))
    {
        if(s[i] == 'M')
        {
            if(prev != '\0')
            {
                res+=prev;
            }
        }else if(s[i] == 'N')
        {
            i++;
        }
    }
    else
    {
        res+=s[i];
        prev = s[i];
    }
   }

   return res;
       
}

int main() {
    string str = "abcNdgM";
    cout << StringChanges(str) << endl;
    return 0;
}
