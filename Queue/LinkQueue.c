//该程序为带头节点的链队列
#include<stdio.h>
#include<stdlib.h>

struct LinkNode{
    int data;
    struct LinkNode *next;
};

typedef struct{
    struct LinkNode *front,*rear;
}LinkQueue;

//初始化
void Init_Queue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));//建立头节点
    Q.front->next = NULL;                                  //初始为空
}

//判队空
bool Empty_Queue(LinkQueue &Q){
    if(Q.front==Q.rear)
        return true;
    return false;
}

//入队
bool In_Queue(LinkQueue &Q,int x){
    if(Empty_Queue(Q))
        return false;
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;             //队尾指向NULL
    Q.rear->next = s;           //插入到队尾
    Q.rear = s;                 //重新定义队尾
    printf("%d入队\n",x);
    return true;
}

//出队
bool Out_Queue(LinkQueue &Q,int &x){
    if(Empty_Queue(Q)){
        return false;
    }
    LinkNode *p = Q.front->next;//注意此链表是带头节点的，p指向第一个结点
    x = p->data;
    Q.front->next = p->next;     //指向下一个结点
    if(Q.rear==p)               //若原队列中只有一个元素，删除后队空
        Q.rear = Q.front;
    free(p);
    printf("%d出队\n",x);
    return true;
}

int main(){
    LinkQueue Q;
    int x = 0;
    Init_Queue(Q);
    In_Queue(Q,1);
    In_Queue(Q,2);
    Out_Queue(Q,x);
    Out_Queue(Q,x);
}
