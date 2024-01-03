#include<iostream>
#include<string.h>
using namespace std;

char FirstChar(char *str,int len){
    int i,j;
    for(i = 0; i < len; i++){
        for(j = 0; j < len; j++){
            if(str[i]==str[j]&&i!=j)    //如果字符相同，则最内循环会提前结束
                break;
        }
        if(j==len)                      //若内循环完整遍历一遍，则代表str[i]是不重复的
            break;
    }
    if(i==len)                          //如果i==len 说明全部字符都是重复的
        return -1;
    else                                //若i != len 说明循环提前结束，找到一个不重复的元素
        return str[i];
} 

//采用空间换时间，设置一个辅助数组B[26]用来存放26个字母出现的次数,时间复杂度O(2n)
//先遍历一遍原序列，更新B[26]，注意在第二次遍历查找只出现一次的值时，要按照当初的遍历顺序查找，而不是B[j] j 0-> 26
char first_char(char *str,int len){
    int B[26] = {0};
    for(int i = 0; i < len; i++)
        B[str[i]-'a']++;
    for(int j = 0; j < len; j++)
        if(B[str[j]-'a']==1)
            return str[j];
    cout << "未找到" << endl;
    return 0;
}

int main(){
    char *str = new char;
    cout << "请输入想要检验的序列:";
    cin >> str;
    //cout << "The First and Only Element:" << FirstChar(str,strlen(str)) << endl;
    cout << "The First and Only Element:" << FirstChar(str,strlen(str)) << endl;
    return 0;
}