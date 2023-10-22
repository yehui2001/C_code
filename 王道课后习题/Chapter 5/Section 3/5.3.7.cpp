#include<iostream>
using namespace std;

//定义结构体
typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

struct QNode{
    BiTNode *BT;
    QNode *next;
};

typedef struct{
    struct QNode *front,*rear;
}LinkQueue;

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
    if(EmptyQueue(Q))  return false;
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

//前序遍历
void preOrder(BiTree T){
    if(T!=NULL){
        visit(T);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}


bool Judge_Complete(BiTree T){
    BiTNode *p;
    LinkQueue Q;
    InitQueue(Q);
    if(!T)  return 1;               //空树为满二叉树
    EnQueue(Q,T);
    while(!EmptyQueue(Q)){
        DeQueue(Q,p);
        if(p){
            EnQueue(Q,p->lchild);
            EnQueue(Q,p->rchild);
        }
        else while(!EmptyQueue(Q)){  //若出队是空结点，看其后有无非空结点
            DeQueue(Q,p);
            if(p)   return 0;       //结点非空，非完全二叉树
        }
    }
    return 1;
}

//输入:AB##CD###    ABD###C##
int main(){
    BiTree T;
    cout << "----------------------------------" << endl;
    cout << "请输入带有#的扩充二叉树先根遍历序列:" << endl;             
    Create_tree(T);
    if(Judge_Complete(T))
        cout << "二叉树为完全二叉树"<< endl;
    else
        cout << "二叉树为非完全二叉树"<< endl;
    cout << "----------------------------------" << endl;
    return 0;
}