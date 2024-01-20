#include <iostream>
#include <vector>
using namespace std;
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();

        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i]){
                count++;
            }
        }
        if(nums[n-1]>nums[0]){
            count++;
        }
        return count<=1;
    }
void print(vector<int> a)
{
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{

    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    print(v);
    
   if(check(v)){
cout << "yes \n";
   }
    else{
        cout<<"false";
    }
}