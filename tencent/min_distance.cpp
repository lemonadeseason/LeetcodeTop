//开始看到这道题就觉得很难，看了解析觉得还是挺直观的，dp把大问题用子问题解决也太dior了
//dp[i][j]是string1的前i个词变换到string2的前j个词的最小操作数
//例子：word1 = "horse", word2 = "ros"
//边界：dp[0][j] = j(依次添加j个元素)，同理，dp[i][0]=i(把i个元素全部删除完)
//状态转移方程：dp[i][j]可以由三种途径得到：dp[i-1][j]再额外给word1删除word1[i]；dp[i][j-1]变换之后再加word2[j]；最后还有dp[i-1][j-1]，需要判断word1[i]和word2[j]一样不一样，不一样再添加word2[j]

//比如考虑‘h’到'r'(dp[1][1])  （1）dp[0][1]是1，但还得加入去掉‘h’的1个操作，2（2）dp[1][0]是1，在加入添加‘r’的1个操作，2  （3）dp[0][0]是0，【因为‘h’与‘r’不等，所以可以把h修改为r，只需要1个操作】
//当考虑dp[1][2]（'h'到'ro'）时需要dp[0][2]、dp[1][1]、dp[0][1]

class Solution {
public:
    int minDistance(string word1, string word2) {
        //vector<vector<int>> dp(word1.size()+1,vector<int> word2.size()+1);
        int len1 = word1.size();
        int len2 = word2.size();
        int dp[len1+1][len2+1];   //dp[i][j]是第一个字符串的前i个到第二个字符串的前j个的编辑距离
        for(int i = 0;i<=len1;i++)
        {
            dp[i][0] = i;
        }
        for(int i = 0;i<=len2;i++)
        {
            dp[0][i] = i;
        }
        //初始化边界
        for(int i = 1;i<=len1;i++)
        {
            for(int j = 1;j<=len2;j++)
            {
                int temp = dp[i-1][j-1];
                if(word1[i-1]!=word2[j-1])
                temp += 1;
                //temp += (word1[i-1]==word2[j-1]?0:1);
                dp[i][j] = min(min(dp[i-1][j]+1,dp[i][j-1]+1),temp);
            }
        }
        return dp[len1][len2];
    }
};
