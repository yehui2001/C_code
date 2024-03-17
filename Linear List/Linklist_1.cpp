//该程序实现基于带头节点的单链表的定义及基础操作
#include<iostream>
using namespace std;

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

LNode *Get_Elem_Address2(LinkList &L,ElemType e){
    LNode *p = L->next;
    while(p && p->data!=e){
        p = p->next;
    }
    return p;
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

//头插法建立单链表
LinkList Create_List_head(LinkList &L){
    int x;
    LNode *s;
    cout << "请输入想要添加的数据:" << endl;
    cin >> x;
    while(x!=9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;                   //让新结点插在头节点跟第一个结点中间
        L->next = s;                         //令新插入的结点始终在头节点之后
        cin >> x;
    }
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

LNode* ReverseList(LNode* head) {
    // write code here
    LNode *p = head->next,*q;
    head->next = nullptr;
    while(p!=nullptr){
        q = p->next;                //记录后续结点
        p->next = head->next;       //接上head后面的结点
        head->next = p;             //插入结点
        p = q;                      //更新当前插入结点
    }
    return head;
}

int main(){
    LinkList L;
    Init_List(L);
    Create_List_tail(L);
    //cout << Get_Elem_Address(L,2) << endl;
    ReverseList(L);
    Print_Linklist(L);
    return 0;
}