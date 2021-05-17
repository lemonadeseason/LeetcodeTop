class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> dup;
        int len = nums.size();
        int idx,val;
        for(int i = 0;i<len;i++)
        {
            idx = abs(nums[i]);    //值可能被变负了
            val = nums[idx-1];     //因为值最大就是长度，所以可以用这种方法
            if(val>0)
            {
                nums[idx-1] = val*(-1);
            }
            else    //因为顶多出现两次，所以变负了就可以放了
            {
                dup.push_back(idx);
            }
        }
        return dup;
    }
};
