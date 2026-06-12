#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int row = mid / m;
            int col = mid % m;

            if (target == mat[row][col])
                return true;
            else if (target < mat[row][col])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int target;
    cin >> target;

    Solution obj;

    if (obj.searchMatrix(mat, target))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}