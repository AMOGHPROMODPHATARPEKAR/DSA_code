vector<int> JobScheduling(Job arr[], int n) 
    { 
       sort(arr,arr+n,cmp);
       
       int maxDeadline = INT_MIN;
       for(int i=0;i<n;i++)
       {
           maxDeadline = max(maxDeadline,arr[i].dead);
       }
       
       vector<int>schedule(maxDeadline+1,-1);
       int count=0;
       int maxProfit = 0;
       for(int i=0;i<n;i++)
       {
           int curprofit = arr[i].profit;
           int curdead = arr[i].dead;
           int curid = arr[i].id;
           
           for(int k=curdead ;k>0;k--)
           {
               if(schedule[k] == -1)
               {
                   count++;
                   schedule[k] =curid;
                   maxProfit += curprofit;
                   break;
               }
           }
       }
       vector<int>ans;
       ans.push_back(count);
       ans.push_back(maxProfit);
       return ans;
       
    } 