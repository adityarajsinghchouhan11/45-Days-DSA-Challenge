class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int maxlen=0;
        int n=arr.size();
        long long sum=0;
        unordered_map<long long,int> presum;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==k)
                maxlen=max(maxlen,i+1);
            long long rem=sum-k;
            if(presum.find(rem)!=presum.end())
            {
                int len=i-presum[rem];
                maxlen=max(maxlen,len);
            }
            if(presum.find(sum)==presum.end())
            {
                presum[sum]=i;
            }
        }
        return maxlen;
    }
};