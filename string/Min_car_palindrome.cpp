bool isPalindrome(string s)
{
	int n=s.length();
	int j;

	for(int i=0,j=n-1;i<=j;i++,j--)
	{
		if(s[i] != s[j]) return false;
	}
	return true;
}

    int minChar(string str){
       int cnt=0;

	while(str.length()>0)
	{
		if(isPalindrome(str))
        {
			break;
		}
		else
		{
			cnt++;

			str.erase(str.begin()+str.length()-1);
		}
	}

	return cnt;
	
    }