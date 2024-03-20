bool checkSame(int index,string haystack, string needle)
    {
        for(int i=0;i<needle.size();i++,index++)
        {
            if(haystack[index] != needle[i])
            {
                return false;
            }
        }
        return true;
    }

    int strStr(string haystack, string needle) {
    
    for(int i=0;i<haystack.size();i++)
    {
        if(haystack[i]== needle[0])
        {
           if(checkSame(i,haystack,needle))
           {
            return i;
           }
        }
    }
    return -1;
    }