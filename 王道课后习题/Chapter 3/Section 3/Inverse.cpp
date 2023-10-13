//该程序实现顺序栈的定义及其基本操作（增删改查）
#include<iostream>
#define MaxSize 50
using namespace std;

typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int top;
} SqStack;

typedef struct{
    ElemType data[MaxSize];
    int front,rear;
} SqQueue;

//顺序栈初始化
void InitStack(SqStack &S){
    S.top = -1;                 //默认栈空，栈顶指针指向-1
}                               //栈顶指针默认指向栈顶元素

//顺序队列初始化
void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
}

//判栈空
bool Empty_Stack(SqStack S){
    if(S.top==-1)
        return true;
    else
        return false;
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

//进栈
bool Push_Stack(SqStack &S,ElemType &x){
    if(S.top==MaxSize-1)         //若栈满，报错
        return false;
    S.data[++S.top] = x;         //栈顶指针先加1，再添加元素
    printf("进栈元素:%d\n",x);    
    return true;
}

//出栈
bool Pop_Stack(SqStack &S,ElemType &x){
    if(S.top==-1)                //若栈空，报错
        return false;            
    x = S.data[S.top--];         //先取栈顶元素，再指针减1
    printf("出栈元素:%d\n",x);
    return true;

}//入队
bool In_Queue(SqQueue &Q,int x){
    if(Full_Queue(Q))     //判断队满
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MaxSize;        //通过取余运算，达到循环队列的目的。
    printf("%d入队\n",x);
    return true;
}

//出队
bool Out_Queue(SqQueue &Q,int &x){
    if(Empty_Queue(Q))
        return false;
    x = Q.data[Q.front];
    Q.front =(Q.front+1)%MaxSize;
    printf("%d出队\n",x);
    return true;
}

//建栈
void Create_Stack(SqStack &S,SqQueue &Q){
    int x;
    for(int i = 0; i < 9; i++){
        Push_Stack(S,Q.data[i]);
    }
}

// 输出
void Print_Stack(SqStack &S){
    int x = 0;
    while(S.top!=-1){
        Pop_Stack(S,x);
        //S.top--;
    }
}

//打印
void Print_Queue(SqQueue &Q){
    for(int i = 0; i < 9; i++){
        cout << Q.data[i]<<"\t"<<endl;
    }
}

void Inverser(SqStack &S,SqQueue &Q){
    int x;
    while(!Empty_Queue(Q)){
        Out_Queue(Q,x);
        Push_Stack(S,x);
    }

    Q.front = Q.rear  = 0;          //发生假溢出，恢复到队空
    while(!Empty_Stack(S)){
        Pop_Stack(S,x);
        In_Queue(Q,x);
    }

}

int main(){
    SqStack S;
    SqQueue Q;
    int x = 0;
    InitStack(S);
    InitQueue(Q);
    int a[9] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 9; i++){
        Q.data[i] = a[i];
        Q.rear++;
    }
    Print_Queue(Q);
    cout << "--------------------------\n";
    //Create_Stack(S,Q);
    //Print_Stack(S);
    //for(int i = 0; i < 9; i++){
    //   Pop_Stack(S,Q.data[i]);
    //}
    Inverser(S,Q);
    Print_Queue(Q);
    cout << "--------------------------\n";
    return 0;
}