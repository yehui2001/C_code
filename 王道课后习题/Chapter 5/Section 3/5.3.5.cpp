#include<iostream>
using namespace std;
#define MaxSize 20

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

int Depth_NonRecur(BiTree &T){
    if(!T)
        return 0;
    int rear = 0,front = 0;             //rear指向队尾元素下一个位置，front指向队头元素
    int last = 0,level = 0;             //last用来指向当前层最右结点，level指向当前深度
    BiTree Q[MaxSize];                  //定义一个指针队列
    Q[rear++] = T;                      //根结点入队
    BiTNode *p;
    while(front < rear){
        p = Q[front++];                  
        if(p->lchild!=NULL&&p!=NULL)     //队列中的空结点没有左孩子，要排除
            Q[rear++] = p->lchild;
        if(p->rchild!=NULL&&p!=NULL)
            Q[rear++] = p->rchild;
        if(front-1==last){               //若刚刚处理的根结点是该层的最右结点，则认为处理了一层结点
            level++;                     //层数++
            last = rear-1;               //last指向下层，注意此时的rear恰好指向下一层最右结点
        }
    }
    return level;
}

int main(){
    BiTree T;
    printf("----------------------------------\n");
    printf("请输入带有#的扩充二叉树先根遍历序列:");//例如AB##CD###
    Create_tree(T);
    cout << "非递归计算的二叉树高度为:" << Depth_NonRecur(T)<< endl;
    return 0;
} 