#include<iostream> 
using namespace std;

typedef int ElemType;

// 定义单链表中的结点类型
typedef struct LNode{
    ElemType data;          //数据域
    struct LNode *next;     //指针域
}LNode,*LinkList;           //重命名后的Linklist常用来定义单链表的头指针

//初始化单链表
LinkList Init_List(LinkList &L){
    L = new LNode;
    L = NULL;
    //cout << "初始化函数中的L地址= "<< &L <<endl;
    return L;
}

//头插法建立单链表
LinkList Create_List_head(LinkList &L){
    int x;
    LNode *s;
    cout << "请输入想要添加的数据:";
    cin >> x;
    while(x!=9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L;                   //让新结点成为首结点
        L = s;                         //令新插入的结点始终是头节点
        cin >> x;
    }
    return L;
}

//尾插法建立单链表
LinkList Create_List_tail(LinkList &L){
    int x;
    LNode *s,*r = L;                        //r为表尾指针
    cout << "请输入想要添加的数据:"<< endl;
    cin >> x;
    while(x!=9999){
        if(L==NULL){                            
            s = (LNode*)malloc(sizeof(LNode));
            s->data = x;
            s->next = NULL;
            L = s;                              
            r = s;                              
            cin >> x;                     
        }
        else{
            s = (LNode*)malloc(sizeof(LNode));
            s->data = x;
            r->next = s;
            r = s;
            cin >> x;                
        }
    }
    r->next = NULL;                         //尾结点置空
    return L;
}

//删除所有值为x的结点
void Delete_Node(LinkList &L,ElemType x){
    if(L==NULL)                                 //指向的结点为空跳出递归
        return;
    LNode *p;
    if(L->data ==x){                            //当前结点的值若为x，用p指针帮助删除结点
        p = L;                                  //注意此处传参的L，不是首地址，而是每个结点的地址。
        L = L->next;                            //此处为什么不断链？因为此处的L实际上是上一个传入参数的L->next,该操作其实上是L->next = L->next->next;恰好把L->next所指结点删除
        delete p;                               
        Delete_Node(L,x);                       //此时的L已经为L->next，实际已经在向后查找了
    }
    else                                        //当前值不为x，向后查找传入L->next
        Delete_Node(L->next,x);
}

//打印单链表
void Print_Linklist(LinkList &L){
    LNode * p = L;
    cout << "链表序列:" <<endl;
    while(p!=NULL){
        cout <<'\t'<< p->data;
        p = p->next;
    }
    cout << endl;
}

int main(){
    LinkList L;
    L = Init_List(L);
    Create_List_tail(L);
    Print_Linklist(L);
    //cout << "\n" << "主函数中的L地址="<< &L <<endl;
    //Delete_Linklist(L,2);
    Delete_Node(L,2);
    Print_Linklist(L);
    return 0;
}