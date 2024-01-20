#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// brute force
void sortColors(vector<int> &nums)
{
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            c0++;
        }
        else if (nums[i] == 1)
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }
    int i = 0;
    while (c0)
    {
        nums[i] = 0;
        i++;
        c0--;
    }
    while (c1)
    {
        nums[i] = 1;
        i++;
        c1--;
    }
    while (c2)
    {
        nums[i] = 2;
        i++;
        c2--;
    }
}

// dutch national flag alogorithm(3pointer approach)

void sort_0_1_2(vector<int>&a)
{
    int low=0;
    int mid=0;
    int high = a.size()-1;

    while(mid<=high)
    {
        if(a[mid] == 0)
        {
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if(a[mid] == 1)
        {
            mid++;
        }
        else{
            swap(a[mid],a[high]);
            high--;
        }
    }
}
int main()
{
    vector<int> a = {1, 2, 0, 0, 2, 0, 1};
    // sortColors(a);
    sort_0_1_2(a);

    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }
}