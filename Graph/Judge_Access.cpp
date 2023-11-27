#include <iostream>
using namespace std;

void computeReachability(int matrix[][5]) {
    int n = 5;  // 矩阵的大小
    int reachableMatrix[5][5];
    
    // 将输入矩阵复制到 reachableMatrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            reachableMatrix[i][j] = matrix[i][j];
        }
    }


    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (reachableMatrix[i][k] == 1 && reachableMatrix[k][j] == 1) {
                    reachableMatrix[i][j] = 1;  // 将可达关系标记为1
                }
            }
        }

        // 打印当前趟的结果
        cout << "Pass " << k + 1 << ":\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << reachableMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    // 示例矩阵
    int exampleMatrix[5][5] = {
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0}

        // {0, 1, 0, 0, 0},
        // {0, 0, 1, 0, 0},
        // {0, 0, 0, 1, 0},
        // {0, 0, 0, 0, 1},
        // {1, 0, 0, 0, 0}

        // {0, 0, 0, 0, 1},
        // {0, 0, 1, 0, 0},
        // {0, 0, 0, 1, 0},
        // {0, 0, 0, 0, 1},
        // {0, 1, 0, 0, 0}
    };

    // 调用函数计算可达关系矩阵
    computeReachability(exampleMatrix);

    return 0;
}