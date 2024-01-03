#include <stdio.h>

#define ROWS 5
#define COLS 5

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

// 定义栈结构
struct Stack {
    int x;
    int y;
};

void push(struct Stack *stack, int *top, int x, int y) {
    stack[*top].x = x;
    stack[*top].y = y;
    (*top)++;
}

void pop(int *top) {
    (*top)--;
}

void fillPixels(int x, int y, int color) {
    struct Stack stack[ROWS*COLS];  // 栈
    int top = 0;  // 栈顶指针

    push(stack, &top, x, y);  // 起始点入栈

    while (top > 0) {
        int currentX = stack[top - 1].x;
        int currentY = stack[top - 1].y;
        pop(&top);

        if (currentX < 0 || currentX >= ROWS || currentY < 0 || currentY >= COLS || image[currentX][currentY] != 0) {
            continue;
        }

        image[currentX][currentY] = color;
        printImage();

        push(stack, &top, currentX + 1, currentY);  // 下
        push(stack, &top, currentX, currentY - 1);  // 左
        push(stack, &top, currentX - 1, currentY);  // 上
        push(stack, &top, currentX, currentY + 1);  // 右
    }
}

int main() {
    // 初始化图像
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                image[i][j] = 8;  // 边界用8表示
            } else {
                image[i][j] = 0;   // 其他位置用0表示未填充
            }
        }
    }

    // 调用填充函数
    fillPixels(1, 2, 1);        //初始点填充

    return 0;
}
