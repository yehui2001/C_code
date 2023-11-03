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
    cout << "请输入要插入当前结点的data值,0代表当前结点为NULL:";
    cin >> c;                 	  
        if(c == '#'){                    
            T = NULL;
        }                 
        else{
            T = new BiTNode;
            T->data = c;
            Create_tree(T->lchild);
            Create_tree(T->rchild);
        }
}

bool Judge_Similarity(BiTree t1,BiTree t2){
    if(t1==NULL && t2==NULL)    //若两个都为空，则相似
        return true;
    if(t1==NULL || t2==NULL)    //若只有一个为空，注意此处已经筛选了t1和t2同时为空的情况（上一个if）
        return false;   
    else{             //两个都是根结点则继续
        if(Judge_Similarity(t1->lchild,t2->lchild) && Judge_Similarity(t1->rchild,t2->rchild))  //左右子树都满足，才算是相似
            return true;
        else
            return false;           //若至少有一对结点不满足，则返回false，由于是取并运算，故认定两树不相似
    }
}

//Input:AB##CD### ABD#M###CF##G##
int main(){
    BiTree t1,t2;
    cout << "----------------------------------" << endl;
    cout << "请输入第一颗带有#的扩充二叉树先根遍历序列:" << endl;
    Create_tree(t1);
    cout << "请输入第二颗带有#的扩充二叉树先根遍历序列:" << endl;
    Create_tree(t2);
    if(Judge_Similarity(t1,t2))
        cout << "相似 "<< endl;
    else
        cout << "不相似" << endl;
    return 0;
} 