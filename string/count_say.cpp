string countAndSay(int n) {
        if(n==1)
            return "1";
        
        string s = countAndSay(n-1);

        string res="";
        int count=0;

        for(int i=0;i<s.length();i++)
        {
            count++;
            if(i == s.length()-1 || s[i]!= s[i+1] )
            {
                res=res+to_string(count)+s[i];
                count=0;
            }
        }
        return res;
    }

    1->"1"
    2->"11"
    3->"21"
    4->"1211"