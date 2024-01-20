#include<iostream>
using namespace std;
int main()
{
    int a[6]={1,2,2,1,2,3};
int count[6]={0};
bool ans=true;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(a[i]==a[j])
            count[i]++;
        }
    }
   for (int i = 0; i < 3; i++)
   {
     if(count[i]==count[i+1])
ans=false;
   }
   
   if(ans){
    cout<<"Unique";
   }else
   {
    cout<<"not";
   }
}
// bool uniqueOccurrences(vector<int>& arr) {
    //   int i = 0;
    //     sort(arr.begin(),arr.end());
    //     vector<int> ans;
    //     while (i < arr.size()){
    //         int count = 1;
    //         for (int j = i+1; j< arr.size(); j++){
    //             if (arr[i] == arr[j])
    //                 count++;
    //         }
    //         ans.push_back(count);
    //         i = i + count;
    //     }
    //     sort(ans.begin(),ans.end());
    //     for (int i = 0; i < ans.size() - 1; i++){
    //         if (ans[i] == ans [i+1])
    //             return false;
    //     }
    //     return true;
    // }