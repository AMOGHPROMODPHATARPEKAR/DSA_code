#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//approach 1:brute  TC:O(n2logn)  sc:O(n2)
int getKthLargest(vector<int> &arr, int k) {
    vector<int> sumStore;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }

    sort(sumStore.begin(), sumStore.end());

    return sumStore[sumStore.size() - k];
}
//heap better approach tc:O(n2) sc:O(k)
int getKthLargest_opt(vector<int> &arr, int k)
{
	priority_queue<int,vector<int>,greater<int>>minheap;
int n= arr.size();
	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=i;j<n;j++)
		{
			sum+=arr[j];
			if(minheap.size()<k)
			{
				minheap.push(sum);
			}
			else if(sum > minheap.top())
			{
				minheap.pop();
				minheap.push(sum);
			}
		}
	}
	
	return minheap.top();
}
int main() {
    // Example usage
    vector<int> arr = {1, 3, 2, 5, 4};
    int k = 2;

    int result = getKthLargest(arr, k);

    cout << "Kth Largest Sum: " << result << endl;

    return 0;
}
