int sum_of_digits(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    
    void solve(int n, vector<int> &v){
        for(int i=2;i*i<=n;i++){
            while(n%i==0){
                v.push_back(i);
                n=n/i;
            }
        }
        if (n>1) v.push_back(n);
    }
    
    int sum_of_digits_primeFactors(vector<int> &v){
        int sum=0;
        for(auto it: v){
            sum+=sum_of_digits(it);
        }
        return sum;
    }
    
    int smithNum(int n) {
       
        vector<int> list_of_primeFactors; 
        solve(n,list_of_primeFactors);   
        if (list_of_primeFactors.size()==1) return 0; 
        int sum1=sum_of_digits(n); 
        int sum2=sum_of_digits_primeFactors(list_of_primeFactors); 
        return sum1==sum2;
    }