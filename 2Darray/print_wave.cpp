#include<bits/stdc++.h>
using namespace std;


void wave(int a[][4]){
    for(int col=0;col<4;col++){
        if(col&1){
            //odd
            for(int row=2;row>=0;row--){
                cout<<a[row][col]<<" ";
            }
        }else{
            for(int row=0;row<3;row++){
                cout<<a[row][col]<<" ";
            }
        }
    }
}
int main()
{
int a[3][4];
for(int i=0;i<3;i++){
    for(int j=0;j<4;j++){
        cin>>a[i][j];
    }
}
wave(a);

}