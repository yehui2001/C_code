//基于无头单链表
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
    cout << "初始化函数中的L地址= "<< &L <<endl;
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
        if(L==NULL){                            //由于无头结点的特殊性，创建的第一个结点需要重新赋予头指针
            s = (LNode*)malloc(sizeof(LNode));
            s->data = x;
            s->next = NULL;
            L = s;                              //令新创建的结点作为第一个结点
            r = s;                              //令表尾指针始终指向表尾
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

//按序查找结点
LNode *Get_Elem_Address(LinkList &L,int i){
    if(i<1)
        return NULL;                        //查找位置不合法
    LNode *p;                               //指针p为当前扫描到的结点
    int j=1;                                //p当前指向结点位序（头节点默认为0）
    p = L;                                  //从头节点开始
    while(p!=NULL&&j<i){                    //指针p扫描到表尾结束，或者找到第i个结点的前驱结点结束
        p = p->next;                        //若没找到，指针向后移动
        j++;
    }
    return p;                               //返回前驱结点的地址，注意此处也可能是空指针
}

//删除结点
bool Delete_Linklist(LinkList &L,int i){
    LNode *p,*q;
    p = Get_Elem_Address(L,i-1);
    if(p==NULL){
        cout << "删除位置不合法";
        return false;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    cout << "删除第"<< i<< "个结点后" ;
    return 0;
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
    cout << "\n" << "主函数中的L地址="<< &L <<endl;
    //Delete_Linklist(L,2);
    Print_Linklist(L);
    return 0;
}