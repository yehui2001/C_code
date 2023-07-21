#include <iostream>
typedef int* ElemType;
void increment(ElemType p) {
    (*p)++;
    printf("%d\n",*p);
}

int main() {
    int value = 5;
    ElemType p;
    *p = value;
    increment(p);
    std::cout << *p << std::endl;
    return 0;
}
