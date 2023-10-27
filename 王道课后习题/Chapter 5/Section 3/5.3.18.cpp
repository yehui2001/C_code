#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild,*rchild;      //左右孩子指针
    int ltag,rtag;                          //左右线索标志，用以表示左右孩子指针是指向左（右）孩子还是前驱（后继) 0代表有孩子指针，1代表是线索指针
} * ThreadTree;
ThreadNode *pre = NULL;
ThreadNode *xNode;
ElemType x = 'C';

//访问该结点，并打印该值                        pre指向当前访问结点的前驱
void visit(ThreadNode *q){
    if(q->lchild==NULL){                    //若无左孩子，则令其成为左线索指针          
        q->lchild = pre;                    //左孩子指针指向pre指针
        q->ltag = 1;                        //标记为线索指针
    }
    if(pre!=NULL&&pre->rchild==NULL){       //处理前驱结点的右孩子指针，若为空，则令其指向当前结点q（也就是说q是pre的后继结点）
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;                                //pre指针向后访问
}

//中序线索二叉树的构造
void InThread(ThreadTree T){
    if(T!=NULL){                    //递归，线索化二叉树
        InThread(T->lchild);        //中序遍历左子树      
        visit(T);                   //访问根结点
        InThread(T->rchild);        //中序遍历右子树
    }
}

void Create_InThread(ThreadTree T){
    if(T!=NULL){
        InThread(T);
        if(pre->rchild==NULL)       //处理遍历的最后一个结点
            pre->rtag = 1;
    }
}

//访问该结点，并打印其值
void Visit(ThreadNode *p){
    if(p!=NULL)
        printf("%c\t",p->data);
}

//找到以p为根的子树中，第一个被中序遍历的结点
ThreadNode *FirstNode_IN(ThreadNode *p){
    //循环找到最左下结点(不一定是叶子结点)
    while(p->ltag==0)   p=p->lchild;
    return p;
}

//在中序线索二叉树中找p的中序后继
ThreadNode *NextNode_IN (ThreadNode *p){
    //找右子树中最左下的结点
    if(p->rtag==0)
        return FirstNode_IN(p->rchild);
    else
        return p->rchild;           //rtag==1直接返回线索后继
}

//对中序线索二叉树进行中序遍历（利用线索实现的非递归调用）
void Inorder(ThreadNode *T){
    for(ThreadNode *p = FirstNode_IN(T);p!=NULL;p=NextNode_IN(p))
        Visit(p);
    printf("\n");
}

//递归建树  以先序遍历序列为例
void Create_tree(ThreadTree &T){
    char c;
    scanf("%c",&c);
    if(c =='#')
        T = NULL;
    else{
        T = (ThreadNode*)malloc(sizeof(ThreadNode));
        T->data = c;
        if(c==x)
        xNode = T;
        T->ltag = 0;        //默认指向左右孩子
        T->rtag = 0;        //都没有线索化
        Create_tree(T->lchild);
        Create_tree(T->rchild);
    }
}



//从中序线索二叉树中找指定结点在后序中的前驱结点
ThreadNode *InPostPre(ThreadTree t,ThreadNode *&p){
    ThreadNode *q;
    if(p->rtag==0)
        q = p->rchild;
    else if(p->ltag==0)
        q = p->lchild;
    else if(p->lchild==NULL)            //既没有左孩子指针也没有左线索指针 <=> 中序序列中的第一个结点
        q = NULL;                       //无前驱结点
    else{
        while(p->lchild && p->ltag==1)  //若只有左线索指针，则一直向上查找其祖先,直到有左孩子指针，或者左孩子为空为止
            p = p->lchild;
        if(p->ltag==0)                  //有左孩子
            q = p->lchild;
        else                            //左孩子为空
            q = NULL;
    }
    return q;
}

int main(){
    ThreadTree T;
    printf("输入先序序列建树:");
    Create_tree(T);
    Create_InThread(T);
    Inorder(T);                 //中序遍历 中序线索二叉树
    cout << x << "在后序序列中的前驱结点为:"<< InPostPre(T,xNode)->data << endl;
    return 0;
}