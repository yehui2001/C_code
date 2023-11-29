//基于快速排序的线性时间选择
#include<iostream>
#include <cstdlib>          //随机数
using namespace std;

//随机数    产生 [a,b] 范围内到随机数 
int Rand(){
    int a = 1,b = 8;
    srand((unsigned)time(NULL));        //添加当前时间为随机数种子，不加这行就产生伪随机数
    return a + rand()%(b-a+1);
}


//随机点的快速排序
int RandomizedSelect(int a[],int p,int r){
    srand((unsigned)time(0));
    int q = p + rand()%(r-p+1);           //产生[p,r]的随机数

    int temp = a[q];                    //把产生的随机基准元素值放到表头
    a[q] = a[p];
    a[p] = temp;                           

    while(p < r){                       //找到temp的下标
    while(a[r] >= temp && p < r)        
        r--;
    a[p] = a[r];
    while(a[p] <= temp && p < r)       
        p++;
    a[r] = a[p];
    }
    a[p] = temp;
    return p;
}

int select(int a[],int p,int r,int k){   //p为初始下标，r为结束下标
    if(p==r)    return a[p];             //递归出口
    int i = RandomizedSelect(a,p,r);
    int j = i-p+1;                       //注意此处k要与i-p+1比较，而不是直接与i比较;
    if(k>j) return select(a,i+1,r,k-j);  //若k大于i之前值的个数，则说明k不在前半部分，
    else return select(a,p,i,k);         //若k小于i之前值的个数，说明第k个值在前半部分
}


int main(){

    int k = 8;
    int a[10] = {3,1,5,8,2,9,18,14,4,6};
    cout<< "第" << k << "个数是:"<< select(a,0,9,k) << endl;
    return 0;
}