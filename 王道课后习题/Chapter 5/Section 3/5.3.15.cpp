#include<iostream>
using namespace std;
#define MaxSize 20

typedef char ElemType;
void PreToPost(ElemType pre[],int l1,int h1,ElemType post[],int l2,int h2){
    int half;   
    if(h1>=l1){                                             //当左子树的先序序列没有结点时退出
        post[h2] = pre[l1];                                 //先序中的第一个元素一定是后序的最后一个结点
        half = (h1-l1)/2;                                   //每次递归更新half值
        PreToPost(pre,l1+1,l1+half,post,l2,l2+half-1);      //转换左子树
        PreToPost(pre,l1+half+1,h1,post,l2+half,h2-1);      //转换右子树        
    }
}

int main(){
    ElemType pre[] = {'A','B','C','D','E','F'};
    ElemType post[MaxSize];
    PreToPost(pre,0,6,post,0,6);
    cout << "后序序列"<<endl;
    for(int i = 0; i <= 6; i++){
        cout << post[i];
    }
    cout << endl;
    return 0;
}