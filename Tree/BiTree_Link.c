//该程序用于实现链式二叉树及其基本操作
#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

struct LinkNode{
    BiTNode *Elem;
    struct LinkNode *next;
};

typedef struct{
    struct LinkNode *front,*rear;
}LinkQueue;

//初始化队列
void Init_Queue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));//建立头节点
    Q.front->next = NULL;                                  //初始为空
}

//队列判空
bool Empty_Queue(LinkQueue &Q){
    if(Q.front==Q.rear)
        return true;
    return false;
}

//入队
bool In_Queue(LinkQueue &Q,BiTree &q){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->Elem = q;
    s->next = NULL;             //队尾指向NULL
    Q.rear->next = s;           //插入到队尾
    Q.rear = s;                 //重新定义队尾
    //printf("%c入队\n",x);
    return true;
}

//出队
bool Out_Queue(LinkQueue &Q,BiTree &q){
    if(Empty_Queue(Q)||q==NULL){
        return false;
    }
    LinkNode *p = Q.front->next;//注意此链表是带头节点的，p指向第一个结点
    if(p==NULL)
        return false;
    q = p->Elem;
    Q.front->next = p->next;     //指向下一个结点
    if(Q.rear==p)               //若原队列中只有一个元素，删除后队空
        Q.rear = Q.front;
    free(p);
    //printf("%c出队\n",x);
    return true;
}

//访问该结点，并打印该值
void visit(BiTree T){
    if(T!=NULL)
    printf("%c",T->data);
}

//前序遍历
void preOrder(BiTree T){
    if(T!=NULL){
        visit(T);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

//中序遍历
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

//后序遍历
void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

//层序遍历          需要用到队列，父母结点出队后，让其孩子结点入队，保证了下层结点入队的顺序自左向右
void LevelOrder(BiTree T){
    BiTNode *p;
    LinkQueue Q;
    Init_Queue(Q);
    In_Queue(Q,T);
    while(!Empty_Queue(Q)){
        Out_Queue(Q,p);
        visit(p);
        if(p->lchild!=NULL)
            In_Queue(Q,p->lchild);
        if(p->rchild!=NULL)
            In_Queue(Q,p->rchild);
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

int max(int x,int y){
    return x>y ? x:y;
}

//求二叉树的深度
int Depth_tree(BiTree &T){
    return T==NULL ? 0:max(Depth_tree(T->lchild),Depth_tree(T->rchild))+1;
}

//求二叉树的总结点数
int Num_BiTNode(BiTree &T){
    return T==NULL ? 0:Num_BiTNode(T->lchild)+Num_BiTNode(T->rchild)+1;
} 


int main(){
    BiTree T;
    printf("----------------------------------\n");
    printf("请输入带有#的扩充二叉树先根遍历序列:");//例如AB##CD###
    Create_tree(T);
    printf("二叉树的深度为:%d\n",Depth_tree(T));
    printf("二叉树的结点数为:%d\n",Num_BiTNode(T));
    printf("\n先序遍历序列:");
    preOrder(T);
    printf("\n中序遍历序列:");
    InOrder(T);
    printf("\n后序遍历序列:");
    PostOrder(T);
    printf("\n层序遍历序列:");
    LevelOrder(T);
    printf("\n----------------------------------\n");
    return 0;
} 