#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                if (j != i + 1 && arr[j] == arr[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)arr[i] + arr[j] + arr[left] + arr[right];

                    if (sum < target)
                        left++;
                    else if (sum > target)
                        right--;
                    else {
                        ans.push_back({arr[i], arr[j], arr[left], arr[right]});
                        left++;
                        right--;

                        while (left < right && arr[left] == arr[left - 1]) left++;
                        while (left < right && arr[right] == arr[right + 1]) right--;
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    int n, target;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    Solution obj;
    vector<vector<int>> result = obj.fourSum(arr, target);

    for (auto &quad : result) {
        for (int x : quad) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}