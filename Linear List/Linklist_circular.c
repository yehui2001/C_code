//该程序实现带头结点的循环单链表的定义及基础操作
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
// 定义单链表中的结点类型
typedef struct LNode{
    ElemType data;          //数据域
    struct LNode *next;     //指针域
}LNode,*LinkList;           //重命名后的Linklist常用来定义单链表的头指针

//初始化单链表
bool Init_List(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));     //申请一个头节点
    if(L==NULL)
        return false;                       //申请内存失败
    L->next = L;                         //此时尾结点应该指向自身
    printf("初始化函数中L的地址:%p\n",&L);    
    return true;                            
}

//尾插法建立单链表
LinkList Create_List_tail(LinkList &L){
    int x;
    LNode *s,*r = L;                        //r为表尾指针
    printf("请输入想要添加的数据:");
    scanf("%d",&x);
    while(x!=9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;                        //在表尾插入新结点
        r = s;                              //令表尾指针始终指向表尾
        scanf("%d",&x);                     //若scanf“%d”里面有其他内容，输入时需要一并键入
    }
    r->next = L;                         //尾结点置空
    return L;
}

//打印单链表
void Print_Linklist(LinkList &L){
    LNode *p = L->next;                      //从头指针后的第一个结点开始打印
    printf("\n链表序列为:\n");
    while(p!=L){
        printf("%d\t",p->data);
        p = p->next;
    }
}

int main(){
    LinkList L;
    Init_List(L);
    Create_List_tail(L);
    Print_Linklist(L);
}