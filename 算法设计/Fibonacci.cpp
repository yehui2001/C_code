#include<iostream>
using namespace std;

int Fibonacci(int n){
    if(n<=0)             //单独讨论特殊情况
        return 0;
    if(n==1)
        return 1;
    int p = 0, q = 1;    // p代表f(n-1)， q代表f(n-2)
    int i = 2;
    int result = 0;
    while(i <= n){
        result = p + q;
        p = q;
        q = result;
        i++;
    }
    return result;
} 

int main(){
    int n;
    cout << "请输入n:" << endl;
    cin >> n;
    cout << Fibonacci(n) << endl;
    return 0;
}