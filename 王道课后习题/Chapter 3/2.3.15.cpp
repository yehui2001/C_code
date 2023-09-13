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

//此题在14题的代码基础上加以修改，将插入的起始点换到L1
void Merge_Same(LinkList &L1,LinkList &L2){
    LNode *p = L1->next,*q = L2->next,*s = L1;    
    while(p&&q){
        if(p->data==q->data){
            LNode *r;
            r = new LNode;
            r->data = p->data;
            s->next = r;                //在执行第一次插入操作时，L1就已经断链了
            s = r;
            p = p->next;
            q = q->next;
        }
        else if(p->data < q->data){
            p = p->next;
        }
        else
            q = q->next;
    }
    delete L2;
}

//课后题的答案
void Union(LinkList &L1,LinkList &L2){
    LNode *p = L1->next;
    LNode *q = L2->next;
    LNode *u,*r = L1;
    while(p&&q){
        if(p->data==q->data){
            r->next = p;
            r = p;                              //r指向结果表的表尾
            p = p->next;                
            u = q;                              //释放q结点
            q = q->next;                        
            delete u;
        }
        else if(p->data>q->data){
            u = q;
            q = q->next;
            delete u;
        }
        else{
            u = p;
            p = p->next;
            delete u;
        }
    }
    while(p){                           //处理还未
        u = p;
        p = p->next;
        delete u;
    }
    while(q){
        u = q;
        q = q->next;
        delete u;
    }
    r->next = NULL;
    delete L2;
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
    LinkList L1,L2;
    Init_List(L1);
    Init_List(L2);
    Create_List_tail(L1);
    Create_List_tail(L2);
    cout << "序列1:";
    Print_Linklist(L1);
    cout << "序列2:";
    Print_Linklist(L2);
    //Merge_Same(L1,L2);
    Union(L1,L2);
    Print_Linklist(L1);
    return 0;
}