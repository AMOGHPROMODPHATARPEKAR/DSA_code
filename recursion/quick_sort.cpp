#include<iostream>
using namespace std;
int count=0;
int partition(int a[],int l,int h)
{
int pivoti=a[l];
int i=l;
int j=h+1;
while(i<j)
{
    do{
        i++;
    }while(a[i]<pivoti);
do{
    j--;
}while(a[j]>pivoti);
if(i<j)
swap(a[i],a[j]);
}

swap(a[l],a[j]);

return j;

}
void quicksort(int a[], int l, int h) {
    if (l < h) {
        int p = partition(a,l,h);
        count++;
        quicksort(a, l,p-1);
        quicksort(a, p+1, h);
        
    }
}
int main()
{
    int a[10],n,i;
   cout<<"enter number of elements\n";
    cin>>n;
    cout<<"enter elements\n";
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<"before sorting \n";
     for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    quicksort(a,0,n-1);
    cout<<"tc = "<<count<<endl;
    cout<<"after sorting\n";
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}