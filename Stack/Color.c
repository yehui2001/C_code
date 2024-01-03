#include <stdio.h>

#define ROWS 7
#define COLS 7

int image[ROWS][COLS];

void printImage() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fillPixels(int x, int y, int color) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS || image[x][y] != 0) {
        return;
    }

    image[x][y] = color;
    printImage();

    fillPixels(x, y + 1, color);  // 右
    fillPixels(x - 1, y, color);  // 上
    fillPixels(x, y - 1, color);  // 左
    fillPixels(x + 1, y, color);  // 下
}

int main() {
    // 初始化图像
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                image[i][j] = 8;  // 边界用-1表示
            } else {
                image[i][j] = 0;   // 其他位置用0表示未填充
            }
        }
    }

    // 调用填充函数
    fillPixels(2, 2, 1);

    return 0;
}