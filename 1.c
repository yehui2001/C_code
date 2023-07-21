#include<stdio.h>
void test(int* q){
    printf("q 的地址%p",&q);
}
int main(){
    int x = 5;
    int *p;
    *p = x;
    printf("主函数中的x值 = %d\n",*p);
    printf("p 的地址：%p",&p);
    test(p);
    printf("经过自定义函数中的x值 = %d\n",*p);
    return 0;
}