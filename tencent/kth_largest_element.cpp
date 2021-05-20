class Solution {
public:
    int partition(vector<int>& nums,int left,int right)
    {
        int partition_ele = nums[left];
        int i = left;
        int j = right+1;
        while(true)
        {
            while(nums[++i]<partition_ele) {if(i==right) break;};   //注意不能越界
            while(nums[--j]>partition_ele) {if(j==left) break;};
            if(i>=j) break;   //i>j很明显已经交叉了，等于时：比如10，i=j=1，则1应该和0调换位置
            //找到左右各一个不符合和partition_ele位置关系的元素，它两调换位置
            int temp = nums[i];    
            nums[i] = nums[j];
            nums[j] = temp;
        }
        int temp = nums[j];
        nums[j] = partition_ele;
        nums[left] = temp;
        return j;
    }
    void quickSort(vector<int>& nums,int left,int right,int target)
    {
        if(left>=right)  return;    
        int q = partition(nums,left,right);
        if(q==target) return;   //一分好target就返回
        if(target<q)
           quickSort(nums,left,q-1,target);
        if(target>q)
           quickSort(nums,q+1,right,target); 
    }

    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        quickSort(nums,0,len-1,len-k);
        return nums[len-k];
    }
};
