class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int len = nums.size();
        int bound = len - k;
        if(len==1) return {nums[0]};
        /*
        if(nums[0]>nums[1])
        {
            int maxV=nums[0],maxId=0,secondV= nums[1],secondId=1;
        }
        else
        {
            int maxV=nums[1],maxId=1,secondV= nums[0],secondId=0;
        }
        for(int i = 2;i<min(k,len-1);i++)
        {
            if(nums[i]<secondV)
            {
                continue;
            }
            else if(nums[i]>maxV)
            {
                maxV=nums[i];maxId=i;
            }
            else
            {
                secondV=nums[i];secondId=i;
            }
        }*/
        int maxV=nums[0],maxId=0;
        for(int i = 1;i<min(k,len-1);i++)
        {
            if(nums[i]>maxV)
            {
                maxV=nums[i];maxId=i;
            }
        }
        res.push_back(maxV);
        if(len-1<=k) return res;
        for(int i = 1;i<=bound;i++)
        {
            if(nums[i]>=maxV)  //如果新进来的大于以往最大值，直接更新，不管以前的max是不是取不到了
            {
                maxV = nums[i];
                maxId = i;
                res.push_back(maxV);
                continue;
            }
            else if(maxId==i-1)   //上一次的max是在i-1上取到的,重新计算
            {
            //得重新计算
            maxV = nums[i];
            maxId = i;
            for(int j = i+1;j<=i+k-1;j++)
            {
                if(nums[j]>maxV)
                {
                    maxV = nums[j];
                    maxId = j;
                }
            }
            res.push_back(maxV);
        }
        else
        {
            res.push_back(maxV);
        }
    }
    return res;
}
};
