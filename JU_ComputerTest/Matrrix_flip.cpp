#include<iostream>
#include<vector> 
using namespace std;

//水平翻转
void flip_horizontal(int **matrix,int row, int col){
    int temp;
	for(int i = 0; i < row; i++)
        for(int j = 0; j < col/2; j++){
            temp = matrix[i][col-1-j];             //数组每列最大下标Col-1
            matrix[i][col-1-j] = matrix[i][j];
            matrix[i][j] = temp;
        }
} 

//垂直翻转
void flip_vertical(int **matrix,int row, int col){
    int temp;
	for(int i = 0; i < row/2; i++)
        for(int j = 0; j < col; j++){
            temp = matrix[row-1-i][j];             //数组每行最大下标Row-1
            matrix[row-1-i][j] = matrix[i][j];
            matrix[i][j] = temp;
        }
} 
 



void Print(int **Matrix, int row,int col){
	for(int i = 0; i < row; i++){
		cout << endl;
		for(int j = 0; j < col; j++)
			cout  << "\t" << Matrix[i][j]; 
	}
} 

int main(){
	int Row,Col,sign;
	cout << "请输入矩阵的行数和列数,以及操作数：" << endl;
	cin >> Row >> Col >> sign;

    int** Matrix = new int*[Row];
    for (int i = 0; i < Row; i++) {
        Matrix[i] = new int[Col];
    }

    cout << "请依次输入矩阵数据：" << endl;
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Col; j++) {
            cin >> Matrix[i][j];
        }
    }

    cout << "原矩阵是："<< endl;
    Print(Matrix, Row, Col);

    cout << "\n" << "翻转后的矩阵是："<< endl;
    if(sign)
        flip_horizontal(Matrix,Row,Col);
    else
        flip_vertical(Matrix,Row,Col);
    Print(Matrix, Row, Col);

    // 释放动态分配的内存
    for (int i = 0; i < Row; i++) {
        delete[] Matrix[i];
    }
    delete[] Matrix;
	return 0;
} 
