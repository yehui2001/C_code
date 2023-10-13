#include<iostream>
using namespace std;
#define maxsize 10

typedef double ElemType;
typedef struct{
    ElemType data;
    int no;
}SqStack;

//递归函数
int Fun(int n,int x){ //n代表Fun_n
    if(n==0||n==1)
        return n==0?1:2*x;
    else
        return 2*x*Fun(n-1,x)-2*(n-1)*Fun(n-2,x);
}
   
//非递归求值
int Non_Recur(int n,int x){
    SqStack st[maxsize];
    int top = -1,i;                         //结构体数组栈的  栈顶指针
    ElemType fv1 = 1,fv2 = 2*x;             //n = 0, n = 1的函数初值
    for(i = n; i >= 2; i--){
        top++;
        st[top].no = i;                     //为每个空间定义函数序号
    }
                                            //fv2代表P_n-1(x),fv1代表P_n-1(x)
    while(top!=-1){                         //栈不为空时
        st[top].data = 2*x*fv2 - 2*(st[top].no-1)*fv1;      //先求P2(x)，替换fv2，然后更新fv1值，继续出栈，边出栈边更新fv1，fv2
        fv1 = fv2;
        fv2 = st[top].data;
        top--;
    }
    return n==0?fv1:fv2;                    //n==0,则输出1，n==1输出2*x，不进入循环，n>1，输出fv2(st[top].data)
}

int main(){
    cout << "Recursion Result = " << Fun(3,2) << endl;
    cout << "Non-Recursion Result = " << Non_Recur(1,2) << endl;
    return 0;
}