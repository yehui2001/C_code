#include<iostream>
using namespace std;

int num = 0;
typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

//访问该结点，并打印该值
void visit(BiTree T){
    if(T!=NULL)
        if(T->lchild&&T->rchild)
            num++;
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
    char c;
    cin >> c;                 //输入的c序列和对应Create函数递归顺序应该与对应遍历序列一致
    if(c =='#')                    
        T = NULL;                   
    else{
        T = new BiTNode;
        T->data = c;
        Create_tree(T->lchild);
        Create_tree(T->rchild);
    }
}

//Algorithm thinking:每遍历到一个结点，查看其左右子树，看是否存在，若均存在，则num++;
int figure_Double(BiTree T){
    preOrder(T);
    return num;
}

//The answer: using the recurion function
int DsonNodes(BiTree T){
    if(T==NULL)
        return 0;
    else if(T->lchild&&T->rchild != NULL)
        return DsonNodes(T->lchild) + DsonNodes(T->rchild) + 1;
    else
        return DsonNodes(T->lchild) + DsonNodes(T->rchild);
}


//Input:AB##CD###  ABD##E##C## 
int main(){
    BiTree T;
    cout << "----------------------------------" << endl;
    cout << "请输入带有#的扩充二叉树先根遍历序列:" << endl;             //例如AB##CD###
    Create_tree(T);
    cout << figure_Double(T) << endl;
    cout << DsonNodes(T) << endl;
    return 0;
} 