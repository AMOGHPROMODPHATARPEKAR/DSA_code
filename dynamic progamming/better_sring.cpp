#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 256;
int countSub(string str)
    {
        vector<int> last(MAX_CHAR, -1);
     
        int n = str.length();
        int dp[n + 1];
     
        dp[0] = 1;
     
        for (int i = 1; i <= n; i++) {
            dp[i] = 2 * dp[i - 1];
     
            if (last[str[i - 1]] != -1)
                dp[i] = dp[i] - dp[last[str[i - 1]]];
            last[str[i - 1]] = (i - 1);
        }
     
        return dp[n];
    }
    string betterString(string str1, string str2) {
        int countSubsequence1 = countSub(str1);
        int countSubsequence2 = countSub(str2);
        
        return max(countSubsequence1, countSubsequence2) == countSubsequence1 ? str1 : str2;
    }
    int main()
    {
        string ans = betterString("gfg","ghg");
        cout<<" Answer is : "<<ans<<endl;
    }