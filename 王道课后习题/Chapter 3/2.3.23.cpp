//该程序实现基于带头节点的单链表的定义及基础操作
#include<iostream>
using namespace std;

typedef char ElemType;
// 定义单链表中的结点类型
typedef struct LNode{
    ElemType data;          //数据域
    struct LNode *next;     //指针域
}LNode,*LinkList;           //重命名后的Linklist常用来定义单链表的头指针

//初始化单链表
bool Init_List(LinkList &L){
    L = new LNode;     //申请一个头节点
    if(L==NULL)
        return false;                       //申请内存失败
    L->next = NULL;                         //此时头节点也作为尾结点应该指向空指针
    //cout << "初始化函数中L的地址:"<<&L<< endl; //加取地址符是返回L指针的地址
    return true;                            //不加地址符是返回L地址所指对象的地址
}

//尾插法建立单链表
LinkList Create_List_tail(LinkList &L){
    char x;
    LNode *s,*r = L;                        //r为表尾指针
    cout << "请输入想要添加的数据(输入'/'停止):" <<endl;
    cin >> x;
    while(x!='/'){                          //输入/停止
        s = new LNode;
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

//要求时间高效，采取空间换时间
//基于L1，L2创建两个新的链表，采用头插法。
//从头开始查找第一个值不相同的结点。
void Find_Common_suffix(LinkList L1,LinkList L2){
    LNode *p1 = L1->next,*p2 = L2->next;
    LNode *str1 = new LNode,*s,*str2 = new LNode;
    str1->next = NULL;
    str2->next = NULL;
    while(p1!=NULL){
        s = p1->next;
        p1->next = str1->next;
        str1->next = p1;
        p1 = s;
    }
    L1 = str1;
    while(p2!=NULL){
        s = p2->next;
        p2->next = str2->next;
        str2->next = p2;
        p2 = s;
    }
    L2 = str2;
    int Tag = 0;
    str1 = str1->next;
    str2 = str2->next;
    while(str1!=NULL||str2!=NULL){
        if(str1->data!=str2->data)
            break;
        Tag++;
        str1 = str1->next;
        str2 = str2->next;
        if(str2==NULL||str1==NULL)
            break;
    }
    cout <<"公共后缀位置位于倒数第"<< Tag << "位置" << endl;
}



int main(){
    LinkList L1,L2;
    Init_List(L1);
    Init_List(L2);
    Create_List_tail(L1);
    Create_List_tail(L2);
    Print_Linklist(L1);
    Print_Linklist(L2);
    Find_Common_suffix(L1,L2);
    //Print_Linklist(L1);
    return 0;
}