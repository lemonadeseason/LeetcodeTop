//input case；s = "3+2*2"
//input case；s = " 3/2 "
//input case；s = " 3+5 / 2 "
//while循环里捕捉到了input的重复模式；  空格若干  数字  空格若干（歪打正着switch不对应四则运算）  符号   每一次while就处理这样的一个模式  “   5   +”,唯一特例是最后“   5  ”，不会再读符号了

class Solution {
public:
    int calculate(string s) {
        //读入数字和运算符，数字存在一个栈里，符号存在另外一个栈里，是*或/时，直接运算，符号栈里只有+和-
    vector<int> val_stack;
    char pre_op = '+';
    int len = s.size();
    int i = 0;
    while(true)
    {
        while(i<len&&s[i]==' ') i++;
        int num = 0;
        while(i<len&&isdigit(s[i]))
        {
            num = num*10 + int(s[i]-'0');
            i++;
        }
        while(i<len&&s[i]==' ') i++;
        //if(i==len) {break;}
        switch(pre_op)    //当到最后末尾时，无论是数字还是空格都会进入这里
        {
            case '+':val_stack.push_back(num);break;
            case '-':val_stack.push_back(-num);break;
            case '*':{val_stack.back()*=num;break;}
            case '/':{val_stack.back()/=num;break;}
            //default:return 1000;
        }
        if(i==len) break;   
        pre_op = s[i];
        i++;
    }
    return accumulate(val_stack.begin(),val_stack.end(),0);
    }
};
