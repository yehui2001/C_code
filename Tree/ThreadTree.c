#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild,*rchild;      //左右孩子指针
    int ltag,rtag;                          //左右线索标志，用以表示左右孩子指针是指向左（右）孩子还是前驱（后继）
} * ThreadTree;
ThreadNode *pre = NULL;

//访问该结点，并打印该值                        pre指向当前访问结点的前驱
void visit(ThreadNode *q){
    if(q->lchild==NULL){                    
        q->lchild = pre;                    //左孩子指针指向pre指针
        q->ltag = 1;                        //标记为线索指针
    }
    if(pre!=NULL&&pre->rchild==NULL){       //处理前驱结点的右孩子指针，若为空，指向当前结点q（也就是说q是pre的后继结点）
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;                                //pre指针向后访问
    //printf("%c",T->data);
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

//先序线索二叉树的构造
void PreThread(ThreadTree T){
    if(T!=NULL){                     //递归，线索化二叉树
        visit(T);                    //访问根结点
        if(T->ltag==0)               //若lchild不是线索前驱        防止重复访问，陷入循环
            PreThread(T->lchild);    //先序遍历左子树  
        if(T->rtag==0)               //
        PreThread(T->rchild);        //先序遍历右子树
    }
}
/*
关于需要判断ltag ==0的解释
：因为先根序列是先访问根结点，然后访问左孩子。
1.我们先访问根结点，可以注意到visit函数中，若左孩子指针为空，会将该结点的左孩子指针指向前驱结点。
注意到此时的左孩子已经不为空（指向前驱结点
2.然后我们继续访问左孩子，若我们不加判断，我们就好继续访问已经线索化后的左孩子。

关于rtag ==0的判断解释
假设我们有以下二叉树
        A
      /  \
     B   C
        /
       D
我们在运行D结点的所有函数后，递归到PreThread(C->rchild)
可以了解到，我们在访问D时，建立起了 C->rchild = D;
若不加判断，PreThread(C->rchild)会继续访问D

*/
void Create_PreThread(ThreadTree T){
    if(T!=NULL){
        PreThread(T);
        if(pre->rchild==NULL)       //处理遍历的最后一个结点
            pre->rtag = 1;
    }
}

//后序线索二叉树的构造
//不会出现转圈问题，因为最后处理的是根结点，不会再次访问处理过的左右孩子
void PostThread(ThreadTree T){
    if(T!=NULL){                     //递归，线索化二叉树
        PostThread(T->lchild);       //先序遍历左子树  
        PostThread(T->rchild);       //先序遍历右子树
        visit(T);
    }
}

void Create_PostThread(ThreadTree T){
    if(T!=NULL){
        PostThread(T);
        if(pre->rchild==NULL)       //处理遍历的最后一个结点
            pre->rtag = 1;
    }
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

//找到以p为根的子树中，最后一个被中序遍历的结点
ThreadNode *LastNode_IN(ThreadNode *p){
    //循环找到最右下结点(不一定是叶子结点)
    while(p->rtag==0)//若p的左子树只有一个结点，其rtag不等于0，则不进入循环，直接返回左结点           
        p=p->rchild;
    return p;
}

//在中序线索二叉树中找到p的中序前驱
ThreadNode *PreNode_IN (ThreadNode *p){
    //找左子树中最右下的结点
    if(p->ltag==0)
        return LastNode_IN(p->lchild);
    else
        return p->lchild;           //ltag==1直接返回线索前驱
}


//访问该结点，并打印其值
void Visit(ThreadNode *p){
    if(p!=NULL)
        printf("%c\t",p->data);
}

//对中序线索二叉树进行中序遍历（利用线索实现的非递归调用）
void Inorder(ThreadNode *T){
    for(ThreadNode *p = FirstNode_IN(T);p!=NULL;p=NextNode_IN(p))
        Visit(p);
    printf("\n");
}

//对中序线索二叉树进行逆向中序遍历（利用线索实现的非递归调用）
void RevInorder(ThreadNode *T){
    for(ThreadNode *p=LastNode_IN(T);p!=NULL;p=PreNode_IN(p))
        Visit(p);
}


//在先序线索二叉树中找p的先序后继
ThreadNode *NextNode_Pre(ThreadNode *p){
    if(p->rtag==0){             //有左孩子
        if(p->lchild!=NULL){    //左子树不为空
            return p->lchild;   //第一个访问的结点为左子树的根结点
        }
        else                    //只有右子树
            return p->rchild;   //第一个访问的结点为右子树的根结点
    }
    else
        return p->rchild;
}

//在先序线索二叉树中进行先序遍历
void Preorder(ThreadNode *T){
    for(ThreadNode *p=T;p!=NULL;p=NextNode_Pre(p))
        Visit(p);
}

//如果p->ltag==0，即有左子树，也就是没有左线索指针
//无法知道指定结点的先序前驱，因为访问次序为根左右，我们无法往回找
//可以用三叉链表解决

//在后序线索二叉树中找p的后序前驱
ThreadNode *PreNode_Post(ThreadNode *p){
    if(p->ltag==0){                         //有左孩子
        if(p->rchild!=NULL&&p->rtag==0)     //右子树不为空,且未被线索化
            return p->rchild;               //最后一个访问的结点为右子树的根结点
        else                                //只有左子树
            return p->lchild;               //最后一个访问的结点为左子树的根结点
    }
    else
        return p->lchild;
}

//在后序线索二叉树中进行后序遍历
void Postorder(ThreadNode *T){
    for(ThreadNode *p=T;p!=NULL;p=PreNode_Post(p))
        Visit(p);
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
        T->ltag = 0;        //默认指向左右孩子
        T->rtag = 0;        //都没有线索化
        Create_tree(T->lchild);
        Create_tree(T->rchild);
    }
}

int main(){
    ThreadTree T;
    printf("输入先序序列建树:");
    Create_tree(T);
    //Create_PreThread(T);
    //Create_InThread(T);
    Create_PostThread(T);
    //Preorder(T);
    //Inorder(T);                 //中序遍历 中序线索二叉树
    //RevInorder(T);
    Postorder(T);
    return 0;
}