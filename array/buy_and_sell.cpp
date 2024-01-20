#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// brute force
    int maxProfit(vector<int>& prices) {
       int maxi = INT16_MIN;
       int profit =0;
        for(int i=0;i<prices.size()-1;i++)
        {
            for(int j=i+1;j<prices.size();j++)
            {
                if(prices[i]<prices[j])
                {
                    profit = prices[j]-prices[i];
                    maxi = max(maxi,profit);
                }
            }
        }
        if(maxi == INT16_MIN)
        {
            return 0;
        }
        return maxi;
    }
//optimal using DP
int maxProfit1(vector<int>& prices) {
       int mini= prices[0];
       int profit =0;
        for(int i=1;i<prices.size();i++)
        {
            int cost  =  prices[i] - mini;
             profit = max(profit,cost);
             mini = min(mini,prices[i]);
                
        }
        
        return profit;
    }
int main()
{
    vector<int> a = {7,2,4,2,1};
    cout<<"MAX  profit is "<<maxProfit1(a);
}