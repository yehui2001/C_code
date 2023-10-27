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

BiTNode *head,*pre = NULL;
BiTNode *LeafNode_In(BiTree t){
    if(t){
        LeafNode_In(t->lchild);
        if(t->lchild==NULL && t->rchild==NULL){
            if(pre==NULL){          //处理第一个结点
                head = t;
                pre = t;
            }
            else{
                pre->rchild = t;
                pre = t;            //pre指针后移到叶子结点
            }
        }
        LeafNode_In(t->rchild);
        pre->rchild = NULL;         //处理最后一个结点
    }
    return head;
}

void Print(BiTree t){
    BiTNode *p = t;
    while(p!=NULL){
        cout << "\t" << p->data;
        p = p->rchild;
    }
}

//Input:AB##CD### ABD#M###CF##G##
int main(){
    BiTree T;
    cout << "----------------------------------" << endl;
    cout << "请输入带有#的扩充二叉树先根遍历序列:" << endl;             
    Create_tree(T);
    cout << "叶子结点值:";
    LeafNode_In(T);
    Print(head);
    cout << "\n----------------------------------" << endl;
    return 0;
} 