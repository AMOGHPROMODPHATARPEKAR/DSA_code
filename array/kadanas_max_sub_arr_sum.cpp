#include <bits/stdc++.h>
using namespace std;

//brute force
int maxSubArray1(vector<int>& nums) {
        int maxi =INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {int sum =0;
            for(int j=i;j<nums.size();j++)
            {
                   sum += nums[j];
                   maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
//kadan algo
int maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        maxi = max(maxi, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxi;
}

int main()
{
   vector<int>a ={1,2,3,-2,-5,9};
   cout<<" max ans = "<<maxSubArray1(a);
}