#include <bits/stdc++.h>
using namespace std;

int solve(int *arr, int n, int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);

    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans=0;
     ans +=arr[maxi.front()]+arr[mini.front()];
    for(int i=k;i<n;i++)
    {
        
        //next window
        
        // removal
        while (!maxi.empty() && i- maxi.front()>=k)
        {
            maxi.pop_front();
        }
         while (!mini.empty() && i- mini.front()>=k)
        {
            mini.pop_front();
        }
        //addition
         while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        ans +=arr[maxi.front()]+arr[mini.front()];
    }
   
    return ans;
}
//brute force
int SumOfKsubArray(int arr[], int N, int k)
{
    // To store final answer
    int sum = 0;
 
    // Find all subarray
    for (int i = 0; i < N; i++) {
        // To store length of subarray
        int length = 0;
        for (int j = i; j < N; j++) {
            // Increment the length
            length++;
 
            // When there is subarray of size k
            if (length == k) {
                // To store maximum and minimum element
                int maxi = INT_MIN;
                int mini = INT_MAX;
 
                for (int m = i; m <= j; m++) {
                    // Find maximum and minimum element
                    maxi = max(maxi, arr[m]);
                    mini = min(mini, arr[m]);
                }
 
                // Add maximum and minimum element in sum
                sum += maxi + mini;
            }
        }
    }
    return sum;
}
int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    cout << SumOfKsubArray(arr, 7, 4) << endl;
    cout << solve(arr, 7, 4) << endl;
    return 0;
}