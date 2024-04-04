#include<iostream>
#include<vector>
using namespace std;

//添加辅助数组 错误的，忘记要连续字母了
void Judge_LCC(string s){
    vector<int>nums(26,0);
    for(int i = 0; i < s.size(); i++)
        nums[s[i]-'a']++;
    int max = -1,max_index = -1;
    for(int j = 0; j < 26; j++)
        nums[j]>max?(max = nums[j],max_index = j):0;
    cout << '\n' << char('a'+ max_index) << "\t" << max << endl;
}

//聪明算法
void LCC(string s){
    char curChar = '\0',maxChar = '\0';
    int curLen = 0,maxLen = 0;
    for(char c:s){
        if(c==curChar)
            curLen++;
        else{
            curChar = c;
            curLen = 1;
        }
        curLen>maxLen?(maxLen=curLen,maxChar=curChar):0;
    }
    cout << "最长连续出现的字母是：" << maxChar << endl;
    cout << "连续出现的长度是：" << maxLen << endl;
}

int main(){
    string s;
    cout << "请输入一串字符串：" << endl;
    cin >> s;
    Judge_LCC(s);
    LCC(s);
    return 0;
}