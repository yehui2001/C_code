#include <iostream>
#include <string>

using namespace std;

string getMaxSubstring(const string& s1, const string& s2) {
    /*string::npos ��һ������������ʾ std::string �����е�һ������ֵ��
	�� C++ �У�std::string::npos ��ʾ�ַ����е���Чλ�û���δ�ҵ���λ�á�
    �������ַ�����ʹ�� find ����ʱ�����û���ҵ�Ŀ���Ӵ������᷵�� std::string::npos
	*/
	// ���϶̵��ַ����Ƿ��ǽϳ����ַ������Ӵ�
	if (s1.find(s2) != string::npos) {		
        return s2;
    } else if (s2.find(s1) != string::npos) {
        return s1;
    } else {
        // ���� s2 �����п����Ӵ�
        for (int = s2.length(); i > 0; --i) {				//�����Ӵ��ĳ��� 
            for (int j = 0; j <= s2.length() - i; ++j) {	//�����Ӵ�����ʼλ�� 
                string sub = s2.substr(j, i);				//substr(i,j) �����iλ����ȡ����Ϊj���Ӵ� 
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
    cout << "�����ַ��� '" << s1 << "' �� '" << s2 << "' ����󹫹��Ӵ��� '" << result << "'" << endl;
    return 0;
}

