//该程序实现基于带头节点的单链表的定义及基础操作
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
// 定义单链表中的结点类型
typedef struct LNode{
    ElemType data;          //数据域
    struct LNode *next;     //指针域
}LNode,*LinkList;           //重命名后的Linklist常用来定义单链表的头指针

//如果函数形参要通过指针传递，且该指针没有初始化，采用引用的形式进行参数初始化；
//因为指针，实质传递的也是值，这个值是一个未初始化变量的地址
//若不加&，新分配的头节点L获得一个新地址就与原来的LinkList L不一样了

//初始化单链表
bool Init_List(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));     //申请一个头节点
    if(L==NULL)
        return false;                       //申请内存失败
    L->next = NULL;                         //此时头节点也作为尾结点应该指向空指针
    printf("初始化函数中L的地址:%p\n",&L);     //加取地址符是返回L指针的地址
    return true;                            //不加地址符是返回L地址所指对象的地址
}

//按序查找结点
LNode *Get_Elem_Address(LinkList &L,int i){
    if(i<0)
        return NULL;                        //查找位置不合法，此处认为可以查找第0个结点
    LNode *p;                               //指针p为当前扫描到的结点
    int j=0;                                //p当前指向结点位序（头节点默认为0）
    p = L;                                  //从头节点开始
    while(p!=NULL&&j<i){                    //指针p扫描到表尾结束，或者找到第i个结点的前驱结点结束
        p = p->next;                        //若没找到，指针向后移动
        j++;
    }
    return p;                               //返回前驱结点的地址，注意此处也可能是空指针
}

//在i个位置插入结点
bool Insert_Node(LinkList &L,int i,ElemType e){
    LNode *p = Get_Elem_Address(L,i-1);     //查找插入位置（i）的前驱结点
    if(p==NULL)
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
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
    r->next = NULL;                         //尾结点置空
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
        s->next = L->next;                   //让新结点插在头节点跟第一个结点中间
        L->next = s;                         //令新插入的结点始终在头节点之后
        scanf("%d",&x);
    }
    return L;
}
//打印单链表
void Print_Linklist(LinkList &L){
    LNode *p = L->next;                      //从头指针后的第一个结点开始打印
    printf("\n链表序列为:\n");
    while(p!=NULL){
        printf("%d\t",p->data);
        p = p->next;
    }
}
//删除结点（直接删除第i个结点）
bool Delete_Linklist_1(LinkList &L,int i){
    LNode *p,*q;
    p = Get_Elem_Address(L,i-1);                //找到被删结点的前驱结点
    if(p==NULL)
        return false;
    q = p->next;                                //q指向被删除结点
    p->next = q ->next;
    free(q);
    return true;
}
//删除结点（通过删除该结点的后继i+1结点来达到目的）
bool Delete_Linklist_2(LinkList &L,int i){
    LNode *p,*q;
    p = Get_Elem_Address(L,i);
    if(p==NULL)
        return false;
    q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}
// 获取单链表长度 不计入头节点
int Length_Linklist(LinkList &L) {
    int len = 0;
    LNode *p = L->next;
    while (p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

int main(){
    LinkList L;
    Init_List(L);
    printf("主函数中的L地址 = %p\n",&L);
    Create_List_tail(L);
    Print_Linklist(L);
    Insert_Node(L,1,99);
    Insert_Node(L,2,999);
    Print_Linklist(L);
    Delete_Linklist_1(L,2);
    Print_Linklist(L);
    printf("\n表长为%d\n",Length_Linklist(L));
    return 0;
}