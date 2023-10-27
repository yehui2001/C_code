//后序遍历二叉树的非递归算法
#include<iostream>
#include <stack>
using namespace std;

typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

typedef struct SNode
{
    struct SNode *next;
    struct BiTNode *BN;
}*LinkStack;

//初始化链栈
LinkStack Init_Stack(LinkStack &S){
    S = (SNode *)malloc(sizeof(SNode));
    S = NULL;
    return S;
}

//进栈
bool Push(LinkStack &S,BiTNode *&T){
    SNode *s;
    s = (SNode *)malloc(sizeof(SNode));
    s->BN = T;                     
    s->next = S;                   //让新结点成为首结点
    S = s;                         //令新插入的结点始终是头节点
    return true;
}

//出栈
bool Pop(LinkStack &S,BiTNode *&T){
    if(S==NULL){
       return false; 
    }
    SNode *p,*q;
    T = S->BN;
    p = S;
    q = S->next;
    S = q;
    free(p);
    return true;
}

//取栈顶元素
BiTNode *GetTop(LinkStack &S,BiTNode *&T){
    //函数中已经判断S!=NULL了
    T = S->BN;
    return T;
}

//判断栈空
bool isEmpty(LinkStack &S){
    return (S==NULL);
}

//递归建树  以先序遍历序列为例
void Create_tree(BiTree &T){
    char c;
    scanf("%c",&c);                 
    if(c =='#')                    
        T = NULL;                   
    else{
        T = (BiTNode*)malloc(sizeof(BiTNode));
        T->data = c;
        Create_tree(T->lchild);
        Create_tree(T->rchild);
    }
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

//后序遍历非递归算法
//算法思想：借助辅助栈。①沿着根的左孩子，依次入栈，直到左孩子为空； ②读取栈顶元素，如栈顶元素有右孩子且未被访问过，则转向右孩子，
// 按照①再将结点依次入栈；否则，将栈顶元素出栈，并访问。


bool Find_ancestor(BiTree T,LinkStack &S,ElemType x){
    BiTNode *p = T;
    BiTNode *r = NULL;                          //r为临时指针，用于判断右孩子是否被访问过
    while(p||!isEmpty(S)){
        if(p){
            Push(S,p);
            p = p->lchild;
        }
        else{
            GetTop(S,p);          //取S的栈顶元素，进行判断讨论(注意此步骤是必要的，需要更新p的值，因为之前p的值为NULL)
            if(p->rchild!=NULL && p->rchild!=r){ //若栈顶元素有右孩子且未访问过，则转向其右子树继续进行
                p = p->rchild;
            }
            else{
                Pop(S,p);
                if(p->data==x)   //若弹出元素值为x，则停止程序，此时栈内元素均为x的祖先结点
                    return true;    
                r = p;
                p = NULL;
            }
        }
    }
    return false;
}

bool Contain(LinkStack s,BiTNode *&r){
    LinkStack q = s;
    BiTNode *p;
    while(q!=NULL){
        GetTop(q,p);
        if(p->data==r->data)
            return true;
        q = q->next;
    }
    return false;
}

//Alg thinking: By using two Linkstack to store the ancestor BiTNodes,and using a function to match the common Node
bool ANCESTOR(BiTree t,ElemType p,ElemType q,BiTNode *&r){
    LinkStack s1,s2;
    Init_Stack(s1);
    Init_Stack(s2);
    Find_ancestor(t,s1,p);
    Find_ancestor(t,s2,q);
    while(!isEmpty(s1)){
        GetTop(s1,r);
        if(Contain(s2,r)){
            cout << "最近祖先是" << r->data << endl;
            return true;
            break;
        }
        Pop(s1,r);
    }
    return false;
}  

//Input:ABD#M###CF##G##
int main(){
    BiTree T;
    BiTNode *r;
    ElemType x = 'D';
    printf("----------------------------------\n");
    printf("请输入带有#的扩充二叉树先根遍历序列:");//例如AB##CD###
    Create_tree(T);
    preOrder(T);
    cout << endl;
    if(ANCESTOR(T,'E','G',r))   cout << "找到祖先结点" << endl;
    else cout << "未找到" << endl;
    printf("\n----------------------------------\n");
    return 0;
}