#include<iostream>
using namespace std;

int BiToDe(int n){
	int ans = 0, p = 1;
	while(n!=0){
		int a = n%10;			//��һ�εõ���λ�� ���ڶ��εõ�ʮ��λ��
		ans = ans + a*p;
		p*=2;
		n = n/10; 
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	int N = BiToDe(n);
	cout << N;
}
