//该程序实现循环队列的定义及其基本操作（增删改查）
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int front,rear;             //定义队头指针和队尾指针
}SqQueue;

//默认队尾指针指向队尾元素后一个位置
void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;        //初始化队空
}

//判断队空
bool Empty_Queue(SqQueue &Q){
    if(Q.rear == Q.front)
        return true;
    return false;
}

//判断队满
bool Full_Queue(SqQueue &Q){
    if(Q.front==(Q.rear+1)%MaxSize)
        return true;
    return false;
}

//输入队列长度
int Length_Queue(SqQueue &Q){
    return  (Q.rear-Q.front+MaxSize)%MaxSize;
}

//入队
bool EnQueue(SqQueue &Q,int x){
    if(Full_Queue(Q))     //判断队满
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MaxSize;        //通过取余运算，达到循环队列的目的。
    printf("%d入队\n",x);
    return true;
}

//出队
bool DeQueue(SqQueue &Q,int &x){
    if(Empty_Queue(Q))
        return false;
    x = Q.data[Q.front];
    Q.front =(Q.front+1)%MaxSize;
    printf("%d出队\n",x);
    return true;
}

int main(){
    SqQueue Q;
    int x = 0;
    InitQueue(Q);
    In_Queue(Q,1);
    In_Queue(Q,2);
    printf("表长:%d\n",Length_Queue(Q));
    Out_Queue(Q,x);
    Out_Queue(Q,x);
    return 0;
}