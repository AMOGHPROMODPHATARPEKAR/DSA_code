//brute TC- O(n2) sc-O(n)
int verify(vector<int>temp,int l,int r)
    {
        sort(temp.begin(),temp.end());
        int n=temp.size();
        int max = temp[n-1];
        if(max >=l && max <=r)
        {
            return 1;
        }
        return 0;
    }
    long countSubarrays(int a[], int n, int L, int R)
    {
        vector<int>temp;
       long cnt=0;
       for(int i=0;i<n;i++)
       {   temp.clear();
           for(int j=i;j<n;j++)
           {
               temp.push_back(a[j]);
               cnt+=verify(temp,L,R);
           }
       }
       return cnt;
        
    }

    //optimised
     long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        int start = -1;
        int end = -1;
        
        long count = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > R) {
                start = i;
                end = i;
                continue;
            }
            
            if(a[i] >= L) {
                end = i;
            }
            
            count += (end - start);
        }
        
        return count;
        
    }