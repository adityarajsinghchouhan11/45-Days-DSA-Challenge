#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        int count = 0;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                count += (mid - left + 1);
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid)
            temp.push_back(arr[left++]);

        while (right <= high)
            temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];

        return count;
    }

    int mergesort(vector<int> &arr, int low, int high) {
        int count = 0;

        if (low >= high)
            return count;

        int mid = low + (high - low) / 2;

        count += mergesort(arr, low, mid);
        count += mergesort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);

        return count;
    }

    int inversionCount(vector<int> &arr) {
        return mergesort(arr, 0, arr.size() - 1);
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
    int inversions = obj.inversionCount(arr);

    cout << "Inversion Count: " << inversions << endl;

    return 0;
}