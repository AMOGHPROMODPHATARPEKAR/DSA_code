#include<bits/stdc++.h>

using namespace std;

int leftMax(int index, vector<int>& ht) {
    int maxi = INT_MIN;

    for (int i = 0; i < index; i++) {
        if (ht[i] > maxi) {
            maxi = ht[i];
        }
    }
    return maxi;
}

int rightMax(int index, vector<int>& ht) {
    int maxi = INT_MIN;

    for (int i = index + 1; i < ht.size(); i++) {
        if (ht[i] > maxi) {
            maxi = ht[i];
        }
    }
    return maxi;
}
//TC-O(N2)
int trap(vector<int>& height) {
    int n = height.size();
    vector<int> ans(n);
    int water = 0;

    for (int i = 1; i < n - 1; i++) {
        ans[i] = min(leftMax(i, height), rightMax(i, height)) - height[i];
    }

    for (int i = 1; i < n - 1; i++) {
        if (ans[i] > 0) {
            water += ans[i];
        }
    }

    return water;
}

int trapOp(vector<int>& height) {
        int n=height.size();
        vector<int>pre(n);
        
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,height[i]);
            pre[i]=maxi;
        }
        
        vector<int>suf(n);
        maxi=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            maxi=max(maxi,height[i]);
            suf[i]=maxi;
        }

        int water=0;
        for(int i=1;i<n-1;i++)
        {
            water += min(pre[i],suf[i]) - height[i];
        }
        
        return water;
    }

int trapOP2(vector<int>& height) {
       int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        res += maxLeft - height[left];
      }
      left++;
    } else {
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        res += maxRight - height[right];
      }
      right--;
    }
  }
  return res;
    }

int main() {
    // Example Usage
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int result = trap(height);

    // Displaying the result
    cout << "Trapped water: " << result << " units" << endl;

    return 0;
}
