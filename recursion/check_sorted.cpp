     #include <iostream>
using namespace std;

bool issorted(int a[],int n)
{ 
if(n==0||n==1){
    return true;
}
if(a[0]>a[1])
{
    return false;
}
else{
    return issorted(a+1,n-1);//remaining part 
}
}
int main()
{ 
    int ar[]={1,2,3,3,5};
    if(issorted(ar,5)){
        cout<<"sorted"<<endl;
    }else{
        cout<<"not sorted"<<endl;
    }
}