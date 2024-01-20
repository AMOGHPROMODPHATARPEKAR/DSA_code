#include <iostream>
#include <vector>
using namespace std;
    void rotate(vector<int>& nums, int k) {
        vector<int>temp(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            temp[(i+k)%nums.size()]=nums[i];
        }
        nums=temp;

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
    v.push_back(1);
    v.push_back(5);
    v.push_back(4);
    v.push_back(8);
    print(v);
    cout << "afterr \n";
   rotate(v,2);
    print(v);
}