#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int ele = 0;
        int count = 0;

        // Boyer-Moore Voting Algorithm
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                ele = arr[i];
                count++;
            }
            else if (ele == arr[i]) {
                count++;
            }
            else {
                count--;
            }
        }

        // Verify candidate
        count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == ele)
                count++;
        }

        return (count > n / 2) ? ele : -1;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.majorityElement(arr) << endl;

    return 0;
}