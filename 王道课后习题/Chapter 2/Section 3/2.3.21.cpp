//该程序实现基于带头节点的单链表的定义及基础操作
#include<iostream>
#include <cstdlib>          //随机数
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
    //cout << "初始化函数中L的地址:"<<&L<< endl; //加取地址符是返回L指针的地址
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
        cin >> x;                     //若cin >> “%d”里面有其他内容，输入时需要一并键入
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

//随机数    产生 [a,b] 范围内到随机数 
int Rand(){
    int a = 1,b = 8;
    srand((unsigned)time(NULL));        //添加当前时间为随机数种子，不加这行就产生伪随机数
    return a + rand()%(b-a+1);
}

//手动创建让链表带环
void Generate_circular(LinkList &L){
    LNode *p = L,*q;
    int Tag = 0;                                //在第五个结点位置进环
    while(Tag!=Rand()){                         
        p = p->next;
        Tag++;
    }
    q = p;
    p = L;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = q;

}

//先找到相遇点，又因为a = n*r - x,所以从头结点到入口处的距离 与 从相遇点处移动n-1圈后到入口处的距离 相同
//a:头结点到入口处的距离
//r:环长
//x:入口处到相遇点处的距离
LNode *Find_circular(LinkList &L){
    LNode *fast = L,*slow = L;
    while(fast!=NULL&&fast->next!=NULL){        //为什么要加两个判断条件，因为fast指针一次跳两步，有可能会跳在最后一个结点停止，也有可能会跳在NULL指针上停止
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow)  break;                  //找到相遇点
    }
    if(fast==NULL||fast->next==NULL)
        return NULL;
    LNode *p1 = L,*p2 = slow;                //分别指向开始点，相遇点
    while(p1!=p2){
        p1 = p1->next;
        p2 = p2->next;
    }
    LNode *p = L;
    int Tag = 0;
    while(p!=p1){
        p = p->next;
        Tag++;
    }
    cout << "入口处的位置在" << Tag <<"个结点处"<<endl;
}

int main(){
    LinkList L;
    Init_List(L);
    Create_List_tail(L);
    Print_Linklist(L);
    Generate_circular(L);
    Find_circular(L);
    return 0;
}