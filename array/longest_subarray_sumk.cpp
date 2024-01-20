


#include <bits/stdc++.h>
using namespace std;
//for k=0
int maxLen_0(vector<int>&A, int n)
    {   
      unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 
    }
int solve(vector<int>& a,int k) {
    int maxLen = 0;
    unordered_map<int, int> sumIndexMap;
    int sum = 0;
   int maxlen=0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];

        if (sum == k) {
            maxLen = max(maxlen,i + 1);
        }
        int rem=sum-k;
         if (sumIndexMap.find(rem) != sumIndexMap.end()) {
           int len=i-sumIndexMap[rem];
           maxlen=max(maxlen,len);
        } 
        if(sumIndexMap.find(sum) == sumIndexMap.end())
        {
            sumIndexMap[sum]=i;
        }
    }

    return maxLen;
}
//optimal for sum =k applicable only for positive integer
int solve_op(vector<int>& a,int k) {
    
    int left=0,right=0;
    int sum=a[0];
    int maxLen=0;
    int n=a.size();

    while(right<n)
    {
        while (left<=right && sum>k)
        {
            sum-=a[left];
            left++;
        }
        if(sum == k)
        {
            maxLen=max(maxLen,right-left+1);
        }
        right++;
        if(right <n)
        sum+= a[right];
        
    }

    return maxLen;
}
int main() {
    vector<int> a = {9, 1, 3, 1, 6, 5};
    cout << solve_op(a,5) << endl;
    cout << solve(a,5) << endl;

    return 0;
}

