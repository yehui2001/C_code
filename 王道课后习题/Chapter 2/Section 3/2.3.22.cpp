//该程序实现基于带头节点的单链表的定义及基础操作
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
        cin >> x;                    
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

//找倒数第k个结点，双指针
bool Find_LNode(LinkList &L,int k){
    LNode *p = L,*q=NULL;
    int Tag = 0;
    while(p->next!=NULL){
        p = p->next;
        Tag++;
        if(Tag==k){
            q = L;
        }
        if(Tag>=k)
        q = q->next;
    }
    if(q==NULL)
    return 0;
    cout << "倒数第"<< k <<"个元素是:" << q->data << endl;
    return 1;
}

int main(){
    LinkList L;
    Init_List(L);
    Create_List_tail(L);
    Print_Linklist(L);
    Find_LNode(L,4);
    return 0;
}