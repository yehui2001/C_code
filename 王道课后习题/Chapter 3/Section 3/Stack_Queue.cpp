//该程序实现用双栈模拟一个队列
#include<iostream>
#define MaxSize 2
using namespace std;

typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int top;
} SqStack;

//顺序栈初始化
void InitStack(SqStack &S){
    S.top = -1;                 //默认栈空，栈顶指针指向-1
}                               //栈顶指针默认指向栈顶元素

//判栈空
bool Empty_Stack(SqStack S){
    if(S.top==-1)
        return true;
    else
        return false;
}
//判栈满
bool Overflow_Stack(SqStack S){
    if(S.top==MaxSize-1)
        return true;
    else
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

}

int Enqueue(SqStack &s1,SqStack &s2,ElemType x){
    int key = x;
    if(!Overflow_Stack(s1)){                    //若s1未满，则直接插入到s1中
        Push_Stack(s1,x);
        return 1;
    }
    if(Overflow_Stack(s1) && !Empty_Stack(s2)){//若s1已经满，且s2中有元素，则不能操作，因为若将s1的元素插入到s2中，其输出的顺序收到影响
        cout << "队列满!!!" << endl;
        return 0;
    }
    if(Overflow_Stack(s1) && Empty_Stack(s2)){
        while(!Empty_Stack(s1)){
            Pop_Stack(s1,x);
            Push_Stack(s2,x);
        }
    }
    Push_Stack(s1,key);
    return 0;
}

void Dequeue(SqStack &s1,SqStack &s2,ElemType &x){
    if(!Empty_Stack(s2))                        //若s2中有剩余元素，优先输出
        Pop_Stack(s2,x);
    else if(Empty_Stack(s1))                    //若s1和s2都空，则队列为空
        cout << "队列为空!!!" << endl;
        else{    
        while(!Empty_Stack(s1)){                //若s2为空，但s1不空，则将s1的转移到s2中再输出
            Pop_Stack(s1,x);
            Push_Stack(s2,x);
        }
            Pop_Stack(s2,x);
    }
}

bool QueueEmpty(SqStack s1,SqStack s2){
    if(Empty_Stack(s1)&&Empty_Stack(s2)){
        cout << "空队" << endl;
        return true;
    }
    else{
        cout << "非空队" << endl;
        return false;
    }
}

int main(){
    SqStack s1,s2;
    int x = 0;
    InitStack(s1),InitStack(s2);
    Enqueue(s1,s2,1);
    Enqueue(s1,s2,2);
    Enqueue(s1,s2,3);
    Enqueue(s1,s2,4);
    Enqueue(s1,s2,5);
    Dequeue(s1,s2,x);
    cout << "x = " << x << endl;
    Enqueue(s1,s2,6);
    Dequeue(s1,s2,x);
    cout << "x = " << x << endl;
    Dequeue(s1,s2,x);
    cout << "x = " << x << endl;
    QueueEmpty(s1,s2);
    cout << "--------------------------\n";
    return 0;
}

