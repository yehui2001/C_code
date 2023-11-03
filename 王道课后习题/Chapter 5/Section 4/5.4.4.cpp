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
    若结点没有孩子(fch==NULL),则它必是叶子
*/

int leaves(Tree t){
    if(t==NULL)
        return 0;                   //树空返回0
    if(t->fch==NULL)                //若结点无孩子，该点必是叶子
        return 1+leaves(t->nsib);   //返回其兄弟子树的叶结点数
    else 
        return leaves(t->fch) + leaves(t->nsib);
}



int main(){
    Tree t;
    cout << "按照树的先根序列输入：" << endl;
    Create_tree(t);
    cout << "树的先根遍历序列:" << endl;
    PreOrder(t);
    cout << "叶子结点数为:" << leaves(t) << endl;
    return 0;
}