//这个是自己写的，速度和空间都不够好，还需要改进
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int maxFromThisEle[len];
        maxFromThisEle[len-1] = nums[len-1];
        for(int i = len-2;i>=0;i--)
        {
            int fromNext = maxFromThisEle[i+1];
            if(fromNext>0)
            {
                maxFromThisEle[i] = nums[i] + fromNext;
            }
            else
            {
                maxFromThisEle[i] = nums[i];
            }
        }
        int max = -100000000;
        for(int i=0;i<len;i++)
        {
            int cur = maxFromThisEle[i];
            if(cur>max)
            {
                max = cur;
            }
        }
        return max;
    }
};
