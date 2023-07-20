#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;