   #include<bits/stdc++.h>
using namespace std;
    bool isRotated(string str1, string str2)
    {
        int len1= str1.length();
        int len2 = str2.length();
        if(len1 != len2)
        {
            return false;
        }
        if(len1<2 || len2 <2)
        {
            if(str1 == str2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        //create temp right rotation and left rotation 
        string temp1,temp2;
        
        //right rotation
        temp1.append(str1.substr(2,len1-2));
        temp1.append(str1.substr(0,2));
        
        //left rotation
        temp2.append(str1.substr(len1-2,2));
        temp2.append(str1.substr(0,len1-2));
        
        if(temp1 == str2 || temp2 == str2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int main() {
    string a = "amazon";
string b = "azonam";
string s1 ="geeksforgeeks";
string s2 ="geeksgeeksfor";
if(isRotated(s1,s2))
{
    cout<<"yes roated by 2 place";
}
else{

    cout<<"NO roated by 2 place";
}
    return 0;
}