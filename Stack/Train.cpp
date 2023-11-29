#include<iostream>
using namespace std;
#define MaxSize 10

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

//进栈
bool Push_Stack(SqStack &S,ElemType x){
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

void Train_Arrange(int *train,int n){
    int i = 0,*q = train,key;                //q为指向train，用来存放最终结果
    SqStack s;
    InitStack(s);
    while(i<n){                              //NULL是专属于字符串的结束符
        if(train[i]%2==0)                    //若为偶数车厢则入栈
            Push_Stack(s,train[i]);
        else                                 //若为奇数车厢则调到前部
            *(q++) = train[i];
        i++;
    }
    while(!Empty_Stack(s)){
        Pop_Stack(s,key);
        *(q++) = key;
    }
} 


int main(){
    int train[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(train)/sizeof(int);
    Train_Arrange(train,n);
    for(int i = 0; i < 10; i++)
        cout << "\t" <<train[i];
    return 0;
}