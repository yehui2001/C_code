#include<iostream>
using namespace std;

/*
    算法思想：加法进位
*/

string string_sum(string s,string t){
    int sLength = s.length();
    int tLength = t.length();
    if(sLength == 0 )           //如果有一项长度为0
        return t;
    if(tLength == 0)
        return s;
    if(tLength > sLength){      //选择两者中最大的串为结果串
        swap(s,t);
        swap(sLength,tLength);
    }

    int c = sLength - tLength;
    while(c > 0){               //短字符串前导零
        t = '0' + t;            //假设t = '1',该语句执行后的结果为 t = '01'
        c--;
    }

    int carry = 0;              //记录进位
    int temp = 0;               //记录当前位数加法的结果
    for(int i = sLength; i >= 0; i--){
        temp = s[i] - '0' + t[i] - '0' + carry; //竖向加法
        if(temp>=10){
            temp-= 10;
            carry = 1;          //代表进位
        }
        else{
            carry = 0;          //表示没有进位
        }
        s[i] = temp + '0';      //转换成字符
    }
    if(carry == 1)            //判断最后一位是否需要进位
        s = '1' + s;
    return s;
}

int main(){
    string s = "9529";
    string t = "115";
    cout << string_sum(s,t) << endl;

    return 0;
}