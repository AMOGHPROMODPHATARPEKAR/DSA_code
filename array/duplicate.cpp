#include<iostream>
using namespace std;
int floyd(int nums[])
{
    int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}
int main()
{
    int a[6]={5,1,2,3,4,2};
    int ans=0;
    for(int i=0;i<6;i++)
    {
        ans=ans^a[i];
    }
   for(int i=1;i<6;i++)
    {
        ans=ans^i;
    }
    cout<<ans<<endl;
    cout<<"Duplicate by flyd cycle detection is "<<floyd(a);
   
}