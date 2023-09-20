//该程序实现基于带头节点的单链表的定义及基础操作
#include<iostream>
using namespace std;
#define n 10

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
    L->next = NULL;                         //此时头节点也作为尾结点应该指向空指针
    //cout << "初始化函数中L的地址:"<<&L<< endl; //加取地址符是返回L指针的地址
    return true;                            //不加地址符是返回L地址所指对象的地址
}

//尾插法建立单链表
LinkList Create_List_tail(LinkList &L){
    int x;
    LNode *s,*r = L;                        //r为表尾指针
    cout << "请输入想要添加的数据:" <<endl;
    cin >> x;
    while(x!=9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;                        //在表尾插入新结点
        r = s;                              //令表尾指针始终指向表尾
        cin >> x;                     //若cin >> “%d”里面有其他内容，输入时需要一并键入
    }
    r->next = NULL;                         //尾结点置空
    return L;
}


//打印单链表
void Print_Linklist(LinkList &L){
    LNode *p = L->next;                      //从头指针后的第一个结点开始打印
    cout << "链表序列为:" << endl;
    while(p!=NULL){
        cout << "\t" << p->data;
        p = p->next;
    }
    cout << endl;
}

void Resort(LinkList &L){
    LNode *p,*q,*r,*s;
    p = q = L;
    while(q->next!=NULL){                   //寻找中间结点
        p = p->next;                        //p走一步
        q = q->next;                        
        if(q->next!=NULL) q = q->next;      //q走两步
    }
    q = p->next;                            //p即为中间结点，令q为后半段的头结点
    p->next = NULL;                         //此时的p为前半段的尾结点，其next->NULL,且前半段长度>=后半段，最多长1，如 1 2 3 | 5 4 
    while(q!=NULL){                         //将链表后半段逆置，运用头插法,每次在p结点后面插入新结点
        r = q->next;                        //防止断链，记录未插入结点
        q->next = p->next;
        p->next = q;
        q = r;                              //此时链的相对位置: 1 2 3.....n n-1.....
    }
    s = L->next;                            //依次将后半段中的第一个结点插入到前半段的第一个结点后面
    q = p->next;
    p->next = NULL;
    while(q!=NULL){
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = r;
    }
}



int main(){
    LinkList L;
    Init_List(L);
    Create_List_tail(L);
    Print_Linklist(L);
    Resort(L);
    Print_Linklist(L);
    return 0;
}