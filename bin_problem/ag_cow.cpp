#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> a, int n,int m,int mid){
    int cow=1;
    int last= a[0];
    for(int i=0;i<n;i++){
        if(a[i]-last >= mid){
            cow++;
            if(cow==m){
                return true;
            }
            last= a[i];
        }
    }
 return false;
}

int allocate(vector<int> a, int n,int m){
    sort(a.begin(),a.end());
    int s=0;
    int maxi=-1;
    for(int i=0;i<n;i++){
        maxi=max(maxi,a[i]);
    }
    int e=maxi;
    int ans=-1;
    int mid= s + (e-s)/2;

        while(s<=e){
        if(isPossible(a,n,m,mid))
        {
            ans=mid;
            s= mid+1;
        }
        else{
            e=mid-1;
        }
         mid=s+(e-s)/2;
    }return ans;

}

int main(){
vector<int>a={4,2,1,3,6};
cout<<"answer  "<<allocate(a,5,2);
}