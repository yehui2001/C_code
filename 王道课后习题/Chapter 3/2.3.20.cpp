//该程序实现基于带头节点的双链表的定义及基础操作
#include<iostream>
using namespace std;

typedef int ElemType;
// 定义双链表中的结点类型
typedef struct DNode{
    ElemType data;                 //数据域
    struct DNode *prior,*next;     //指针域
    int freq;                      //访问频度
}DNode,*DLinkList;           

//初始化双链表
bool Init_DList(DLinkList &L){
    L = (DNode *)malloc(sizeof(DNode));     //申请一个头节点
    if(L==NULL)
        return false;                       //申请内存失败
    L->next = NULL;                         //此时头节点也作为尾结点应该指向空指针
    L->prior = NULL;
    return true;                         
}

//尾插法建立双链表
DLinkList Create_DList_tail(DLinkList &L){
    int x;
    DNode *s,*r = L;                        //r为表尾指针
    cout << "请输入想要添加的数据:" << endl;
    cin >> x;
    while(x!=9999){
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;
        s->freq = 0;
        s->prior = r;
        r->next = s;                        //在表尾插入新结点
        r = s;                              //令表尾指针始终指向表尾
        cin >> x;                 
    }
    r->next = NULL;                         //尾结点置空
    return L;
}

//打印单链表
void Print_DLinklist(DLinkList &L){
    DNode *p = L->next;                      //从头指针后的第一个结点开始打印
    cout << ("\n链表序列为:\n");
    while(p!=NULL){
        cout << "\t" << p->data;
        p = p->next;
    }
}

//结合频度排序的x值查找
DNode *Locate(DLinkList &L,ElemType x){
    DNode *p = L->next,*q;
    while(p->data!=x&&p->next!=NULL){                //查到x或者找完一遍后退出
        p = p->next;
    }
    if(p==NULL)
        exit(0);
    p->freq++;
    if(p->next==L||p->prior->freq>p->freq)      //若查找的值是首结点或者freq++后还是小于前驱
        return p;                               //则直接返回
    
    if(p->next!=NULL)
        p->next->prior = p->prior;
    p->prior->next = p->next;                   //将目标结点摘下来
    
    q  = p->prior;                              //查找插入位置
    while(q!=L&&q->freq<=p->freq)               //直到知道比该结点频度大的结点q时，终止
        q = q->prior;
    p->next = q->next;                          //找到位置后，插入
    if(q->next!=NULL)                           //防止q->next==NULL;以下皆为双链表的插入操作
        q->next->prior = p;
    p->prior = q;
    q->next = p;
    return p;
}

int main(){
    DLinkList L;
    Init_DList(L);
    Create_DList_tail(L);
    Print_DLinklist(L);
    Locate(L,3);
    Print_DLinklist(L);
    Locate(L,2);
    Print_DLinklist(L);
}