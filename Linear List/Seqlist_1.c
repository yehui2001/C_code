//此程序用静态分配数组实现顺序表及其基本操作
#include<stdio.h>
#include<stdlib.h>
#define Maxsize 50

typedef int Elemtype; 
// 静态分配空间
typedef struct{
    Elemtype data[Maxsize]; //静态数组存放数据元素
    int length;             //当前长度
} Seqlist;                  //顺序表类型定义

// 初始化静态线性表
void Init_List(Seqlist &L){
    for(int i=0; i < Maxsize; i++){
        L.data[i] = 0;
    }
    L.length = 0;
}

// 打印线性表
void Print_List(Seqlist &L){
    printf("\nThe SeqList is ");
    if(L.length == 0)
        printf("Null");
    for(int i=0; i < L.length; i++){
        printf("%d\t",L.data[i]);
    }
    printf("\n");
}

// 插入数据元素 
bool Insert_List(Seqlist &L,int i,Elemtype e){ //i means the position inserted,e is the element inserted.
    if(i<1||i>L.length+1)   //判断插入位置是否合法，即不属于顺序表的逻辑结构
        return false;
    if(L.length == Maxsize) //当前存储空间已满
        return false;       
    for(int j=L.length; j>=i; j--){ //此处的j i 都是指元素的位序，从1开始。
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

// 删除数据元素
bool Delete_List(Seqlist &L,int i,Elemtype &e){ //i 为要删除元素的位序,e来返回删除元素的值
    if(i<1||i>L.length+1)   //判断删除位置是否合法
        return false;
    e = L.data[i-1];
    for(int j=i; j<L.length; j++){ //若要删除最后一个元素，只是将表长减1，最后一个元素其实没有被覆盖掉
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;    
}

// 查找数据元素
int Find_List(Seqlist &L,Elemtype e){ //查找值为e的数据元素的下标
    int i;
    for(int i=0; i < L.length; i++){
        if(L.data[i] == e){
            return i+1;
        }
    }
    return 0;
}

int main(){
    Seqlist L;
    Init_List(L);
    Print_List(L);
    Insert_List(L,1,99);
    Insert_List(L,2,999);
    Print_List(L);
    Elemtype e = -1,a = 99;
    Delete_List(L,2,e);
    Print_List(L);
    printf("The position is%d\n",Find_List(L,a));
}