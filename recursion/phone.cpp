#include <iostream>
#include<vector>
using namespace std;


    void solve(string digit,int index, string output,vector<string>& ans,string map[])
    {

        if(index>=digit.length()){
            ans.push_back(output);
            return;
        }
        int number = digit[index]-'0';
        string value= map[number];

        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digit,index+1, output,ans,map);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0)
        return ans;
        string output;
        int index=0;
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,index,output,ans,map);
        return ans;
    }
int main()
{
string a="234";
vector<string>ans=letterCombinations(a);
for(int i=0;i<ans.size();i++)
{
   cout<<ans[i]<<" ";
}
}