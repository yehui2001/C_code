#include<iostream>
using namespace std;

int main(){
    char a[] = {'I','O','I','I','O'};
    int n = sizeof(a)/sizeof(char);
    int num0 = 0,num1 = 0;                  //num0记录当前出栈次数
    for(int i = 0; i < n; i++){             //num1记录当前入栈次数
        if(a[i]=='I')
            num1++;
        else 
            num0++;
        if(num0>num1){                      //若出现num0 > num1，则跳出
            cout << "不合法" <<endl;
            return 0;
        }
    }
    if(num0==num1)                          //判断栈终态是否为空
        cout << "合法" << endl;
    else
        cout << "不合法" << endl;
    return 0;
}