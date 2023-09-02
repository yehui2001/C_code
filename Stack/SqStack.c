//该程序实现顺序栈的定义及其基本操作（增删改查）
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50

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
bool Pop_Stack(SqStack &S,ElemType x){
    if(S.top==-1)                //若栈空，报错
        return false;            
    x = S.data[S.top--];         //先取栈顶元素，再指针减1
    printf("出栈元素:%d\n",x);
    return true;
}

//取栈顶元素
bool GetTop_Stack(SqStack &S,ElemType &x){
    if(S.top==-1)                //若栈空，报错
        return false;            
    x = S.data[S.top];         //取栈顶元素
    printf("取得栈顶为:%d\n",x);
    return true;
}

//建栈
void Create_Stack(SqStack &S){
    int x;
    printf("请输入想要插入的元素:");
    scanf("%d",&x);
    while(x!=9999){
        Push_Stack(S,x);
        scanf("%d",&x);
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

int main(){
    SqStack S;
    int x = 0;
    InitStack(S);
    printf("--------------------------\n");
    if(Empty_Stack(S)){
        printf("栈空\n");
    }
    //Push_Stack(S,1);
    //Push_Stack(S,2);
    //GetTop_Stack(S,x);
    //Pop_Stack(S,x);
    //GetTop_Stack(S,x);
    Create_Stack(S);
    Print_Stack(S);
    printf("--------------------------\n");
    return 0;
}