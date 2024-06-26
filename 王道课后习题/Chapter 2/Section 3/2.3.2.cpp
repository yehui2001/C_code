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

// 删除所有值为x的结点
void Delete_Node(LinkList &L,ElemType x){
    LNode *p = L->next,*pre = L,*q;             //引用一个前驱结点用以防止断链
    while(p!=NULL){                 
        if(p->data==x){                         
          q = p;
          p = p->next;
          pre->next = p;                        //链接
          delete q;  
        }
        else{                                   //若当前结点值非x，pre和p同步后移
            pre = p;
            p = p->next;
        }
    }
}

//法二
//法一法二区别在于，法一对删除操作采用了链接链表，法二采用非x结点插入表中
void Delete_Node_2(LinkList &L,ElemType x){
    LNode *p = L->next,*r = L,*q;               //r指针也用来作为前驱结点
    while(p!=NULL){                             
        if(p->data !=x){
            r->next = p;
            r = p;
            p = p->next;
        }
        else{
            q = p;
            p = p->next;
            delete q;
        }
    }
    r->next = NULL;
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
    Init_List(L);
    Create_List_tail(L);
    Print_Linklist(L);
    Delete_Node(L,6);
    Print_Linklist(L);
    return 0;
}