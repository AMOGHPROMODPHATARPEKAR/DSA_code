#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>

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

bool wordPattern(string pattern, string s) {
    vector<string> arr = split(s, ' ');
    for(auto i :arr)
      cout<<i;

    cout<<endl;
    if (pattern.length() != arr.size())
        return false;

    map<char, string> mp;

    for (int i = 0; i < pattern.length(); i++) {
        // Check if pattern character already exists in the map
        if (mp.find(pattern[i]) != mp.end()) {
            // If it exists, check if the mapped value matches the current word
            if (mp[pattern[i]] != arr[i]) 
                return false;
        } else {
            // If pattern character doesn't exist in map
            // Check if the word is already mapped to another pattern character
            for (auto& kv : mp) {
                if (kv.second == arr[i])
                    return false;
            }
            // If not, add pattern character and the word to the map
            mp[pattern[i]] = arr[i];
        }
    }
    return true;
}

  bool wordPattern2(string pattern, string s) {
      vector<string> arr = split(s, ' ');
    
    if (pattern.length() != arr.size())
        return false;

    
    unordered_map<char,string>freq1;
    unordered_map<string,char>freq2;
        
        int n= pattern.length();

        for(int i=0;i<n;i++)
        {
           
            freq1[pattern[i]] = arr[i];
            freq2[arr[i]] = pattern[i];
        
        }
        for(int i=0;i<n;i++)
        {
           
            if(freq1[pattern[i]]!=arr[i] || freq2[arr[i]]!=pattern[i])
            {
                return false;
            }
        
        }
        
        return true;
      }

int main() {
    string pattern = "abba";
    string s = "dog cat cat dog";

    cout << wordPattern2(pattern, s) << endl; // Output: 1 (true)

    return 0;
}
