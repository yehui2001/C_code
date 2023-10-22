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

//递归建树  以先序遍历序列为例
void Create_tree(BiTree &T){
    char c;
    scanf("%c",&c);                 //输入的c序列和对应Create函数递归顺序应该与对应遍历序列一致
    if(c =='#')                    
        T = NULL;                   
    else{
        T = new BiTNode;
        T->data = c;
        Create_tree(T->lchild);
        Create_tree(T->rchild);
    }
}


BiTree PreInCreat(ElemType A[],ElemType B[],int l1,int h1,int l2,int h2){
    //l1,h1为先序的第一个和最后一个结点下标
    int i,llen,rlen;
    BiTree root;
    root = new BiTNode;                     //建立根结点
    if(!A[l1])  return root;
    root->data = A[l1];                     //先序中第一个结点为根结点
    for(i=l2; B[i]!=root->data; i++);       //找到根结点在中序中的位置
    llen = i-l2;                            //左子树长度
    rlen = h2-i;                            //右子树长度
    if(llen)                                //若左子树存在
        root->lchild = PreInCreat(A,B,l1+1,l1+llen,l2,i-1);//将范围缩小至查找左子树的根结点
    else
        root->lchild = NULL;                //若左子树长度为0，则左子树为空
    if(rlen)
        root->rchild = PreInCreat(A,B,h1-rlen+1,h1,h2-rlen+1,h2);
    else
        root->rchild = NULL;
    return root;
}



int main(){
    printf("----------------------------------\n");
    //Create_tree(T);
    char A[] = {' ','A','B','C','D','E','F','G','H','I'};
    char B[] = {' ','B','C','A','E','D','G','H','F','I'};
    BiTree p = PreInCreat(A,B,1,10,1,10);
    preOrder(p);
    return 0;
} 