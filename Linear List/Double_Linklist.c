//该程序实现基于带头节点的双链表的定义及基础操作
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
// 定义双链表中的结点类型
typedef struct DNode{
    ElemType data;                 //数据域
    struct DNode *prior,*next;     //指针域
}DNode,*DLinkList;           

//初始化双链表
bool Init_DList(DLinkList &L){
    L = (DNode *)malloc(sizeof(DNode));     //申请一个头节点
    if(L==NULL)
        return false;                       //申请内存失败
    L->next = NULL;                         //此时头节点也作为尾结点应该指向空指针
    L->prior = NULL;
    printf("初始化函数中L的地址:%p\n",&L);     //加取地址符是返回L指针的地址
    return true;                            //不加地址符是返回L地址所指对象的地址
}

//尾插法建立双链表
DLinkList Create_DList_tail(DLinkList &L){
    int x;
    DNode *s,*r = L;                        //r为表尾指针
    printf("请输入想要添加的数据:");
    scanf("%d",&x);
    while(x!=9999){
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;
        s->prior = r;
        r->next = s;                        //在表尾插入新结点
        r = s;                              //令表尾指针始终指向表尾
        scanf("%d",&x);                     //若scanf“%d”里面有其他内容，输入时需要一并键入
    }
    r->next = NULL;                         //尾结点置空
    return L;
}

//按序查找结点
DNode *Get_Elem_Address(DLinkList &L,int i){
    if(i<0)
        return NULL;                        //查找位置不合法，此处认为可以查找第0个结点
    DNode *p;                               //指针p为当前扫描到的结点
    int j=0;                                //p当前指向结点位序（头节点默认为0）
    p = L;                                  //从头节点开始
    while(p!=NULL&&j<i){                    //指针p扫描到表尾结束，或者找到第i个结点的前驱结点结束
        p = p->next;                        //若没找到，指针向后移动
        j++;
    }
    return p;                               //返回前驱结点的地址，注意此处也可能是空指针
}

//插入操作
bool Insert_DLinklist(DLinkList &L,int i,ElemType e){
    DNode *s,*p;
    s = (DNode*)malloc(sizeof(DNode));
    s->data = e;
    p = Get_Elem_Address(L,i-1);
    if(p==NULL){
        return false;
    }
    if(p->next==NULL){
        s->next = p->next;          //若插入结点要作为最后结点，则不需要其后面的NULL的前驱指针指向它。
        p->next = s;
        s->prior = p;
    }
    else{
        s->next = p->next;
        p->next->prior = s;
        p->next = s;
        s->prior = p;
    }
    return true;
}

//打印单链表
void Print_DLinklist(DLinkList &L){
    DNode *p = L->next;                      //从头指针后的第一个结点开始打印
    printf("\n链表序列为:\n");
    while(p!=NULL){
        printf("%d\t",p->data);
        p = p->next;
    }
}

int main(){
    DLinkList L;
    Init_DList(L);
    Create_DList_tail(L);
    Print_DLinklist(L);
    Insert_DLinklist(L,2,99);
    Print_DLinklist(L);
}