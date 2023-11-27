#include<iostream>
using namespace std;

//定义结构体
typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

typedef struct SNode{
    BiTNode *BT;
    struct SNode *next;
}*LinkStack;

struct QNode{
    BiTNode *BT;
    QNode *next;
};

typedef struct{
    struct QNode *front,*rear;
}LinkQueue;

LinkStack InitStack(LinkStack &S){
    S = new SNode;
    S = NULL;
    return S;
}

bool Push(LinkStack &S,BiTNode *&T){
    SNode *s;
    s = new SNode;
    s->BT = T;
    s->next = S;                   //让新结点成为首结点
    S = s;                         //令新插入的结点始终是头节点
    return true;
}

bool Pop(LinkStack &S,BiTNode *&T){
    if(S==NULL){
       return false; 
    }
    SNode *p,*q;
    T = S->BT;
    p = S;
    q = S->next;
    S = q;
    delete p;
    return true;
}

bool EmptyStack(LinkStack &S){
    return (S==NULL);
}

void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = new QNode;                           //建立头节点
    Q.front->next = NULL;                                  //初始为空
}

bool EmptyQueue(LinkQueue &Q){
    if(Q.front==Q.rear)
        return true;
    return false;
}

void EnQueue(LinkQueue &Q,BiTNode *&T){
    QNode *s;
    s = new QNode;
    s->BT = T;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q,BiTNode *&T){
    if(EmptyQueue(Q)||T==NULL)  return false;
    QNode *p = Q.front->next;
    T = p->BT;
    Q.front->next = p->next;
    if(Q.rear == p)  Q.rear = Q.front;      //若原队列只有一个结点，删除后变空,若此行不加，在空队中插入时，会断链(Q.front消失)
    delete p;
    return true;
}

//访问该结点，并打印该值
void visit(BiTree T){
    if(T!=NULL)
    printf("%c",T->data);
}

void LevelOrder(BiTree T){
    BiTNode *p;
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,T);
    while(!EmptyQueue(Q)){
        DeQueue(Q,p);
        
        visit(p);
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);
        if(p->rchild!=NULL)
            EnQueue(Q,p->rchild);
    }
}

//层序遍历(自下而上，自右而左)
//只需要将我们原来出队后访问的操作改为出队后压栈即可
void Invert_LevelOrder(BiTree T){
    BiTNode *p;
    LinkQueue Q;
    LinkStack S;
    InitStack(S);
    InitQueue(Q);
    EnQueue(Q,T);
    while(!EmptyQueue(Q)){
        DeQueue(Q,p);
        Push(S,p);
        
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);
        if(p->rchild!=NULL)
            EnQueue(Q,p->rchild);
    }

    while(!EmptyStack(S)){
        Pop(S,p);
        visit(p);
    }
}



//递归建树  以先序遍历序列为例
void Create_tree(BiTree &T){
    char c;
    scanf("%c",&c);                 //输入的c序列和对应Create函数递归顺序应该与对应遍历序列一致
    if(c =='#')                    
        T = NULL;                   
    else{
        T = (BiTNode*)malloc(sizeof(BiTNode));
        T->data = c;
        Create_tree(T->lchild);
        Create_tree(T->rchild);
    }
}

int main(){
    BiTree T;
    cout << "----------------------------------" << endl;
    cout << "请输入带有#的扩充二叉树先根遍历序列:" << endl;             //例如AB##CD###
    Create_tree(T);
    printf("\n层序遍历序列:");
    Invert_LevelOrder(T);
    cout << "----------------------------------" << endl;
    return 0;
}



