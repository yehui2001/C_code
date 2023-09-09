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

void Sort_Link(LinkList &L){
    LNode *p = L->next,*pre;                 //
    LNode *r = p->next;
    p->next = NULL;                          //创造只含有一个元素的有序表，和含有n-1个元素的无序表
    p = r;
    while(p!=NULL){
        r = p->next;
        pre = L;                             //pre每次从已排序列的头结点开始
        while(pre->next!=NULL && p->data > pre->next->data)//向后查找，找到p的位置
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = r;                               //每插入一个元素，待排序列的指针向后移动
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
    Sort_Link(L);
    Print_Linklist(L);
    return 0;
}