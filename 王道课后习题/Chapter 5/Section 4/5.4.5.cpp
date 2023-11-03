#include<iostream>
using namespace std;
typedef char ElemType;

typedef struct node{
    ElemType data;     //数据域
    node *fch,*nsib;    // 孩子与兄弟域
} *Tree;

void Create_tree(Tree &t){
    ElemType c;
    cout << "请输入要插入当前结点的data值,0代表当前结点为NULL:" ;
    cin >> c;                 	  
    if(c == '#'){                   
        t = NULL;                   
        return;                   
    }		
    else{
        t = new node;
        t->data = c;
        Create_tree(t->fch);
        Create_tree(t->nsib);
    }
}

void PreOrder(Tree t){
    if(t){
        PreOrder(t->fch);
        cout << "\t" << t->data;
        PreOrder(t->nsib);
    }
}

/*
    采用递归
    1.树为空，高度为零
    2.高度为第一孩子树的高度+1 和 兄弟子树高度 更大者
    3.非递归算法类似于求二叉树的非递归
*/

int Depth_tree(Tree t){
    int hc,hs;
    if(t==NULL)
        return 0;
    else{
        hc = Depth_tree(t->fch);
        hs = Depth_tree(t->nsib);
        return hc+1>hs?hc+1:hs;
    }
}



int main(){
    Tree t;
    cout << "按照树的先根序列输入：" << endl;
    Create_tree(t);
    cout << "树的先根遍历序列:" << endl;
    PreOrder(t);
    cout << "树的深度为:" << Depth_tree(t) << endl;
    return 0;
}