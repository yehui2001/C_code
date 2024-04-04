#include <iostream>
#include <string>

using namespace std;

string getMaxSubstring(const string& s1, const string& s2) {
    /*string::npos 是一个常量，它表示 std::string 类型中的一个特殊值。
	在 C++ 中，std::string::npos 表示字符串中的无效位置或者未找到的位置。
    当你在字符串中使用 find 方法时，如果没有找到目标子串，它会返回 std::string::npos
	*/
	// 检查较短的字符串是否是较长的字符串的子串
	if (s1.find(s2) != string::npos) {		
        return s2;
    } else if (s2.find(s1) != string::npos) {
        return s1;
    } else {
        // 遍历 s2 的所有可能子串
        for (int = s2.length(); i > 0; --i) {				//控制子串的长度 
            for (int j = 0; j <= s2.length() - i; ++j) {	//控制子串的起始位置 
                string sub = s2.substr(j, i);				//substr(i,j) 代表从i位置提取长度为j的子串 
                if (s1.find(sub) != string::npos) {	
                    return sub;
                }
            }
        }
        return "";
    }
}

int main() {
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    string result = getMaxSubstring(s1, s2);
    cout << "两个字符串 '" << s1 << "' 和 '" << s2 << "' 的最大公共子串是 '" << result << "'" << endl;
    return 0;
}

