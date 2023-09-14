//该程序实现带头结点的循环单链表的定义及基础操作
#include<iostream>
using namespace std;

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
    return true;                            
}

//尾插法建立单链表
LinkList Create_List_tail(LinkList &L){
    int x;
    LNode *s,*r = L;                        //r为表尾指针
    cout << "请输入想要添加的数据:" << endl;
    cin >> x;
    while(x!=9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;                        //在表尾插入新结点
        r = s;                              //令表尾指针始终指向表尾
        cin >> x;                     //若cin >> “%d”里面有其他内容，输入时需要一并键入
    }
    r->next = L;                            //尾结点置空
    return L;
}

void Connect_Linklist(LinkList &h1,LinkList &h2){
    LNode *p = h1,*q = h2;
    while(p->next!=h1){
        p = p->next;
    }
    while(q->next!=h2){
        q = q->next;
    }
    p->next = h2->next;     //h2的头结点无数据，跳过
    q->next = h1;
    delete h2;
}

//打印单链表
void Print_Linklist(LinkList &L){
    LNode *p = L->next;                      //从头指针后的第一个结点开始打印
    printf("\n链表序列为:\n");
    while(p!=L){
        cout << "\t" << p->data;
        p = p->next;
    }
    cout << endl;
}

int main(){
    LinkList L1,L2;
    Init_List(L1);
    Init_List(L2);
    Create_List_tail(L1);
    Print_Linklist(L1);
    Create_List_tail(L2);
    Print_Linklist(L2);
    Connect_Linklist(L1,L2);
    Print_Linklist(L1);
}