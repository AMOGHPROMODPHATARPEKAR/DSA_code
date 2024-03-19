#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// brute force
void merge_array1(vector<int>& v1, int m, vector<int>& v2, int n) {
int i=0,j=0;
vector<int>v3;
while (i<m &&j<n)
{
   if(v1[i]<v2[j])
   {
    v3.push_back(v1[i]);
    i++;
   }else{
    v3.push_back(v2[j]);
    j++;
   }
}

while (i<m)
{
     v3.push_back(v1[i]);
    i++;
}
while (j<n)
{
   v3.push_back(v2[j]);
    j++;
}
v1 = v3;
    }
    //litte optimised
    void merge_array2(vector<int>& v1, int m, vector<int>& v2, int n) {
  int left=m-1;
  int right=0;
  while(left>=0 && right<n)
  {
      if(v1[left]>v2[right])
      {
          swap(v1[left],v2[right]);
          left--;
          right++;
      }
      else
      {
          break;
      }
  }
  sort(v1.begin(),v1.begin()+m);
  sort(v2.begin(),v2.end());
  int t=n;
  while(t)
  {
      v1.pop_back();
      t--;
  }
  for(int i=0;i<n;i++)
  v1.push_back(v2[i]);
    }
    //optimal gap method 
  void swap_grt(vector<int>& v1, vector<int>& v2, int i1,int i2)
  {
    if(v1[i1]>v2[i2])
    {
        swap(v1[i1],v2[i2]);
    }
  }
    void merge3(vector<int>& v1, int m, vector<int>& v2, int n)
    {
        int len =m+n;
        int gap = (len/2) +( len%2);
        while(gap>0)
        {
            int left=0;
            int right = gap;
            while (right<len)
            {
                //arr1 arr2
                if(left<m && right>=m)
                {
                    swap_grt(v1,v2,left,right-m);
                }
                //arr2 arr2
               else if(left>=m )
                {
                    swap_grt(v2,v2,left-m,right-m);
                
                }
                //arr1 arr1
               else
                {
                    swap_grt(v1,v1,left,right);

                }
                left++;
                right++;
            }
            if(gap == 1)break;

            gap= (gap/2) + (gap%2);
        }
    }
int main()
{
    // vector<int>v1={2,3,4,0,0,0};
    vector<int>v1= {1, 1, 3, 6 ,9, 9} ;
    vector<int>v2={1, 2 ,3 ,4 ,8 ,8};
    merge3(v1,6,v2,6);
    for(int i=0;i<12;i++)
    cout<<v1[i]<<" ";
}