
int func(int num,int n,int m)
{
  long long ans=1;
  for(int i=1;i<=n;i++)
  {
    ans=num*ans;
    if(ans>m) return 2;
  }
  if(ans == m) return 1;
  return 0;

}

int NthRoot(int n, int m) {
  
  int low=1,high = m;
  while(low<=high)
  {
    int mid = low + (high-low)/2;
    int ans=func(mid,n,m);
    if(ans==1) return mid;
    else if (ans == 2) high=mid-1;
    else low=mid+1;
  }
  return -1;
}   