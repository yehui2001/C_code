//基于单链表的快速排序算法
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

LNode *Get_End(LinkList L){
    LNode *p = L;
    while(p->next!=NULL)
        p = p->next;
    return p;
}

LNode *Get_Mid(LinkList L,LNode *end){
    int key = L->data,temp;
    LNode *p = L,*q = p->next;
    while(q!=end){
        if(key>q->data){                    //若q指向的值比基准元素值小，则不交换,即p，q交换同一个元素
            p = p->next;                    //若q与p不是相邻，则说明至少有一个q->data > key，下次p，q交换，交换的是大于key的值和小于key的值
            temp = p->data;
            p->data = q->data;
            q->data = temp;
        }
        q = q->next;
    }//while
    temp = p->data;                         //此处不用能直接用temp，因为temp是未交换前p的值
    L->data = temp;                         //将p指针的值与基准元素的值交换
    p->data = key;
    return p;
}


void QuickSort(LinkList L,LNode *end){
    if(L!=end){
        LNode *mid = Get_Mid(L,end);
        QuickSort(L,mid);
        QuickSort(mid->next,end);
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
    LNode *end = Get_End(L);
    QuickSort(L->next,NULL);
    Print_Linklist(L);
    return 0;
}