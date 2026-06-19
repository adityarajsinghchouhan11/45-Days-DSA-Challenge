class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int xr=0;
        unordered_map<int,int> mpp;
        int count=0;
        mpp[0]++;
        for(int i=0;i<arr.size();i++)
        {
            xr=xr^arr[i];
            int x=xr^k;
            count+=mpp[x];
            mpp[xr]++;
        }
        return count;
    }
};