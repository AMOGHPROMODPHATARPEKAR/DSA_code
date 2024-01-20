int solveOp(vector<int>&prices,int fee)
    {
        int n=prices.size();
        vector<int>next(n+1,0);
        vector<int>cur(n+1,0);

        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit =0;
                if(buy)
                {
                    int buyKaro = -prices[index]+ next[0];
                    int skipKaro = 0+ next[1];
                    profit = max(buyKaro,skipKaro);
                }
                else
                {
                    int sellKaro = prices[index] + next[1] - fee;
                    int skipKaro = 0+next[0];
                    profit = max(sellKaro,skipKaro);
                }

                cur[buy] = profit;
            }
            next=cur;
        }

        return next[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solveOp(prices,fee);
    }