#include<bits/stdc++.h>
using namespace std;

void col_sum(int a[][4]){
    for(int j=0;j<4;j++){
        int sum=0;
    for(int i=0;i<3;i++){
        sum+=a[i][j];
    }
    cout<<"sum is col "<<sum<<endl;
}

}
int largest_sum(int a[][4])
{ int maxi=INT16_MIN;
int colIndex=-1;
        for(int j=0;j<4;j++){
        int sum=0;
    for(int i=0;i<3;i++){
        sum+=a[i][j];
    }
   if(sum>maxi){
    maxi=sum;
    colIndex=j;
   }
}
return colIndex;
}
int main()
{
int a[3][4];
for(int i=0;i<3;i++){
    for(int j=0;j<4;j++){
        cin>>a[i][j];
    }
}
int sum_r[3]={0};
for(int i=0;i<3;i++){
    for(int j=0;j<4;j++){
        sum_r[i]+=a[i][j];
    }
}
for(int i=0;i<3;i++){
cout<<"sum of row "<<i+1<<" is "<<sum_r[i]<<endl;
}
col_sum(a);
cout<<"max at "<<largest_sum(a);
}