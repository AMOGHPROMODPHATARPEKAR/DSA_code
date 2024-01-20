#include<iostream>
using namespace std;
void insertion(int a[],int n)
{
    int i,j,key,c=0;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        c++;
        while((j>=0)&&(key<a[j]))
        {
            a[j+1]=a[j];
            j--;
            c++;
        }
        a[j+1]=key;
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
    insertion(a,n);
    cout<<"after sorting\n";
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}
// why?
// adaptable,stable,smll size
// TC SC
// sc-constant
// tc-bc-O(n),wc,ac-O(n2)