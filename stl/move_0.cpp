#include <iostream>
#include <vector>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != 0)
        {
            swap(nums[j], nums[i]);
            i++;
        }
    }
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
    v.push_back(0);
    v.push_back(5);
    v.push_back(0);
    v.push_back(8);
    print(v);
    cout << "afterr \n";
   moveZeroes(v);
    print(v);
}