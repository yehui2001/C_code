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


void Delete_Same(LinkList &L){
    LNode *p = L->next,*pre,*q;
    while(p!=NULL){
        if(p->data==p->next->data){          //找到重复值结点
            pre = p;
            while(p->next!=NULL&&p->data==p->next->data){        //向后查找下一个不同值的结点位置
                p = p->next;                                     //找到表尾，则结束查找
            }                 
            if(p->next==NULL){                                   //若后续无不同值，则从原值后面直接截断
                pre->next = NULL;
            }
            else{                                                //若后续有不同值，则跳过其他相同值结点，直接连接
                pre->next = p->next;
            }
        }
        p = p->next;
    }
}

//更推荐答案的找到一个重复删除一个
void Del_Same(LinkList &L){
    LNode *p = L->next,*q;
    if(p==NULL) return;
    while(p->next!=NULL){
        q = p->next;                    //记录后继结点
        if(p->data==q->data){           //若后续结点与当前结点相同，则删除
            p->next = q->next;
            delete q;
        }
        else
            p = p->next;
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
    Init_List(L);
    Create_List_tail(L);
    Print_Linklist(L);
    Delete_Same(L);
    Print_Linklist(L);
    return 0;
}