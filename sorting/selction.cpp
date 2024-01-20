#include<iostream>
using namespace std;
void selection(int a[],int n)
{
    int i,j,c=0,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
       
        for(j=i+1;j<n;j++)
        { c++;
            if(a[j]<a[min])
            min=j;
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
 cout<<"T C= "<<c<<endl;
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
    selection(a,n);
    cout<<"after sorting\n";
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
} 
//bc,wc,ac-(n2)
//used when small size