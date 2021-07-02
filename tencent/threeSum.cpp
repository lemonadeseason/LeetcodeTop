class Solution {
public:
    //为了避免重复，先排个序，方便跳过一样的元素
    //从头到尾遍历，将所指元素作为第一个元素，剩下两个元素利用已经排好的序，从剩下的头、尾开始
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        vector<vector<int>> res;
        
        for(int i = 0;i<len-2;i++)
        {
            //if(nums[i]==nums[i+1]) continue;
            int target = -nums[i];
            int second = i+1;
            int third = len-1;
            while(second<third)
            {
                if(nums[second]+nums[third]>target)
                {
                    third--;
                }
                else if(nums[second]+nums[third]<target)
                {
                    second++;
                }
                else{
                    res.insert(res.end(),vector<int>({nums[i],nums[second],nums[third]}));
                    second++;
                    third--;
                    while(second<third&&nums[second]==nums[second-1]){second++;}
                    while(second<third&&nums[third]==nums[third+1]){third--;}
                }
            }
            while(i<len-1&&nums[i]==nums[i+1]) {i++;}
        }
        return res;
    }
};
