//t O(n) sc O(1)
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	
	int hash[n+1]={0};
	for(int i=0;i<n;i++)
	{
		hash[arr[i]]++;
	}
	
	int rep=-1;
	int miss=-1;
	for(int i=1;i<=n;i++)
	{
		if(hash[i]==2)
		{
			rep=i;
		}
		if(hash[i]==0)
		{
			miss=i;
		}
		if(rep !=-1 && miss != -1)
		{
			break;
		}
	}
	return make_pair(miss,rep);
}

//approach 2 maths
pair<int,int> missingAndRepeating(vector<int> &a, int n)
{
	long long sn=(n*(n+1))/2;
	long long s2n=(n*(n+1)*(2*n+1))/6;
   long long s=0,s2=0;
	for(int i=0;i<n;i++)
	{
    s+=a[i];
	s2+=( long long)a[i] * ( long long)a[i];
	}
	int val1=s-sn;//x-y
    int val2=s2-s2n ;//(x+y)(x-y);
	val2=val2/val1;//x+y

	long long x= (val1 + val2)/2;
	long long y= val2-x;
	return {int(y),int(x)};
}
pair<int,int> missingAndRepeating(vector<int> &a, int n)
{
	//xor method
	int xr=0;
	for(int i=0;i<n;i++)
	{
     xr^=a[i];
	 xr^=(i+1);
	}
	int bitNo=0;
	while(1)
	{
		if((xr & (1<<bitNo)) !=0)
		{
			break;
		}
		bitNo++;
	}
	int zero=0;
    int one=0;

	for(int i=0;i<n;i++)
	{
		if((a[i] & (1<<bitNo)) != 0)
		{
			one = one ^ a[i];
		}
		else{
			zero =zero^a[i];
		}
	}

	for(int i=1;i<=n;i++)
	{
		if((i & (1<<bitNo)) != 0)
		{
			one = one ^ i;
		}
		else{
			zero =zero^i;
		}
	}

	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(a[i] == zero)cnt++;
	}

	if(cnt == 2) return {one,zero};
	return{zero,one};

	
}