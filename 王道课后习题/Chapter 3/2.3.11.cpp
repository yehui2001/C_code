//该程序实现基于带头节点的单链表的定义及基础操作
#include<iostream>
using namespace std;

typedef int ElemType;
// 定义单链表中的结点类型
typedef struct LNode{
    ElemType data;          //数据域
    struct LNode *next;     //指针域
}*LinkList;                 //重命名后的Linklist常用来定义单链表的头指针

//初始化单链表
bool Init_List(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));     //申请一个头节点
    if(L==NULL)
        return false;                       //申请内存失败
    L->next = NULL;                         //此时头节点也作为尾结点应该指向空指针
    //cout << "初始化函数中L的地址:"<<&L<< endl; //加取地址符是返回L指针的地址
    return true;                            //不加地址符是返回L地址所指对象的地址
}

//要求从尾到头反向输入每个结点的值
//尾插法建立单链表
LinkList Create_List_tail(LinkList &L){
    int x;
    LNode *s,*r = L;                        //r为表尾指针
    cout << "请输入想要添加的数据:" <<endl;
    cin >> x;
    while(x!=9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;                         //在表尾插入新结点
        r = s;                               //令表尾指针始终指向表尾
        cin >> x;                      
    }
    r->next = NULL;                          //尾结点置空
    return L;
}

//与上题大差不差，区别在于对B表的建立采用头插法
void Split_twoside(LinkList &L,LinkList &L2){
    LNode *p = L->next,*q;              //p为A的结点      
    while(p->next!=NULL){               //若p为空结点，p->next就没有，此处会报错
        q = p->next->next;
        p->next->next = L2->next;       //p->next结点头插入偶数序列中
        L2->next = p->next;
        p->next = q;                
        p = p->next;                    //p后移
        if(p==NULL){                    //若p结点已空，跳出循环
            break;
        }
    }
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


int main(){
    LinkList L;
    LinkList L2;
    Init_List(L);
    Init_List(L2);
    Create_List_tail(L);
    Print_Linklist(L);
    Split_twoside(L,L2);
    Print_Linklist(L2);
    return 0;
}