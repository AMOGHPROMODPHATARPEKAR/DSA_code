int minimumDays(int S, int N, int M){
       int sunday = S/7;
       
       int buydays = S-sunday;
       int total = M*S;
       int ans=0;
       if(total %N == 0)
       {
           ans= total/N;
       }
       else
       {
           ans = total/N +1;
       }
       if(ans <= buydays)
       {
           return ans;
       }
       else
       {
           return -1;
       }
    }