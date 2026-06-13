#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) 
    {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }
    while (left <= mid)
        temp.push_back(arr[left++]);

    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
    }
    int countpairs(vector<int>&arr,int low,int mid,int high)
    {
        int count=0;
        int right=mid+1;
        for(int i=low;i<=mid;i++)
        {
            while(right<=high && arr[i]>2*arr[right])
                right++;
            count+=(right-(mid+1));
        }
        return count;
    }
    int mergeSort(vector<int>& arr, int low, int high) 
    {
        int count=0;
        if (low >= high)
            return count;
        int mid = (low + high) / 2;
        count+=mergeSort(arr, low, mid);
        count+=mergeSort(arr, mid + 1, high);
        count+=countpairs(arr,low,mid,high);
        merge(arr, low, mid, high);
        return count;
    }
    int countRevPairs(vector<int> &arr) {
        return mergeSort(arr,0,arr.size()-1);
        
    }
};