//原地逆置
#include<iostream>
using namespace std;

void Swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void Reverse(int A[],int n){
    if(n == 0)  return;
    for(int i = 0; i < n/2;i++)
        Swap(A[i],A[n-i-1]);
}

void Print(int A[],int n){
    for(int i = 0; i < n; i++){
        cout <<"\t"<< A[i];
    }
    cout << endl;
}

int main(){
    int n;
    cout << "请输入元素的数量:" <<endl;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    Print(A,n);
    Reverse(A,n);
    Print(A,n);
}