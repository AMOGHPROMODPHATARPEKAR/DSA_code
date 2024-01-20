#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
       int index =-1;
       int n= nums.size();

       //step1: find the break point

       for(int i =n-2;i>=0;i--)
       {
           if(nums[i]<nums[i+1])
           {
               index =i;
               break;
           }
       }

       if(index == -1)
       {
           reverse(nums.begin(),nums.end());
           return;
       }

       //step2 : first  just a greater number than index and swap

       for(int i=n-1;i>index;i--)
       {
           if(nums[i] > nums[index])
           {
               swap(nums[i],nums[index]);
               break;
           }
       }

       //step3 reverse the next part after index

       reverse(nums.begin()+index+1,nums.end());
        
    }
int main()
{
  vector<int>a ={1,2,3,9,8,0};
  nextPermutation(a);
  for(int i=0;i<a.size();i++)
  {
    cout<<a[i]<<" ";
  }
    return 0;
}