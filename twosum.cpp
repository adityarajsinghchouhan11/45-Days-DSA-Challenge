#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < arr.size(); i++) {
            int rem = target - arr[i];

            if (mpp.find(rem) != mpp.end())
                return true;

            mpp[arr[i]] = i;
        }

        return false;
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
    if (obj.twoSum(arr, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}