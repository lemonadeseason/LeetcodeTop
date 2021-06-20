class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        int i = 0;
        int j = len -1;
        while(i<j)
        {
            //跳过非数字和字母的字符
            while(i<j&&!isalnum(s[i])){i++;}
            while(i<j&&!isalnum(s[j])){j--;}
            if(i<j)
            {
            //if(diff!=0&&diff!=diff1&&diff!=diff2)    #这里有问题，P与0之间的差正好等于A到a的
            if(tolower(s[i])!=tolower(s[j]))
            {
                return false;
            }
            i++;
            j--;
            }
        }
        return true;
    }
};
