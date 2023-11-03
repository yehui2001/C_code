#include<iostream>
using namespace std;

typedef char ElemType;

typedef struct node{
    ElemType data;     //数据域
    node *fch,*nsib;    // 孩子与兄弟域
} *Tree;

void Init(node *&pointer,char *level,int n ){
    for(int i = 0; i < n; i++){
        pointer[i]->data = level[i];
        pointer[i]->fch = pointer[i]->nsib = NULL; 
    }
}

void CreateCSTree_degree(char *level,int *degree,node *&pointer,int n){
    Init(pointer,level,n);
    int k = 0;
    for(int i = 0; i < n; i++){
        if(degree[i]){      //有孩子结点
            k++;                //选取孩子结点
            pointer[i]->fch = pointer[k];//链接
            for(i = 0; i < degree[i]-1; i++){   //将剩余兄弟结点链接到pointer[k]右子树
                k++;
                pointer[k-1]->nsib = pointer[k];
            }
        }
    }
}


int main(){
    char level[] = {'A','B','E','G','D','F'};
    int degree[] = {3,2,0,0,0,0};
    node *pointer = new node[6];
    for(int i = 0; i < 6; i++){
        pointer[i] =  new node;     //分配内存  
    }
    return 0;
}