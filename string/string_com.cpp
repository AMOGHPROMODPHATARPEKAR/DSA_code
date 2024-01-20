    int compress(vector<char>& chars) {
        int i=0;
        int ansindex=0;
        int n=chars.size();
        while(i<n){
            int j=i+1;
            while(j<n &&chars[i]==chars[j]){
                j++;
            }//break if new char is encounterd
            chars[ansindex++]=chars[i];
            
            int count=j-i;
            //convert to string
            if(count>1){
                string c=to_string(count);
                for(char i:c){
                    chars[ansindex++]=i;
                }
            }
            i=j;
        }
        return ansindex;
    }