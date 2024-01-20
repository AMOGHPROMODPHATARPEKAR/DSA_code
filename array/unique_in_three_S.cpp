int singleElement(int arr[] ,int N) {
        unordered_map<int,int>mp;
        for(int i=0;i<N;i++)
        {
            mp[arr[i]]++;
        }
        for(auto i:mp)
        {
            if(i.second == 1)
            {
                return i.first;
            }
        }
        
    }
int singleElement(int arr[], int N) {
    int res = 0;

    for (int i = 0; i < 32; i++) {
        int setbit = 0;

        // Count the number of elements with the ith bit set
        for (int j = 0; j < N; j++) {
            if ((arr[j] & (1 << i)) != 0)
                setbit++;
        }

        // If the count is not a multiple of 3, set the ith bit in the result
        if ((setbit % 3) == 1)
            res = res | (1 << i);
    }

    return res;
}
