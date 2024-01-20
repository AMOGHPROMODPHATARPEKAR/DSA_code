#include<iostream>
using namespace std;
int bin(int a[], int n,int key){
    int s=0,mid;
    int e=n-1;
    while(s<=e){
        mid=s+(e-s)/2;
        if(a[mid]==key){
            return mid;
        }
        if(key>a[mid]){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return -1;
}
int main(){

    int a[5]={2,3,6,8,10};
    int index= bin(a,5,1);
    cout<<"the element 6 is at index "<<index;
}