#include<iostream>
using namespace std;
/*
    注意二维数组的定义是 int M[常量表达式][常量表达式],定义大小的必须为常量，而不能是变量
*/
int Find_SaddlePoint(int **M, int row, int col){
    int ** t = new int*[row];                       //用来标识M[i][j]是否为鞍点
    for (int i = 0; i < row; i++) {
        t[i] = new int[col];
    }                               
    for(int i = 0; i < row; i++)                    //赋初值，0代表不是鞍点 2代表是鞍点
        for(int j = 0; j < col; j++)
            t[i][j] = 0;
        

    
    for(int i = 0; i < row; i++){               
        int Max  = 0,Max_index = 0;                 //找每行的最大值元素，其鞍点矩阵值+1
        for(int j = 0; j < col; j++){
            if(Max<M[i][j]){
                Max = M[i][j];
                Max_index = j;
            }
        }
        t[i][Max_index]++;
    }

    
    for(int j = 0; j < col; j++){                   //找每列的最小值元素，其鞍点矩阵值+1
        int Min = 9999,Min_index = 0;
        for(int i = 0; i < row; i++){
            if(Min>M[i][j]){
                Min = M[i][j];
                Min_index = i;
            }
        }
        t[Min_index][j]++;
    }
    

    int sum = 0;
    for(int i = 0; i < row; i++)                    //赋初值，0代表不是鞍点
        for(int j = 0; j < col; j++){
            if(t[i][j]==2)
                sum++;
    }

    return sum;
}



int main(){
    int Row,Col;
	cout << "请输入矩阵的行数和列数：" << endl;
	cin >> Row >> Col;

    int ** Matrix = new int*[Row];
    for (int i = 0; i < Row; i++) {
        Matrix[i] = new int[Col];
    }

    cout << "请依次输入矩阵数据：" << endl;
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Col; j++) {
            cin >> Matrix[i][j];
        }
    }

    cout << "鞍点个数:" << Find_SaddlePoint(Matrix,Row,Col) << endl;

    return 0;
}