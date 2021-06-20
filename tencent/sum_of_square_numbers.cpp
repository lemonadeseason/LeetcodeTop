class Solution {
public:
    bool judgeSquareSum(int c) {
        int bound = sqrt(c);
        for(int i = 0;i<=bound;i++)
        {
            /*
            for(int j = 0;j<=bound;j++)
            {
                long long val = i*i+j*j;
                if(val==c)
                {
                    return true;
                }
                if(val>c)
                {
                    break;
                }
            }*/
            double b = sqrt(c-i*i);
            if(b == int(b))    //?
            {
                return true;
            }
        }  
        return false;  
    }
};
