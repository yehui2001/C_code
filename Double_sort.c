#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void Create_array(int N,int *arr){
    int i;
    for(i = 0;i < N; i++){
        arr[i] = i+1;
    }
}

//创建升序函数
//此处采用冒泡排序，每一趟将最大值移动到末端
void A_order(int *arr,int q,int N){
    int temp,i,j,k = 0;
    for(i = q - 1; i < N - 1; i++){
        for(j = q - 1; j < N-1-k; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
            k++;
        }
    } 
} 

//创建降序函数
void D_order(int *arr,int q){
    int temp,i,j;
    for(i = 0; i < q; i++){
        for(j = 0; j < q-1-i; j++){
            if(arr[j] < arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Print_arr(int *arr,int N){

    int i;
    for(i = 0;i < N; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void Sort_Array(int *op,int* arr,int N,int M){
    int p,q,j;
    for(j = 0; j< 2*M;j = j + 2){
        p = op[j];
        q = op[j+1];
        if(p == 1){
            A_order(arr,q,N);
            //Print_arr(arr,N);
        }
        if(p == 0){
            D_order(arr,q);
            //Print_arr(arr,N);
        }
        if( p!=0 && p!=1){
            printf("出错,请输入正确的操作数");
        }
    }
    Print_arr(arr,N);
}


int main(){
    int N,M,i;
    //printf("请输入创建序列的长度跟操作次数:\n");
    scanf("%d %d",&N,&M);
    int arr[N],op[2*M];

    Create_array(N,arr);
    //printf("原序列:\n");
    //Print_arr(arr,N);


    //printf("输入具体的操作类型跟操作长度:\n");
    for(i = 0; i < 2*M; i++){
         scanf("%d",&op[i]);
    }

    //printf("各步骤:\n");
    Sort_Array(op,arr,N,M);


    return 0;
}