class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        int idx = 0,posFlag=1;
        while(s[idx]==' ')   //丢弃空格
        {
            idx++;
        }
        if(s[idx]=='+'||s[idx]=='-')  
        {
            if(s[idx]=='-')
            {
                posFlag = -1;
            }
            else
            {
                posFlag = 1;
            }
            idx++;
        }
        string intString;
        long long val = 0;   //注意long long，初始化为0，第一次乘10不影响
        while(idx<len&&s[idx]>='0'&&s[idx]<='9')
        {
            //val +=(s.at(idx)-'0')*times;
            //times*=
            //intString += s[idx];
            //idx++;
            val = val*10 + (s[idx]-'0');
            if(val*posFlag>INT_MAX)   //因为是long long，即使max乘以10也不会越界
            {
                return INT_MAX;
            }
            if(val*posFlag<INT_MIN)
            {
                return INT_MIN;
            }
            idx++;
        }


        val *= posFlag;
        /*
        if(val> INT_MAX)
        val = INT_MAX;
        if(val< INT_MIN)
        val = INT_MIN;
        */
        return val;
    }
};
