
#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second > (nums.size()/2))
            {
                return it.first;
            }
        }
        return -1;
    }
 //mo0ne's voting algorithm
    int majorityElement_op(vector<int>& nums) {
    

     int cnt=0;
     int el;
     for(int i=0;i<nums.size();i++)
     {
         if(cnt==0)
         {
             cnt=1;
             el=nums[i];
         }else if(nums[i] == el)
         {
             cnt++;
         }else{
             cnt--;
         }
     }
     int cnt1=0;
     for(int i=0;i<nums.size();i++)
     {
         if(nums[i] == el)
         {
             cnt1++;
         }
     }
     if(cnt1 >( nums.size()/2))
     {
         return el;
     }
     else
     return -1;
    }

    int main()
    {
        vector<int>a={1,2,2,3,2};
        // cout<<"majority element is "<<majorityElement(a);
        cout<<"majority element is "<<majorityElement_op(a);
    }