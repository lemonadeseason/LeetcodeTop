class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        int increaseNum[len];   //如果考虑nums[0：i]，且nums[i]必须考虑进去，则最长递增序列的长度为increseNum[i]
        int last[len];
        int max = 1;
        increaseNum[0] = 1;
        last[0] = nums[0];
        for(int i =1;i<len;i++)
        {
            int maxIncrease = 0;   //如果之前的都比cur大，则这个数字不会被修改
            int cur = nums[i];
            for(int j = 0;j<i;j++)
            {
                if((last[j]<cur)&&(maxIncrease<increaseNum[j]))   
                {
                    maxIncrease = increaseNum[j];
                }
            }
            increaseNum[i] = maxIncrease + 1;
            last[i] = cur;
            if(increaseNum[i]>max)
            {
                max = increaseNum[i];
            }
        }
        return max;
    }
};
