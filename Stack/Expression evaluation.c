//该程序用以实现中序表达式求值（1.中序转后序，2.后序求值）
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

typedef struct SNode
{
    char data;
    struct SNode *next;
}*LinkStack;


//初始化链栈
LinkStack Init_Stack(LinkStack &S){
    S = (SNode *)malloc(sizeof(SNode));
    S = NULL;
    return S;
}


//进栈
bool Push_Stack(LinkStack &S,int x){
    SNode *s;
    s = (SNode *)malloc(sizeof(SNode));
    s->data = x;
    s->next = S;                   //让新结点成为首结点
    S = s;                         //令新插入的结点始终是头节点
    return true;
}

//出栈
bool Pop_Stack(LinkStack &S,int &elem){
    if(S==NULL){
       return false; 
    }
    SNode *p,*q;
    elem = S->data;
    p = S;
    q = S->next;
    S = q;
    free(p);
    return true;
}

//取栈顶元素
int get_elem(LinkStack &S,int &elem){
    if(S==NULL){
       return false; 
    }
    elem = S->data;
    return elem;  
}

//判断栈空
bool isEmpty(LinkStack &S){
    return (S==NULL);
}


//判断是否为运算符
int is_operator(char op){
    switch(op){
        case '(': return 2;
        case '+':
        case '-':
        case '*':
        case '/': return 1;
        default:  return 0;
    }
}

//定义运算符的优先级
int priority(char op)
{
    switch(op)
    {
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

//定义运算求值
int get_value(int op,int operand1,int operand2){
    operand1 =-49;
    operand2 =-49;
    switch ((char)op)
    {
    case '*': return (operand2 * operand1);
    case '/': return (operand2 / operand1);
    case '+': return (operand2 + operand1);
    case '-': return (operand2 - operand1);
    default:return 0;
    }
}

//中缀求值
/*
void calculate_mid(char str[],LinkStack &Operator, LinkStack &operand){
    int i = 0;
    while(str[i]!='\n'&&str[i]!='\0'){
        if(!is_operator(str[i])){
            Push_Stack(operand,str[i++]);
        }
        else{
            if(isEmpty(Operator)||str[i]=='('){        //运算符栈空直接插入运算符
                Push_Stack(Operator,str[i++]);
            }
            else{
                char op;
                if(str[i]==')'){
                    while(get_elem(Operator,op)!='('){
                        Pop_Stack(Operator,op);
                        value(op,str[i],Operator,operand);
                    }
                    Pop_Stack(Operator,op);
                }
                Push_Stack(Operator,str[i]);
                value(op,str[i],Operator,operand);
            }
        }
    }
}
*/

void cal_mid(char str[],LinkStack &optr, LinkStack &oprd){
    int i = 0;
    int op = 0;
    int operand1 = 0;
    int operand2 = 0;
    while(str[i]!='\0'||!isEmpty(optr)){            
        char a = str[i];
        if(!is_operator(str[i])&&str[i]!='\0'){              //如果是操作数，直接进栈
            Push_Stack(oprd,str[i]);
        }
        else{
            if(isEmpty(optr)){    //若非操作数，且运算符栈空直接插入运算符
                Push_Stack(optr,str[i]);
            }
            else {
                if(priority(get_elem(optr,op))>=priority(str[i])&&str[i]!='\0'){  //若栈顶元素优先级更高或者相等，优先弹出
                    Pop_Stack(optr,op);
                    Pop_Stack(oprd,operand1);                          //并弹出两个运算符
                    Pop_Stack(oprd,operand2);                           //将结果压入栈内
                    Push_Stack(oprd,get_value(op,operand1,operand2));
                }
                else{
                    if(str[i]!='\0')
                        Push_Stack(optr,str[i]);                          //若栈顶元素更低，则当前获取的运算符入栈
                    else{
                        Pop_Stack(oprd,operand1);
                        Pop_Stack(oprd,operand2);
                        Pop_Stack(optr,op);
                        Push_Stack(oprd,get_value(op,operand1,operand2));
                    }
                }
            }
        }
        i++;
    }  
}



int main(){
    char str[MaxSize];
    LinkStack optr,oprd;
    Init_Stack(optr);
    Init_Stack(oprd);
    printf("\n请输入想要计算的中序表达式:");
    scanf("%s",str);
    cal_mid(str,optr,oprd);
    //calculate_mid(str,Operator,operand);
    printf("计算的值=%d\n",oprd->data);
    return 0;
}