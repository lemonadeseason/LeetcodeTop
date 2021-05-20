class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int maxProfit = 0;
        int curMin = prices[0];
        for(int i = 1;i<len;i++)
        {
            if(prices[i]-curMin>maxProfit)
               maxProfit = prices[i]-curMin;
            if(prices[i]<curMin)
            curMin = prices[i];
        }
        return maxProfit;
    }
};
