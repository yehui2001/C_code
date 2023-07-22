//该程序实现基于无头节点的单链表的定义及基础操作
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
// 定义单链表中的结点类型
typedef struct LNode{
    ElemType data;          //数据域
    struct LNode *next;     //指针域
}LNode,*LinkList;           //重命名后的Linklist常用来定义单链表的头指针

//初始化单链表
LinkList Init_List(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    L = NULL;
    printf("初始化函数中的L地址 = %p\n",&L);
    return L;
}

//头插法建立单链表
LinkList Create_List_head(LinkList &L){
    int x;
    LNode *s;
    printf("请输入想要添加的数据:");
    scanf("%d",&x);
    while(x!=9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L;                   //让新结点成为首结点
        L = s;                         //令新插入的结点始终是头节点
        scanf("%d",&x);
    }
    return L;
}

//尾插法建立单链表
LinkList Create_List_tail(LinkList &L){
    int x;
    LNode *s,*r = L;                        //r为表尾指针
    printf("请输入想要添加的数据:");
    scanf("%d",&x);
    while(x!=9999){
        if(L==NULL){                            //由于无头结点的特殊性，创建的第一个结点需要重新赋予头指针
            s = (LNode*)malloc(sizeof(LNode));
            s->data = x;
            s->next = NULL;
            L = s;                              //令新创建的结点作为第一个结点
            r = s;                              //令表尾指针始终指向表尾
            scanf("%d",&x);                     //若scanf“%d”里面有其他内容，输入时需要一并键入
        }
        else{
            s = (LNode*)malloc(sizeof(LNode));
            s->data = x;
            r->next = s;
            r = s;
            scanf("%d",&x);                
        }
    }
    r->next = NULL;                         //尾结点置空
    return L;
}

//按序查找结点
LNode *Get_Elem_Address(LinkList &L,int i){
    if(i<1)
        return NULL;                        //查找位置不合法
    LNode *p;                               //指针p为当前扫描到的结点
    int j=1;                                //p当前指向结点位序（头节点默认为0）
    p = L;                                  //从头节点开始
    while(p!=NULL&&j<i){                    //指针p扫描到表尾结束，或者找到第i个结点的前驱结点结束
        p = p->next;                        //若没找到，指针向后移动
        j++;
    }
    return p;                               //返回前驱结点的地址，注意此处也可能是空指针
}

//删除结点
bool Delete_Linklist(LinkList &L,int i){
    LNode *p,*q;
    p = Get_Elem_Address(L,i-1);
    if(p==NULL){
        printf("删除位置不合法");
        return false;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    printf("删除第%d个结点后",i);
    return 0;
}

//打印单链表
void Print_Linklist(LinkList &L){
    LNode * p = L;
    printf("\n链表序列为:\n");
    while(p!=NULL){
        printf("%d\t",p->data);
        p = p->next;
    }
}

int main(){
    LinkList L;
    L = Init_List(L);
    Create_List_tail(L);
    Print_Linklist(L);
    printf("\n主函数中的L地址 = %p\n",&L);
    Delete_Linklist(L,2);
    Print_Linklist(L);
    return 0;
}