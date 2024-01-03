#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct SNode
{
    int data;
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
bool Pop_Stack(LinkStack &S,char &elem){
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

//因为栈的特点是在栈顶出插入删除元素，故我们选择头插法建栈
//头插法建立链栈
LinkStack Create_Stack_head(LinkStack &S){
    int x;
    SNode *s;
    printf("请输入想要添加的数据:");
    scanf("%d",&x);
    while(x!=9999){ 
        s = (SNode*)malloc(sizeof(SNode));
        s->data = x;
        s->next = S;                   //让新结点成为首结点
        S = s;                         //令新插入的结点始终是头节点
        scanf("%d",&x);
    }
    return S;
}

//判断栈空
bool isEmpty(LinkStack &S){
    return (S==NULL);
}

//打印链栈
void Print_Stack(LinkStack &S){
    SNode * p = S;
    printf("\n链表序列为:\n");
    while(p!=NULL){
        printf("%d\t",p->data);
        p = p->next;
    }
}

bool bracketCheck(char str[],int length){
    LinkStack S;
    Init_Stack(S);
    for(int i = 0; i < length; i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){  //碰到左括号压入栈中
            Push_Stack(S,str[i]);
        }
        else if(str[i]==')'||str[i]==']'||str[i]=='}'){//遇到右括号
            if(isEmpty(S))                          //先判断还有无剩余左括号
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
    return isEmpty(S);                          //若最后栈中无左括号，说明全部匹配成功
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
