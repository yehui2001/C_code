#include<iostream>
using namespace std;
#define MAX_SIZE 12

typedef struct{
    int sqBiTNode[MAX_SIZE];            //T中不存在的结点用-1表示
    int ElemNum;                        //实际占用的数组元素
} SqBiTree;

/*
    算法思想:
    1.若一个结点sqBiTNode[i]有左孩子，则其左孩子一定存放在sqBiTNode[2i+1]中，右孩子位于sqBiTNode[2i+2]
    2.若有双亲结点，则值保存在sqBiTNode[(i-1)/2]中
*/

bool JudgeInOrderBST(SqBiTree t,int k,int *max){    //初始k = 0
    if(k < t.ElemNum && t.sqBiTNode[k]!=-1){
        if(!JudgeInOrderBST(t,2*k+1,max))    return false;      //先遍历左子树
        if(t.sqBiTNode[k]<=*max)    return false;   //若当前结点值小于max,则返回错误
        *max = t.sqBiTNode[k];                      //再遍历根结点，更新max值
        if(!JudgeInOrderBST(t,2*k+2,max))   return false;   //再遍历右子树
    }
    return true;
}

void Init(SqBiTree &t){
    t.sqBiTNode[0] = 40;
    t.sqBiTNode[1] = 25;
    t.sqBiTNode[2] = 60;
    t.sqBiTNode[3] = -1;
    t.sqBiTNode[4] = 30;
    t.sqBiTNode[5] = -1;
    t.sqBiTNode[6] = 80;
    t.sqBiTNode[7] = -1;
    t.sqBiTNode[8] = -1;
    t.sqBiTNode[9] = 27;
    t.ElemNum = 10;
}



int main(){
    SqBiTree t;
    Init(t);
    int max = -1;
    if(JudgeInOrderBST(t,0,&max))
        cout << "是二叉搜索树" << endl;
    return 0;
}