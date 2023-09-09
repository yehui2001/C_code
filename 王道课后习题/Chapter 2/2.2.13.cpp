#include<iostream>
using namespace std;

/*
    算法思想：空间换时间
    创建一下数组B[n] 用以存放1～n是否在序列中的标识符 1表示序列中有该元素
*/
void Find_Min_N(int A[],int n){
    int i;
    int *B = new int[n];
    memset(B,0,sizeof(int)*n);      //初始化函数
    for(i = 0; i < n; i++){
        if(A[i]>0&&A[i]<n)          //属于0～n范围，给予标识       
            B[A[i]-1] = 1;
    }
    for(i = 0; i < n; i++){
        if(!B[i])    break;         //遇到未访问过的正整数就跳出
    }
    cout << "最小正整数是" << i+1 <<endl;
}     

int main(){
    int A[] = {-5,-3,4,3,1};
    cout << sizeof(A)/sizeof(int) << endl;
    Find_Min_N(A,sizeof(A)/sizeof(int));
    return 0;
}