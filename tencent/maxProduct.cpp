class Solution {
public:
    //动态规划，dp[i][j]是考虑从i开始到j结束(必须从这里结束？)的子数组中的最大乘积  dp[i][i]是nums[i]，j>=i，dp[0][n-1]是答案
    //i=2开始，每次考虑dp[i][j],j取i-1到0
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_dp[n];
        int min_dp[n];
        max_dp[0] = nums[0];
        min_dp[0] = nums[0];
        for(int i = 1;i<n;i++)
        {
            int temp1 = max_dp[i-1]* nums[i];
            int temp2 = min_dp[i-1]* nums[i];
            max_dp[i] = max(temp1,max(temp2,nums[i]));
            min_dp[i] = min(temp1,min(temp2,nums[i]));
        }
        return max(*max_element(min_dp,min_dp+n),*max_element(max_dp,max_dp+n));
        //return 1;
    }
};
