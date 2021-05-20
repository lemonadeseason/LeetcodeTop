class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //reheapify
        nums.push_back(nums[0]);  //因为heap不用数组的第一个元素
        int len = nums.size()-1;
        for(int i = len/2;i>=1;i--)
        {
            sink(nums,i,len);
        }
        for(int i = len; i>1;)
        {
            //swap nums[i] with nums[1]
            int temp = nums[1];
            nums[1] = nums[i];
            nums[i] = temp;
            i--; //uncompleted sorted length --
            sink(nums,1,i);
        }
        nums.erase(nums.begin());
        return nums;
    };
    void sink(vector<int>& nums,int cur,int len)
    {
        while(cur*2<=len)
        {
            int j = cur*2;
            if(j+1<=len&&nums[j+1]>nums[j]) j++;    //find the smallest child
            if(nums[j]>nums[cur])
            {
            int temp = nums[cur];
            nums[cur] = nums[j];
            nums[j] = temp;
            cur = j;
            }
            else
            {
                break;
            }
        }
        return;
    }
};
