#include<iostream>
#include<vector>
using namespace std;
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1;
        while(s<e)
        { 
            int mid=s+(e-s)/2;
            if(arr[mid]<arr[mid+1])
            {
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
    }
int main(){

    vector<int>a ={2,3,6,3,2,1};
    int index= peakIndexInMountainArray(a);
    cout<<"peak at index "<<index;
}