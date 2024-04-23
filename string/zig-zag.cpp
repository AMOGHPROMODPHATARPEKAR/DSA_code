string convert(string s, int numsRows) {
        if(numsRows == 1) return s;

        string res="";

        for(int i=0;i<numsRows;i++)
        {
            int increment = 2*(numsRows-1);
            for(int j=i;j<s.length();j+=increment){
                res+=s[j];
                if(i>0 && i< numsRows-1 && (j+increment - 2*i) < s.length())
                {
                    res+=s[j+increment - 2*i];
                }
            }
        }
        return res;
    }

// Input
// s =
// "PAYPALISHIRING"
// numRows =
// 3  
// Expected
// "PAHNAPLSIIGYIR"

explaination
P   A   H
A P L S I
Y   I   R