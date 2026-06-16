#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int count = 0;
        int maxi = 0;
        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            st.insert(arr[i]);
        }

        for (int i = 0; i < n; i++) {
            count = 0;

            if (st.find(arr[i] - 1) == st.end()) {
                count++;
                int x = arr[i] + 1;

                while (st.find(x) != st.end()) {
                    count++;
                    x++;
                }

                maxi = max(maxi, count);
            }
        }

        return maxi;
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
    cout << obj.longestConsecutive(arr) << endl;

    return 0;
}