#include <iostream>
#include <vector>

using namespace std;

vector<int> antiDiagonalPattern(vector<vector<int>> matrix) {
    vector<int> ans;
    int r = matrix.size();
    int k = 0;

    for (int i = 0; i < r; i++) {
        k = 0;
        for (int j = i; j >= 0; j--) {
            ans.push_back(matrix[k++][j]);
        }
    }

    for (int i = 1; i < r; i++) {
        k = i;
        for (int j = r - 1; j >= i; j--) {
            ans.push_back(matrix[k++][j]);
        }
    }

    return ans;
}

int main() {
    // Example usage
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = antiDiagonalPattern(matrix);

    // Displaying the result
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
