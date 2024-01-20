#include<iostream>
#include<vector>
using namespace std;
 bool isSafe(int x,int y,int n, vector<vector<int>>visited,vector<vector<int>> &m)
    {
        if((x>=0 && x<n) &&(y>=0 && y<n)&&(visited[x][y]==0)&&(m[x][y]==1))
        {
            return true;
        }
        else{
            return false;
        }
    }
void solve(vector<vector<int>> &m,int n,vector<string> &ans,int x,int y, vector<vector<int>>visited,string path)
{
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    visited[x][y]=1;
    //down
    int newx=x+1;
    int newy=y;
    if(isSafe(newx,newy,n,visited,m))
    {
        solve(m,n,ans,newx,newy,visited,path+'D');
    }
    
        //left
     newx=x;
     newy=y-1;
    if(isSafe(newx,newy,n,visited,m))
    {

        solve(m,n,ans,newx,newy,visited,path+'L');

    }
    
    //right
     newx=x;
     newy=y+1;
    if(isSafe(newx,newy,n,visited,m))
    {

        solve(m,n,ans,newx,newy,visited,path+'R');

    }
    
            //up
     newx=x-1;
     newy=y;
    if(isSafe(newx,newy,n,visited,m))
    {

        solve(m,n,ans,newx,newy,visited,path+'U');

    }
    
    visited[x][y]=0;
}
//  TC-O(Y^n^2) SC-O(n*m)
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        if(m[0][0]==0){
            return ans;
        }
        int scrx=0,scry=0;
        vector<vector<int>>visited=m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[i][j]=0;
            }
        }
        
        string path="";
        solve(m,n,ans,scrx,scry,visited,path);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
    int main(){
        
    }