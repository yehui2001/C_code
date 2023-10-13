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
        r->next = s;                        //在表尾插入新结点
        r = s;                              //令表尾指针始终指向表尾
        cin >> x;                      
    }
    r->next = NULL;                         //尾结点置空
    return L;
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

void Find_Same(LinkList &L1,LinkList &L2,LinkList &L){
    LNode *p = L1->next,*q = L2->next,*s = L;               //传入的s表默认初始化
    while(p&&q){
        if(p->data==q->data){                               //若值相同
            LNode *r;
            r = new LNode;                                  //创建新结点，并赋值
            r->data = p->data;                               
            s->next = r;                                    //将其链接到L表的末尾
            s = r;                                          //s是指向L的队尾指针
            p = p->next;
            q = q->next;
        }
        else if(p->data < q->data){
            p = p->next;                                    //若p值更小，向后查找等于的q值的p
        }
        else                                                //若q值更小，向后查找等于的p值的q
            q = q->next;
    }
    s->next = NULL;                 //若L表未初始化需要添加表尾指针指向NULL
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
    LinkList L1,L2,L;
    Init_List(L1);
    Init_List(L2);
    Create_List_tail(L1);
    Create_List_tail(L2);
    cout << "序列1:";
    Print_Linklist(L1);
    cout << "序列2:";
    Print_Linklist(L2);
    Find_Same(L1,L2,L);
    Print_Linklist(L);
    return 0;
}