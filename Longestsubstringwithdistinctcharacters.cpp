class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int maxlen=0;
        int l=0,r=0;
        int n=s.size();
        vector<int> arr(256,-1);
        while(r<n)
        {
            if(arr[s[r]]!=-1)
            {
                if(arr[s[r]]>=l)
                    l=arr[s[r]]+1;
            }
            int len=r-l+1;
            maxlen=max(len,maxlen);
            arr[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};
