#include<iostream>
#include<vector> 
using namespace std;

void Matrix_Rotate(int **Matrix, int N){
    //要实现顺时针旋转90度     若要实现逆时针旋转90度
    //1.先转置 
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
            swap(Matrix[i][j],Matrix[j][i]);

    //2.再水平翻转
	for(int i = 0; i < N; i++)
        for(int j = 0; j < N/2; j++)
            swap(Matrix[i][j],Matrix[i][N-1-j]);             //数组每列最大下标N-1
}
 



void Print(int **Matrix, int N){
	for(int i = 0; i < N; i++){
		cout << endl;
		for(int j = 0; j < N; j++)
			cout  << "\t" << Matrix[i][j]; 
	}
} 

int main(){
	int N;
	cout << "请输入矩阵的行数" << endl;
	cin >> N;

    int** Matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        Matrix[i] = new int[N];
    }

    cout << "请依次输入矩阵数据：" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Matrix[i][j];
        }
    }

    cout << "原矩阵是："<< endl;
    Print(Matrix, N);

    cout << "\n" << "翻转后的矩阵是："<< endl;
    Matrix_Rotate(Matrix,N);
    Print(Matrix, N);

    // 释放动态分配的内存
    for (int i = 0; i < N; i++) {
        delete[] Matrix[i];
    }
    delete[] Matrix;
	return 0;
} 
