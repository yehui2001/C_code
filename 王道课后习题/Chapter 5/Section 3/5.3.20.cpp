#include<iostream>
using namespace std;

typedef char ElemType;

typedef struct node{
    char data;
    struct node *left, *right;
}BTree;

BTree  *Create(BTree *T){
    char data;
    cout << "data  = " << endl;
    cin >> data;
    if(data!='#'){
        T = new BTree;
        T->data = data;
        T->left = NULL;
        T->right = NULL;
        T->left = Create(T->left);
        T->right = Create(T->right);
    }
    return T;
}

/*
    算法思想:
        1.采用中序遍历获得中缀表达式，因为运算符是双目运算符，而其左右孩子为操作数，故采用中序遍历
        2.在根结点和叶子结点处无法加括号
        3.中序遍历过程中，在输出左结点前加括号，在输出右结点后加括号

*/

void PutInExp(BTree *T,int deep){
    if(T==NULL)
        return;
    if(!T->left && !T->right)               //叶子结点不添加括号
        cout << T->data;
    else{                                   //根结点deep为1
        if(deep>1)  cout << "(";            //非根结点，添加左括号
        PutInExp(T->left,deep+1);
        cout << T->data;
        PutInExp(T->right,deep+1);
        if(deep>1)  cout << ")";
    }
}

//Input:AB##CD### ABD#M###CF##G##
int main(){
    BTree *T;
    cout << "----------------------------------" << endl;
    T = Create(T);
    cout << "中缀表达式：" << endl;
    PutInExp(T,1);
    return 0;
} 