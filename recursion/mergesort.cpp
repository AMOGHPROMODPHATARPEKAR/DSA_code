#include<iostream>
using namespace std;
int inv=0;
void merge(int a[],int l,int m,int h)
{
    int n1=m-l+1;
    int n2=h-m;
    int *left = new int[n1];
    int *right = new int[n2];
    int i,j,k=0;
    for(i=0;i<n1;i++)
    left[i]=a[l+i];

    for(j=0;j<n2;j++)
    right[j]=a[m+1+j];

    i=0;
    j=0;
    k=l;
        while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
            inv++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = right[j];
        j++;
        k++;
    }
    delete []left;
    delete []right;
}

void mergesort(int a[], int l, int h) {
    if (l < h) {
        int mid = l+ (h-l) / 2;

        mergesort(a, l, mid);
        mergesort(a, mid + 1, h);
        merge(a, l, mid, h);
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
    mergesort(a,0,n-1);
    cout<<"after sorting\n";
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<"\n Inversion "<<inv<<endl;
    return 0;
}
