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


int Width(BiTree &T){
    if(!T)
        return 0;
    int rear = 0,front = 0;                   //rear指向队尾元素下一个位置，front指向队头元素
    int lastNum = 0,curNum = 0;                //lastNum用来记录上一层入队的结点个数，curNum用来记录本层待出队的结点个数
    int width = 0;          
    BiTree Q[MaxSize];                        //定义一个指针队列
    Q[rear++] = T;                            //根结点入队
    lastNum++;
    width++;
    BiTNode *p;
    while(front < rear){
        while(lastNum--){
            p = Q[front++];                   //队首元素出队          
            if(p->lchild!=NULL&&p!=NULL){     //队列中的空结点没有左孩子，要排除
                Q[rear++] = p->lchild;
                curNum++;                     //本层入队的结点++
            }
            if(p->rchild!=NULL&&p!=NULL){
                Q[rear++] = p->rchild;
                curNum++;
            }
        }
        curNum>width? width=curNum:NULL;       //当前层的宽度
        lastNum = curNum;                      //继续执行
        curNum = 0;
    }
    return width;
}

//ABD#M###CF##G##
int main(){
    BiTree T;
    printf("----------------------------------\n");
    printf("请输入带有#的扩充二叉树先根遍历序列:");//例如AB##CD###
    Create_tree(T);
    cout << "二叉树宽度为:" << Width(T)<< endl;
    return 0;
} 