//看了官方思路自己写的，可以从头扫到尾，维护max，potential是之前元素可以提供的（即最少也得考虑“前一个”元素）
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //从头到尾扫描，维护一个目前的最大子序和，同时还有之前元素可以提供的potential值（小于0则不考虑）
        int len = nums.size();
        int potential = nums[0];   //一开始就是potential就是第一个元素
        int max = potential;
        for(int i=1; i<len; i++)
        {
            if(potential>0)
            {
                //curMax = nums[i] + potential;
                potential += nums[i];
            }
            else
            {
                potential = nums[i];
            }
            if(potential>max)
            {
                max = potential;
            }
        }
        return max;
    }
};
