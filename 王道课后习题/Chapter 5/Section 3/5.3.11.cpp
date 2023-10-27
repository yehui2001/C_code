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

//删除根结点的左右子树
void Delete(BiTree T){
    if(T){
        Delete(T->lchild);
        Delete(T->rchild);
        delete T;
    }
}

//要求只删左右子树，保留根结点，宜使用后序遍历
//使用层序遍历有利于找到父结点

//在二叉树上查找所以以x为元素值的结点，并删除以其为根的子树
void Search(BiTree T,ElemType x){
    BiTNode *p;
    if(T->data == x){
        Delete(T);
        exit(0);
    }
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,T);
    while(!EmptyQueue(Q)){
        DeQueue(Q,p);                
        if(p->lchild!=NULL){//左孩子入队前，需要提前判断是否为目标结点，若是直接删除左孩子的左子树即可
            if(p->lchild->data==x){
                Delete(p->lchild);
                p->lchild = NULL;
            }
            else 
                EnQueue(Q,p->lchild);
        }
        if(p->rchild!=NULL){
            if(p->rchild->data==x){
                Delete(p->rchild);
                p->rchild = NULL;
            }
        else
            EnQueue(Q,p->rchild);
        }
    }
}

//输入:AB##CD###    ABD###C##
int main(){
    BiTree T;
    cout << "----------------------------------" << endl;
    cout << "请输入带有#的扩充二叉树先根遍历序列:" << endl;     
    Create_tree(T);      
    cout << "原先根序列为:";  
    preOrder(T);
    Search(T,'C');
    cout << "\n删除"<< 'C'<< "后的先根序列为:";
    preOrder(T);
    cout << "\n----------------------------------" << endl;
    return 0;
}