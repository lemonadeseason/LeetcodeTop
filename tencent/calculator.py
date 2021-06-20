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
        //if(i==len) {break;}
        switch(pre_op)
        {
            case '+':val_stack.push_back(num);break;
            case '-':val_stack.push_back(-num);break;
            case '*':{val_stack.back()*=num;break;}
            case '/':{val_stack.back()/=num;break;}
        }
        if(i==len) break;   
        pre_op = s[i];
        i++;
    }
    return accumulate(val_stack.begin(),val_stack.end(),0);
    }
};
