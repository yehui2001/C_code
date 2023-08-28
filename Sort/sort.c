#include<stdio.h>
#include<stdlib.h>
#define maxsize 10

//直接插入排序
void InsertSort(int A[]){                           //数组传参时，实际上传的是地址
    int temp,i,j;
    for(i = 1; i < maxsize; i++){
        if(A[i]<A[i-1]){
            temp = A[i];                            //保留当前元素
            for(j = i; A[j-1]>temp && j>0; j--){    //寻找当前元素在已排序序列中的位置，j>0，保证找到序列头部的时候停止，认为当前元素是已排序序列中的最小元素
                A[j] = A[j-1];                      //若前一个元素的值大于当前元素，后移，将前面的元素后移                 
            }
            A[j] = temp;                            //复制到对应位置j处
        }
    }
}

//带哨兵的直接插入排序
void InsertSort_Sentry(int A[]){
    int i,j;
    for(i = 2; i < maxsize; i++){
        if(A[i]<A[i-1]){
                A[0] = A[i];                         //存放当前元素;
            for(j = i; A[j-1]>A[0]; j--){            //无需判断j>0,因为当j=1时，A[j-1] = A[0]不大于A[0]自动跳出循环
                A[j] = A[j-1];
            }
            A[j] = A[0];
        }
    }
}

//折半插入排序
void Half_InsertSort(int A[]){
    int i,j,low,mid,high,temp;
    for(i = 1; i < maxsize; i++){
        temp = A[i];
        low = 0;
        high = i-1;
        while(low<=high){                       //循环结束时找到A[i] 元素在已排序序列中的位置high               
            mid = (low+high)/2;                 //取中间点，向下取整
            if(A[mid]>temp)
                high = mid - 1;                 //查找左半子表
            else                                //若出现A[mid] = temp;则继续查找右半子表，保证其稳定性
                low = mid + 1;                  //查找右半子表
        }
        for(j = i; j>low;j--){
            A[j] = A[j-1];
        }
        A[low] = temp;
    }
}

int Swap(int a,int b){
    return a>b?a:b;
}

void Print(int A[]){
    for(int i = 0;i < maxsize;i++){
        printf("%d\t",A[i]);
    }
    printf("\n");
}



int main(){
    int num[maxsize];
    //输入序列
    printf("请输入序列:");
    for(int i=0;i<maxsize;i++){
        scanf("%d",&num[i]);
    }

    printf("原序列:\n");
    Print(num);
    //InsertSort(num);
    //printf("直接插入排序:\n");
    //Print(num);
    Half_InsertSort(num);
    printf("折半插入排序:\n");
    Print(num);
    return 0;
}