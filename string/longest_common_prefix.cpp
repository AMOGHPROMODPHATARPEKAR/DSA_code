 string longestCommonPrefix(vector<string>& strs) {
      string ans ="";
        string t1=strs[0];
        for(int i=1;i<strs.size();i++){
            string temp="";
            string com=strs[i];
            for(int j=0;j<t1.length();j++){
                if(t1[j]!=com[j]){
                    break;
                }else{
                    temp+=t1[j];
                }
            }
            t1=temp;
        }
        ans=t1;
        return ans; 
    }