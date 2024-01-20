  #include<iostream>
  #include<vector>
  #include<algorithm>
using namespace std;
int pivot(vector<int>& a, int n){
          int s=0;
        int e=n-1;
        while(s<e)
        { 
            int mid=s+(e-s)/2;
            if(a[mid]>=a[0])
            {
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
}

int bin(vector<int> &a,int start,int end, int n,int key){
    int s=start,mid;
    int e=end;
    while(s<=e){
        mid=s+(e-s)/2;
        if(a[mid]==key){
            return mid;
        }
        if(key>a[mid]){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return -1;
}

    int search(vector<int>& nums, int target) {
        int piv= pivot(nums,nums.size());
        if(target>= nums[piv] && target <=nums[nums.size()-1])
        {
            return bin(nums,piv,nums.size()-1,nums.size(),target);
        }
        else{
            return bin(nums,0,piv-1,nums.size(),target);
        }
    }
    int main()
    {
        vector<int>a={7,9,1,2,3};
        cout<<"index of 2 is "<<search(a,2);
    }