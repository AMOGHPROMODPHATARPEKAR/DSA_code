#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) {
        int pre=1;
        int suf=1;
        int maxi = INT_MIN;

         for(int i=0;i<nums.size();i++)
         {
             if(pre == 0)
              pre=1;
            if(suf == 0)
            {
                 suf =1;
            }
            pre = pre*nums[i];
            suf = suf*nums[nums.size()-i-1];
            maxi = max(maxi,max(pre,suf));
         }
         return maxi;
    }
    //kadan algorithm
// int maxProductSubArray(vector<int>& nums) {
//     int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
//     for(int i=1;i<nums.size();i++) {
//         int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
//         prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
//         prod1 = temp;
        
//         result = max(result,prod1);
//     }
    
//     return result;
// }

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProduct(nums);
    return 0;
}