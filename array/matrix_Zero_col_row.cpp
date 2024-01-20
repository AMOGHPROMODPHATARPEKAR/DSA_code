void zero(vector<vector<int>>&matrix,int zi,int zj)
     {
       for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(i == zi || j == zj)
                {
                    matrix[i][j]=0;
                }
            }
        }
     }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>ans;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == 0)
                {
                    ans.push_back(make_pair(i,j));
                }
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            zero(matrix,ans[i].first,ans[i].second);
        }
    }