//该程序实现带标志位循环队列的定义及其基本操作（增删改查）
#include<iostream>
#define MaxSize 10
using namespace std;

typedef struct SqQueue{
    int data[MaxSize];
    int front,rear;             //定义队头指针和队尾指针
    int tag = -1;                //标志符，用以判断队空队满，默认-1
}SqQueue;

//默认队尾指针指向队尾元素
void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;        //初始化队空
}

//输入队列长度
int Length_Queue(SqQueue &Q){
    return  (Q.rear-Q.front+MaxSize)%MaxSize;
}

//入队
bool In_Queue(SqQueue &Q,int x){
    if(Q.rear == Q.front && Q.tag==1){return false;}    //需要同时满足才能判断队满
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MaxSize;                        //通过取余运算，达到循环队列的目的。
    Q.tag = 1;
    cout<< x << "入队" << endl;
    return true;
}

//出队
bool Out_Queue(SqQueue &Q,int &x){
    if(Q.rear == Q.front && Q.tag==0){return false;}
    x = Q.data[Q.front];
    Q.front =(Q.front+1)%MaxSize;
    Q.tag = 0;
    cout<< x << "出队" << endl;
    return true;
}

int main(){
    SqQueue Q;
    int x = 0;
    InitQueue(Q);
    In_Queue(Q,1);
    In_Queue(Q,2);
    cout<< "队长:" << Length_Queue(Q) << endl;
    Out_Queue(Q,x);
    Out_Queue(Q,x);
    return 0;
}