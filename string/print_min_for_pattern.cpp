#include<bits/stdc++.h>
using namespace std;

    string printMinNumberForPattern(string S){
        
         string D="1";
         string ans="";
         int n = S.size();
         int count =1;
         for(int i=0;i<n;i++)
         {
             if(S[i] == 'D')
             {
                 count++;
                 D = to_string(count) + D;
             }
             else //means I
             {
                 ans+=D;
                 count++;
                 D = to_string(count);
             }
         }
         ans+=D;
         return ans;
    }
    // string printMinNumberForPattern(string S){
    //     string res="";
    //     stack<int> st;
    //     for(int num=0;num<=S.size();num++){
    //         st.push(num+1);
    //         if(S[num]=='I' || num==S.size()){
    //             while(!st.empty()){
    //                 res+=to_string(st.top());
    //                 st.pop();
    //             }
    //         }
    //     }
    //     return res;
    // }
int main()
{
string a ="DD";
string ans =printMinNumberForPattern(a);
cout<<"Answer is  "<<ans;
}