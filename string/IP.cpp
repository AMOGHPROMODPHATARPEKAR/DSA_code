#include<bits/stdc++.h>
using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
        string temp="";

        for(int i=0;i<s.length();i++)
        {
            if(s[i] == delimiter)
            {
                tokens.push_back(temp);
                temp="";
            }
            else
             temp+=s[i];
        }
        tokens.push_back(temp);
        return tokens;
}

bool even(string s)
{
    int sum=0;
    for(auto i: s){
        sum+= (i-'0');
    }
    if(sum%2 ==0) return true;
    return false;
}

bool greater2(string s)
{
    int maxi= s[2];

    if(s[0] > maxi || s[1] > maxi)
    {
        return false;
    }

    return true;
}

bool ipCheck(string ip){
    vector<string>arr = split(ip,'.');

    for(auto i:arr)
    {
        if(i.length() != 3)
        {
            return false;
        }
    }

    if(even(arr[0]) && !even(arr[1]))
    {
        for(auto i:arr)
        {
            if(!greater2(i)) return false;
        }
        return true;
    }
    else {
        return false;
    }

}
int main(){
    string ip = "129.168.505";
   
    if(ipCheck(ip))
    {
        cout<<"Valid IP";
    }else{
        cout<<"Invalid IP";
    }


}