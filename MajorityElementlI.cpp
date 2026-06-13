#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
using namespace std;

class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        int count1 = 0, count2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (count1 == 0 && ele2 != arr[i]) {
                ele1 = arr[i];
                count1 = 1;
            }
            else if (count2 == 0 && ele1 != arr[i]) {
                ele2 = arr[i];
                count2 = 1;
            }
            else if (ele1 == arr[i]) {
                count1++;
            }
            else if (ele2 == arr[i]) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for (int i = 0; i < n; i++) {
            if (ele1 == arr[i])
                count1++;
            else if (ele2 == arr[i])
                count2++;
        }

        if (count1 > n / 3)
            ans.push_back(ele1);

        if (count2 > n / 3)
            ans.push_back(ele2);

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    vector<int> result = obj.findMajority(arr);

    if (result.empty()) {
        cout << "No majority elements found.\n";
    } else {
        cout << "Majority element(s): ";
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}