int firstUniqChar(string s) {
        int h[26];
        
        for(int i=0;i<s.length();i++)
        {
            h[s[i]-'a']++;
        }
        
        for(int i=0;i<s.length();i++)
        {
            if(h[s[i]-'a'] == 1) return i;
        }
        
        return -1;
    }