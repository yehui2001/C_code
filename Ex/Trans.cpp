#include<iostream>
#include<string.h>
using namespace std;

void Translation(char *str,int len){
    int num1 = 0,num2 = 0;
    for(int i = 0; i < len; i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            num1++;
        if(str[i] >= 'A' && str[i] <= 'Z')
            num2++;
    }
    if(num1>num2){
        for(int i = 0; i < len; i++)
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i]  + ('a' - 'A');
    }
    else{
        for(int i = 0; i < len; i++)
            if(str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - ('a' - 'A');
    }
}

int main(){
    char *str = new char;                       //用之前先分配内存
    cout << "请输入想要检验的序列:" << endl;
    cin >> str;
    cout << "原序列" << str << endl;
    int len = strlen(str);
    Translation(str,len);
    cout << str;
    return 0;
}