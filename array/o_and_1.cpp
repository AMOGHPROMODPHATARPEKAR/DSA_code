#include<iostream>
 #include<algorithm>
using namespace std;
int main()
{
    int a[6]={1,1,0,0,0,1};
    int i=0,j=5;
    while(i<j)
    {
        while(a[i]==0)
        i++;
        while(a[j]==1)
        j--;
        if(i<j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
     for(int i=0;i<6;i++)
    {
        cout<<a[i]<<" ";
    }
}