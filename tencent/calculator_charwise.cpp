//以一个元素一个元素为单位，官方题解的思路，好像我自己想的数字直接读到数字结束更直观
class Solution {
public:
    int calculate(string s) {
        vector<int> val_stack;
        char pre_op = '+';
        int len = s.size();
        int num = 0;
        for(int i = 0;i<len;i++)   //普通的空格不需要处理，循环里不做处理，只需要for中的++就行
        {
            //if(s[i]==' ')
            //    continue;
            if(isdigit(s[i]))
            {
                num  = num*10 + (s[i]-'0');    //太离谱了，不加括号就会overflow
                //cout<<num<<endl;
                //continue;   #否则的话最后一个数计算不进去
            }
            if(!isdigit(s[i])&&s[i]!=' '||i+1==len)   //如果目前是符号  或者这是最后一个（数字）（或空白，最后一个则必须要处理了
            {
            switch(pre_op)
            {
                case '+': {/*cout<<s[i]<<endl;*/val_stack.push_back(num);break;}
                case '-': {val_stack.push_back(-num);break;}
                case '*': {/*cout<<s[i]<<endl;*/val_stack.back()*=num;break;}
                case '/': {val_stack.back()/=num;break;}
            }
            if(i==len-1) break;
            pre_op = s[i];
            //cout<<"signal:"<<pre_op<<endl;
            num = 0;
            }
        }
        return accumulate(val_stack.begin(),val_stack.end(),0);
    }
};

