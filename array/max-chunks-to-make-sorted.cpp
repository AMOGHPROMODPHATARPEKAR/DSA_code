//[o,n-1] always
int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0;
        int curMax= arr[0];
        int n=arr.size();

        for(int i=0;i<n;i++)
        {
            curMax = max(curMax,arr[i]);

            if(curMax == i)
                chunks++;
        }
        return chunks;
    }