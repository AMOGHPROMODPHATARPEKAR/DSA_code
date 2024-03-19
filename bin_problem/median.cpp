int smallerEqual(vector<vector<int>> &matrix, int mid)
{
    int cnt=0;
    for(int i=0;i<matrix.size();i++)
    {
        vector<int>::iterator upper =  upper_bound(matrix[i].begin(),matrix[i].end(),mid);
        cnt+= (upper - matrix[i].begin());
    }
    return cnt;
}
int median(vector<vector<int>> &matrix, int m, int n) {
    int low=1;
    int high=1e9;

    int req=n*m/2;

    while(low<=high)
    {
    int mid=low +(high-low)/2;
    int se = smallerEqual(matrix,mid);
    if(se <= req) low=mid+1;
    else
        high=mid-1; 
    }
    return low;
}
TC: log2(10^9)*n*log2(m)
