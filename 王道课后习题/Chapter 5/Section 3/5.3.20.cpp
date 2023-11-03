#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

//访问该结点，并打印该值
void visit(BiTree T){
    if(T!=NULL)
    cout << T->data;
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
    cout << "请输入要插入当前结点的data值,0代表当前结点为NULL:" ;
    cin >> c;                 	  
    if(c =='#'){                   
        T = NULL;                   
        return;                   
    }		
    else{
        T = new BiTNode;
        T->data = c;
        Create_tree(T->lchild);
        Create_tree(T->rchild);
    }
}

//Input:AB##CD### ABD#M###CF##G##
int main(){
    BiTree T;
    cout << "----------------------------------" << endl;
    cout << "请输入带有#的扩充二叉树先根遍历序列:" << endl;
    Create_tree(T);
    return 0;
} 