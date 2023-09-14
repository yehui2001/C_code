//该程序实现基于带头节点的循环双链表的定义及基础操作
#include<iostream>
using namespace std;

typedef int ElemType;
// 定义双链表中的结点类型
typedef struct DNode{
    ElemType data;                 //数据域
    struct DNode *prior,*next;     //指针域
}DNode,*DLinkList;           

//初始化双链表
bool Init_DList(DLinkList &L){
    L = (DNode *)malloc(sizeof(DNode));     //申请一个头节点
    if(L==NULL)
        return false;                       //申请内存失败
    L->next = L;                         
    L->prior = L;
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
        s->prior = r;
        r->next = s;                        //在表尾插入新结点
        r = s;                              //令表尾指针始终指向表尾
        cin >> x;                 
    }
    r->next = L;                         //尾结点置空
    L->prior = r;
    return L;
}

void Judge_Symmetry(DLinkList L){
    DNode *p = L->next,*q = L->prior;
    while(p->data==q->data&&p!=L){      //从两个方向开始查找，只有结点值不同，或者找完一趟后结束
        p = p->next;
        q = q->prior;
    }
    if(p==L)                            //若结束位置是L处（找完一趟）则表示对称
        cout << "\n" <<"该双链表对称"<< endl;
    else{
        cout << "\n" << "该双链表不对称"<< endl;
    }
}

//答案
//思路：从两头判断，结束条件
int Symmetry(DLinkList L){
    DNode *p = L->next,*q = L->prior;
    while(p!=q&&q->next!=p)             //此处不能写成p->next!=q
        if(p->data==q->data){           //1 2 3 4 2 1 若写成p->next!=q,则不会进行第三次比较
            p = p->next;                //若写成q->next!=p，会进行第三次比较,然后移动后的p指向4，q指向3，q的next的p，跳出
            q = q->prior;
        }
        else{
            cout <<"不对称"<< endl;
            return 0;
        }
    cout <<"对称"<< endl;
    return 1;
}


//打印单链表
void Print_DLinklist(DLinkList &L){
    DNode *p = L->next;                      //从头指针后的第一个结点开始打印
    cout << "链表序列为:" << endl;
    while(p!=L){
        cout << "\t" << p->data;
        p = p->next;
    }
}

int main(){
    DLinkList L;
    Init_DList(L);
    Create_DList_tail(L);
    Print_DLinklist(L);
    //Judge_Symmetry(L);
    Symmetry(L);
}