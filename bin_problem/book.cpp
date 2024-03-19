#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> a, int n,int m,int mid){
    int student=1;
    int page_sum=0;
    for(int i=0;i<n;i++){
        if(page_sum+a[i] <= mid){
            page_sum+=a[i];
        }
        else{
            student++;
            if(student>m || a[i]>mid){
                return false;
            }
            page_sum=a[i];
        }
        
    }
    return true;
}
//n-books m-students
int allocate(vector<int> a, int n,int m){
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    int e=sum;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(isPossible(a,n,m,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
         mid=s+(e-s)/2;
    }return ans;
}

int main(){
vector<int>a={10,40,20,30};
cout<<"answer  "<<allocate(a,4,2);
}