class Solution {
public:
  bool check(vector<int>base,vector<int>newBox)
 {
     if(newBox[0]<=base[0] && newBox[1]<=base[1] && newBox[2]<= base[2])
     {
         return true;
     }
     else
     {
         return false;
     }
 }
int solveOp(int n,vector<vector<int>>& a)
    {
        vector<int>curRow(n+1,0);
        vector<int>nextRow(n+1,0);
        
        for(int cur=n-1;cur>=0;cur--)
        {
            for(int prev=cur-1;prev>=-1;prev--)
            {
                 //include
                int take=0;
                if(prev == -1 || check(a[cur],a[prev]))
                    take=a[cur][2]+nextRow[cur+1];
                
                //exclude
                int notTake = nextRow[prev+1];
                
                curRow[prev+1] =  max(take,notTake);
            }
            nextRow=curRow;
        }
        
       
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a:cuboids)
        {
            sort(a.begin(),a.end());
        }

        sort(cuboids.begin(),cuboids.end());

        return solveOp(cuboids.size(),cuboids);
    }
};