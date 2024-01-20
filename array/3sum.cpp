#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//TC-O(n3)
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;  // Skip duplicates
        }

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                ans.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates for both left and right pointers
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return ans;
}
//TC-O(n2)
vector<vector<int>> threeSumop(vector<int>& nums) {
        
        set<vector<int>>st;
        for(int i=0;i<nums.size();i++)
        {
            set<int>hashset;
            for(int j=i+1;j<nums.size();j++)
            {
               int third=-(nums[i]+nums[j]);
               if(hashset.find(third) != hashset.end())
               {
                   vector<int>temp={nums[i],nums[j],third};
                   sort(temp.begin(),temp.end());
                st.insert(temp);
               }
               hashset.insert(nums[j]);
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }

    //three pointer approach
    vector<vector<int>> threeSumop2(vector<int>& nums) {
        
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && (nums[i] == nums[i-1])) continue;

            int j= i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k] > 0)
                {
                    k--;
                }else if(nums[i]+nums[j]+nums[k] < 0)
                {
                    j++;
                }
                else
                {
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        
        return ans;
    }

int main() {
    // Example Usage
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    // vector<vector<int>> result = threeSumop(nums);
    // vector<vector<int>> result = threeSumop2(nums);

    // Displaying the result
    for (const auto& triplet : result) {
        cout << "[";
    
    }
}