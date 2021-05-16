
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length();   //字符串string的长度
        int l2=text2.length();
        int max;
        //一开始dp[0][...]与dp[...][0]都初始化为0
        //i从1到l1，j从1到
        int dp[l1+1][l2+1];
        for(int i = 0;i<=l1;i++)
        {
            dp[i][0] = 0;
        }
        for(int i = 0;i<=l2;i++)
        {
            dp[0][i] = 0;
        }
        for(int i=1;i<=l1;i++)
        {
            for(int j =1;j<=l2;j++)
            {
                if(text1[i-1]==text2[j-1])   //减1
                {
                    dp[i][j] = dp[i-1][j-1] +1;
                }
                else
                {
                    max = dp[i-1][j];
                    if(dp[i][j-1]>max)
                    {
                        max = dp[i][j-1];
                    }
                    dp[i][j] = max;
                }
            }
        }
        return dp[l1][l2];
    }
};
