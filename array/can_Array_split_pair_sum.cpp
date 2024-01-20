#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool canPair(vector<int> nums, int k) {
       int n = nums.size();
        if(n & 1) return false;
        unordered_map<int,int> mpp;
        //mkaing a frequency array for pairing the elements
        for(int i =0;i< n;i++){
            mpp[nums[i] % k]++;
        }
        for(int i =0;i< n;i++){
            //checking for availablw pair
            if(mpp[(k - nums[i] % k) % k] > 0){
                mpp[(k - nums[i] % k) % k]--;
            }
            else{
                //if pairing is not possible
                return false;
            }
        }
        return true;
    }

int main() {
 vector<int> nums = {9, 7, 5, 3};
    int k = 6;

    if (canPair(nums, k)) {
      cout << "Elements can be paired." <<endl;
    } else {
       cout << "Elements cannot be paired." <<endl;
    }

    return 0;
}