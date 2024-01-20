#include<iostream>
using namespace std;
int first_occ(int a[], int n,int key){
    int s=0,mid;
    int e=n-1;
    int ans=-1;
    while(s<=e){
        mid=s+(e-s)/2;
        if(a[mid]==key){
            ans=mid;
            e=mid-1;
        }
       else if(key>a[mid]){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return ans;
}
int last_occ(int a[], int n,int key){
    int s=0,mid;
    int e=n-1;
    int ans= -1;
    while(s<=e){
        mid=s+((e-s)/2);
        if(a[mid]==key){
            ans=mid;
            s=mid+1;
        }
       else if(key>a[mid]){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return ans;
}
int main(){

    int a[5]={2,3,3,3,10};

    cout<<"the first occurence is at index "<<first_occ(a,5,3)<<endl;
    cout<<"the last occurence is at index "<<last_occ(a,5,3);

}