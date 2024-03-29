    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int s=0;
        int e=row*col-1;
        
        while(s<=e){
        int mid=s+(e-s)/2;

            int ele= matrix[mid/col][mid%col];

            if(ele==target){
                return 1;
            }
            if(target<ele){
                e=mid-1;
            }
            else{
                s=mid+1;
            }

        }
        return 0;
    }