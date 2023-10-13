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
    L = new LNode;
    if(L==NULL)
        return false;
    L->next = NULL;
    return true;
}

//尾插法建立单链表
LinkList Create_List_tail(LinkList &L,int &n){
    int x,i=0;
    LNode *s,*r = L;                        //r为表尾指针
    cout << "请输入想要添加数据的个数:"<< endl;
    cin >> n;
    while(i!=n){ 
        cin >> x;      
        i++;               
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;                        //在表尾插入新结点
        r = s;                              //令表尾指针始终指向表尾                                               
    }
    r->next = NULL;                         //尾结点置空
    return L;
}

bool Central(LinkList L,int n){
    char s[n/2];
    int i;
    LNode *p = L->next;
    for(i = 0; i < n/2; i++){
        s[i] = p->data;
        p = p->next;
    }
    i--;                                    //让i回到[n/2]
    if(n%2==1) p = p->next;                 //若n是奇数，则后移单链表跳过中心结点
    while(p!=NULL && s[i] == p->data){      //s[i]出栈与单链表元素对照
        i--;
        p = p->next;
    }
    if(i==-1){
        cout << "中心对称" << endl;
        return 1;
    }
    else 
        cout << "非中心对称" << endl;
        return 0;
}

//打印单链表
void Print_Linklist(LinkList &L){
    LNode * p = L->next;
    cout << "链表序列:" <<endl;
    while(p!=NULL){
        cout <<'\t'<< p->data;
        p = p->next;
    }
    cout << endl;
}


int main(){
    int n;
    LinkList L;
    Init_List(L);
    Create_List_tail(L,n);
    Print_Linklist(L);
    Central(L,n);
    return 0;
}
