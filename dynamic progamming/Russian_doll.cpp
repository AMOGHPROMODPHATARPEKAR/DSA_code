#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int solveOptimal(int n, vector<vector<int>>& env) {
        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(env[0][1]);

        for (int i = 1; i < n; i++) {
            if (env[i][1] > ans.back()) {
                ans.push_back(env[i][1]);
            } else {
                int index = lower_bound(ans.begin(), ans.end(), env[i][1]) - ans.begin();
                ans[index] = env[i][1];
            }
        }

        return ans.size();
    }

    int solveOp(int n, vector<vector<int>> a) {
        vector<int> curRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int cur = n - 1; cur >= 0; cur--) {
            for (int prev = cur - 1; prev >= -1; prev--) {
                // include
                int take = 0;
                if (prev == -1 || a[cur][1] > a[prev][1])
                    take = 1 + nextRow[cur + 1];

                // exclude
                int notTake = nextRow[prev + 1];

                curRow[prev + 1] = max(take, notTake);
            }
            nextRow = curRow;
        }

        return nextRow[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), comp);

        return solveOptimal(n, envelopes);
        // return solveOp(n, envelopes);
    }
};

int main() {
    Solution solution;

    // Example usage:
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    int result = solution.maxEnvelopes(envelopes);

    cout << "Maximum number of nested envelopes: " << result << endl;

    return 0;
}
