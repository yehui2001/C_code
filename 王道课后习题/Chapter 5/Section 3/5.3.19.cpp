#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct BiTNode
{
    ElemType weight;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

//访问该结点，并打印该值
void visit(BiTree T){
    if(T!=NULL)
    cout << T->weight;
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

//递归建树  以先序遍历序列为例
void Create_tree(BiTree &T){
    ElemType c;
    cout << "请输入要插入当前结点的data值,0代表当前结点为NULL:";
    cin >> c;                 	  
        if(c == 0){                    
            T = NULL;
            //return;
        }                 
        else{
            T = new BiTNode;
            T->weight = c;
            Create_tree(T->lchild);
            Create_tree(T->rchild);
        }
}

/*
 * 基本思想：
 *      在先序遍历的基础上进行改编,
 *      设置一个变量，在前序遍历的时候，每遍历到一个点就记录到这一个点前面经过的所有的weight的和
 *      如果到了叶节点，就将这里的值加上WPL，最终输出WPL    注意WPL的定义
 */

int wpl_PreOrder(BiTree t,int depth){
    static int wpl = 0;
    if(t->lchild==NULL && t->rchild==NULL){
        wpl+=depth*t->weight;
    }
    if(t->lchild!=NULL)
        wpl_PreOrder(t->lchild,depth+1);            //要用+1，而不是++depth,若用++depth，会使在遍历右子树的时候，高度比正常大1
    if(t->rchild!=NULL)                             //非得要装逼，可以左子树++depth，右子树depth++
        wpl_PreOrder(t->rchild,depth+1);
    return wpl;
}

int WPL(BiTree t){
    return wpl_PreOrder(t,0);
}

//Input:
int main(){
    BiTree T;
    cout << "----------------------------------" << endl;
    cout << "请输入带有#的扩充二叉树先根遍历序列:" << endl;
    Create_tree(T);
    cout << "WPL=" << WPL(T) << endl;
    return 0;
} 