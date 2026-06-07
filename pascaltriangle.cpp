class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<int>> dp(n);
        for(int i=0;i<n;i++)
        {
            dp[i].resize(i+1);
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
        return dp[n-1];
    }
};
