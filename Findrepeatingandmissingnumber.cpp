#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        long n = arr.size();
        long long sum1 = 0, sum2 = 0;

        long long s1 = (n * (n + 1)) / 2;
        long long s2 = (n * (n + 1) * (2 * n + 1)) / 6;

        for (int i = 0; i < n; i++) {
            sum1 += arr[i];
            sum2 += (long long)arr[i] * arr[i];
        }

        long long val1 = sum1 - s1;      // x - y
        long long val2 = sum2 - s2;      // x² - y²

        val2 = val2 / val1;              // x + y

        long long x = (val1 + val2) / 2; // repeating
        long long y = x - val1;          // missing

        return {(int)x, (int)y};
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
    vector<int> ans = obj.findTwoElement(arr);

    cout << "Repeating Number: " << ans[0] << endl;
    cout << "Missing Number: " << ans[1] << endl;

    return 0;
}