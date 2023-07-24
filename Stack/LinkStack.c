//该程序实现链栈的定义及其基本操作（增删改查）
#include<stdio.h>
#include<stdlib.h>

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
}

//出栈
bool Pop_Stack(LinkStack &S){
    if(S==NULL){
       return false; 
    }
    SNode *p,*q;
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


//打印链栈
void Print_Stack(LinkStack &S){
    SNode * p = S;
    printf("\n链表序列为:\n");
    while(p!=NULL){
        printf("%d\t",p->data);
        p = p->next;
    }
}

int main(){
    LinkStack S;
    Init_Stack(S);
    Create_Stack_head(S);
    Print_Stack(S);
    Push_Stack(S,999);
    Print_Stack(S);
    Pop_Stack(S);
    Print_Stack(S);
}
