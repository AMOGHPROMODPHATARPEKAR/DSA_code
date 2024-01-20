#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <bits/stdc++.h> 
int solve(vector<int> value,vector<int> weight, int index, int capacity)
{
	if(index == 0)
	{
		if(weight[0]<=capacity)
		{
			return value[0];
		}else{
			return 0;
		}
	}

	int inc=0;
	if(weight[index]<=capacity)
		inc=value[index]+solve(value,weight,index-1,capacity-weight[index]);

	int excl = solve(value,weight,index-1,capacity);

	return max(inc,excl);	

}

int solveMem(vector<int> value,vector<int> weight, int index, int capacity,vector<vector<int>>&dp)
{
	if(index == 0)
	{
		if(weight[0]<=capacity)
		{
			return value[0];
		}else{
			return 0;
		}
	}

	if(dp[index][capacity] != -1 )
	{
		return dp[index][capacity];
	}

	int inc=0;
	if(weight[index]<=capacity)
		inc=value[index]+solveMem(value,weight,index-1,capacity-weight[index],dp);

	int excl = solveMem(value,weight,index-1,capacity,dp);

	dp[index][capacity] = max(inc,excl);	

	return dp[index][capacity];

}
int solveTab(vector<int> value,vector<int> weight, int n, int capacity)
{
	
  vector<vector<int>>dp(n,vector<int>(capacity+1,0));
  
  //analyse base case
  for(int i=weight[0];i<=capacity;i++)
  {
	  if(weight[0]<=capacity)
	  dp[0][i]=value[0];
	  else
	  dp[0][i]=0;
  }
	
	for(int index=1;index<n;index++)
	{
		for(int w=0;w<=capacity;w++)
		{
			int inc=0;
	    if(weight[index]<=w)
		  inc=value[index]+dp[index-1][w-weight[index]];

	int excl = dp[index-1][w];

	dp[index][w] = max(inc,excl);	

		}
	}

	return dp[n-1][capacity];

}
int solveOpt(vector<int> value,vector<int> weight, int n, int capacity)
{
	
  vector<int>prev(capacity+1,0);
  vector<int>cur(capacity+1,0);

  
  //analyse base case
  for(int i=weight[0];i<=capacity;i++)
  {
	  if(weight[0]<=capacity)
	  prev[i]=value[0];
	  else
	  prev[i]=0;
  }
	
	for(int index=1;index<n;index++)
	{
		for(int w=0;w<=capacity;w++)
		{
			int inc=0;
	    if(weight[index]<=w)
		  inc=value[index]+prev[w-weight[index]];

	int excl = prev[w];

	cur[w] = max(inc,excl);	

		}
		prev=cur;
	}

	return prev[capacity];

}
int solveOpt2(vector<int> value,vector<int> weight, int n, int capacity)
{
	

  vector<int>cur(capacity+1,0);

  
  //analyse base case
  for(int i=weight[0];i<=capacity;i++)
  {
	  if(weight[0]<=capacity)
	  cur[i]=value[0];
	  else
	  cur[i]=0;
  }
	
	for(int index=1;index<n;index++)
	{
		for(int w=capacity;w>=0;w--)
		{
			int inc=0;
	    if(weight[index]<=w)
		  inc=value[index]+cur[w-weight[index]];

	int excl = cur[w];

	cur[w] = max(inc,excl);	

		}
		
	}

	return cur[capacity];

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// return solve(value,weight,n-1,maxWeight);

	// vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	// return solveMem(value,weight,n-1,maxWeight,dp);

	// return solveTab(value,weight,n,maxWeight);
	return solveOpt2(value,weight,n,maxWeight);

}

int main() {
    // Example usage
    vector<int> weight = {2, 3, 4, 5};
    vector<int> value = {3, 4, 5, 6};
    int n = weight.size();
    int maxWeight = 5;

    int result = knapsack(weight, value, n, maxWeight);

    cout << "Maximum value in the knapsack: " << result << endl;

    return 0;
}
