class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //sum-2*neg=target -> neg = (sum-target)/2
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            sum += nums[i];
        }
        if(sum-target<0 || (sum-target)%2!=0)
        {
            return 0;
        }
        int neg = (sum-target)/2;
        //vector <vector<int>> dp(n + 1, vector<int>(neg + 1));
        vector<vector<int>> dp(n + 1, vector<int>(neg + 1));
        dp[0][0] = 1;   //dp[0][1...neg]会默认初始化为0
        //dp[i][j]是指nums中前i个数能得到j的方法数
        for(int i = 1;i<=n;i++)
        {
            int cur = nums[i-1];
            for(int j = 0;j<=neg;j++)   //在i=1...num-1中，j要考虑取0的时候，因为有可能从后往前推时，后面的已经凑够了，比如1 1 3中得到3，光最后一个就够了，需要设置为dp[1][0]=1
            {
                dp[i][j] = dp[i-1][j];
                if(cur<=j)    
                {
                    dp[i][j] += dp[i-1][j-cur];
                }
            }
        }
        return dp[n][neg];
    }
};
