//该程序使用栈结构实现括号匹配
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxSize 10

typedef char ElemType;
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
    //printf("进栈元素:%d\n",x);    
    return true;
}

//出栈
bool Pop_Stack(SqStack &S,ElemType &x){
    if(S.top==-1)                //若栈空，报错
        return false;            
    x = S.data[S.top--];         //先取栈顶元素，再指针减1
    //printf("出栈元素:%d\n",x);
    return true;
}

//取栈顶元素
bool GetTop_Stack(SqStack &S,ElemType &x){
    if(S.top==-1)                //若栈空，报错
        return false;            
    x = S.data[S.top];         //取栈顶元素
    //printf("取得栈顶为:%d\n",x);
    return true;
}

bool bracketCheck(char str[],int length){
    SqStack S;
    InitStack(S);
    for(int i=0;i<length;i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){  //碰到左括号压入栈中
            Push_Stack(S,str[i]);
        }
        else{                                       //遇到右括号
            if(Empty_Stack(S))                      //先判断还有无剩余左括号
                return false;                       //若栈中没有，则无法匹配成功
            char topElem;                           //若栈中还有左括号
            Pop_Stack(S,topElem);                   //取出栈顶元素
            if(str[i]==')'&&topElem!='(')           //判断是否成对
                return false;
            if(str[i]==']'&&topElem!='[')
                return false;
            if(str[i]=='}'&&topElem!='{')
                return false;
        }
    }
    return Empty_Stack(S);                          //若最后栈中无左括号，说明全部匹配成功
}

int main(){
    char *str;
    printf("请输入想要检验的括号序列:");
    scanf("%s",str);
    printf("Length = %d\n",strlen(str));
    if(bracketCheck(str,strlen(str)))
        printf("括号序列匹配成功");
    else
        printf("括号序列匹配失败");
    return 0;
}