#include<iostream>
using namespace std;
int pivot(int a[], int n){
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
int main(){

    int a[5]={4,5,1,2,3};
    int index= pivot(a,5);
    cout<<"the pivot index is "<<index;
}