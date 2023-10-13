#include<iostream>
#define maxsize 100
using namespace std;

typedef struct Stack{
    int stack[maxsize];         //栈空间
    int top[2] = {-1,maxsize};                 //两个栈顶指针
}Stack;

Stack s;
 

int Push(int i, int x){
    //i表示栈号，i = 0表示左边的s1栈，i = 1表示右边的s2栈
    if(i<0||i>1){
        cout <<"栈号非法"<< endl;
        return 0;
    }
    if(s.top[1]-s.top[0]==1){
        cout << "栈满" <<endl;
    }

    switch (i)
    {
    case 0: s.stack[++s.top[0]] = x;    return 1; break;
    case 1: s.stack[--s.top[1]] = x;    return 1; break;
    }
}

int Pop(int i){
    if(i<0||i>1){
        cout <<"栈号非法"<< endl;
        return 0;
    }

    switch (i)
    {
    case 0: 
        if(s.top[0]==-1){
            cout << "栈空" << endl;
            return -1;
        }
        else s.stack[s.top[0]--];break;
    case 1: 
        if(s.top[1]==maxsize){
            cout << "栈空" << endl;
            return -1;
        }
        else s.stack[s.top[1]--];
        break;
        return 1;
    }
}

void Create_Stack(){
    int x,i;
    printf("请输入想要插入的元素和位置:");
    scanf("%d %d",&i,&x);
    while(x!=9999){
        Push(i,x);
        scanf("%d %d",&i,&x);
    }
}

void Print(){
    cout << "s1:" << endl;
    for(int i = 0; i <= s.top[0]; i++)              //栈顶指针指向最后一个元素
        cout << s.stack[i] << "\t";
    cout << "\n"<< "s2:" << endl;
    for(int i = s.top[1]; i < maxsize; i++)
        cout << s.stack[i] << "\t";
}

int main(){
    Create_Stack();
    Print();
    return 0;
}