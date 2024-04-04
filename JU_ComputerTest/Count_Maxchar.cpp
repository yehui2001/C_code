#include<iostream>
#include<vector>
using namespace std;

void Count_maxChar(string s,int n){
	vector<int>counts(127);
	int max = 0;
	char string_max;
	for(int i = 0; i < n; i++){
		counts[s[i]]++;
	}
	for(int i = 0; i < 127; i++){
		max>counts[i]?0:(max = counts[i],string_max = char(i)); 
	}
	cout << '\n' << string_max << '\t' << max << endl;
} 

int main(){
    string s;
	cin >> s;
	cout << "s = "<< s << endl; 
	int n = s.length();
	Count_maxChar(s,n);
	//cout <<"n = "<< n << endl; 
	//cout << s[1] << endl;
    return 0;
}
